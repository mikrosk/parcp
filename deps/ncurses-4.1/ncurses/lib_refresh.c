
/***************************************************************************
*                            COPYRIGHT NOTICE                              *
****************************************************************************
*                ncurses is copyright (C) 1992-1995                        *
*                          Zeyd M. Ben-Halim                               *
*                          zmbenhal@netcom.com                             *
*                          Eric S. Raymond                                 *
*                          esr@snark.thyrsus.com                           *
*                                                                          *
*        Permission is hereby granted to reproduce and distribute ncurses  *
*        by any means and for any fee, whether alone or as part of a       *
*        larger distribution, in source or in binary form, PROVIDED        *
*        this notice is included with any such distribution, and is not    *
*        removed from any of its header files. Mention of ncurses in any   *
*        applications linked with it is highly appreciated.                *
*                                                                          *
*        ncurses comes AS IS with no warranty, implied or expressed.       *
*                                                                          *
***************************************************************************/



/*
 *	lib_refresh.c
 *
 *	The routines wredrawln(), wrefresh() and wnoutrefresh().
 *
 */

#include <curses.priv.h>

MODULE_ID("$Id: lib_refresh.c,v 1.14 1997/02/02 01:05:26 tom Exp $")

int wredrawln(WINDOW *win, int beg, int num)
{
	T((T_CALLED("wredrawln(%p,%d,%d)"), win, beg, num));
	touchline(win, beg, num);
	wrefresh(win);
	returnCode(OK);
}

int wrefresh(WINDOW *win)
{
int code;

	T((T_CALLED("wrefresh(%p)"), win));

	if (win == curscr) {
		curscr->_clear = TRUE;
		code = doupdate();
	} else if ((code = wnoutrefresh(win)) == OK) {
		if (win->_clear)
			newscr->_clear = TRUE;
		code = doupdate();
		/*
		 * Reset the clearok() flag in case it was set for the special
		 * case in hardscroll.c (if we don't reset it here, we'll get 2
		 * refreshes because the flag is copied from stdscr to newscr).
		 * Resetting the flag shouldn't do any harm, anyway.
		 */
		win->_clear = FALSE;
	}
	returnCode(code);
}

int wnoutrefresh(WINDOW *win)
{
short	i, j;
short	begx = win->_begx;
short	begy = win->_begy;
short	m, n;
bool	wide;

	T((T_CALLED("wnoutrefresh(%p)"), win));
#ifdef TRACE
	if (_nc_tracing & TRACE_UPDATE)
	    _tracedump("...win", win);
#endif /* TRACE */

	/*
	 * This function will break badly if we try to refresh a pad.
	 */
	if ((win == 0)
	 || (win->_flags & _ISPAD))
		returnCode(ERR);

	/*
	 * If 'newscr' has a different background than the window that we're
	 * trying to refresh, we'll have to copy the whole thing.
	 */
	if (win->_bkgd != newscr->_bkgd) {
		touchwin(win);
		newscr->_bkgd = win->_bkgd;
	}
	newscr->_attrs = win->_attrs;

	/* merge in change information from all subwindows of this window */
	wsyncdown(win);

	/*
	 * For pure efficiency, we'd want to transfer scrolling information
	 * from the window to newscr whenever the window is wide enough that
	 * its update will dominate the cost of the update for the horizontal
	 * band of newscr that it occupies.  Unfortunately, this threshold
	 * tends to be complex to estimate, and in any case scrolling the
	 * whole band and rewriting the parts outside win's image would look
	 * really ugly.  So.  What we do is consider the window "wide" if it
	 * either (a) occupies the whole width of newscr, or (b) occupies
	 * all but at most one column on either vertical edge of the screen
	 * (this caters to fussy people who put boxes around full-screen
	 * windows).  Note that changing this formula will not break any code,
	 * merely change the costs of various update cases.
	 */
	wide = (begx <= 1 && win->_maxx >= (newscr->_maxx - 1));

	win->_flags &= ~_HASMOVED;

	/*
	 * Microtweaking alert!  This double loop is one of the genuine
	 * hot spots in the code.  Even gcc doesn't seem to do enough
	 * common-subexpression chunking to make it really tense,
	 * so we'll force the issue.
	 */
	for (i = 0, m = begy + win->_yoffset;
	     i <= win->_maxy && m <= newscr->_maxy;
	     i++, m++) {
		register struct ldat	*nline = &newscr->_line[m];
		register struct ldat	*oline = &win->_line[i];

		if (oline->firstchar != _NOCHANGE) {
			int last = oline->lastchar;

			/* limit(j) */
			if (last > win->_maxx)
				last = win->_maxx;
			/* limit(n) */
			if (last > newscr->_maxx - begx)
				last = newscr->_maxx - begx;

			for (j = oline->firstchar, n = j + begx; j <= last; j++, n++) {
				if (oline->text[j] != nline->text[n]) {
					nline->text[n] = oline->text[j];

					if (nline->firstchar == _NOCHANGE)
						nline->firstchar = nline->lastchar = n;
					else if (n < nline->firstchar)
						nline->firstchar = n;
					else if (n > nline->lastchar)
						nline->lastchar = n;
				}
			}

		}

		if (wide) {
		    int	oind = oline->oldindex;

		    nline->oldindex = (oind == _NEWINDEX) ? _NEWINDEX : begy + oind + win->_yoffset;
		}

		oline->firstchar = oline->lastchar = _NOCHANGE;
		oline->oldindex = i;
	}

	if (win->_clear) {
		win->_clear = FALSE;
		newscr->_clear = TRUE;
	}

	if (! win->_leaveok) {
		newscr->_cury = win->_cury + win->_begy + win->_yoffset;
		newscr->_curx = win->_curx + win->_begx;
	}
#ifdef TRACE
	if (_nc_tracing & TRACE_UPDATE)
	    _tracedump("newscr", newscr);
#endif /* TRACE */
	returnCode(OK);
}
