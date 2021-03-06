
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
**	lib_scanw.c
**
**	The routines scanw(), wscanw() and friends.
**
*/

#include <curses.priv.h>

MODULE_ID("$Id: lib_scanw.c,v 1.4 1997/02/08 14:45:51 tom Exp $")

#if !HAVE_VSSCANF
extern int vsscanf(const char *str, const char *format, ...);
#endif

int vwscanw(WINDOW *win, const char *fmt, va_list argp)
{
char buf[BUFSIZ];

	if (wgetstr(win, buf) == ERR)
	    return(ERR);

	return(vsscanf(buf, fmt, argp));
}

int scanw(const char *fmt, ...)
{
int code;
va_list ap;

	T(("scanw(\"%s\",...) called", fmt));

	va_start(ap, fmt);
	code = vwscanw(stdscr, fmt, ap);
	va_end(ap);
	return (code);
}

int wscanw(WINDOW *win, const char *fmt, ...)
{
int code;
va_list ap;

	T(("wscanw(%p,\"%s\",...) called", win, fmt));

	va_start(ap, fmt);
	code = vwscanw(win, fmt, ap);
	va_end(ap);
	return (code);
}

int mvscanw(int y, int x, const char *fmt, ...)
{
int code;
va_list ap;

	va_start(ap, fmt);
	code = (move(y, x) == OK) ? vwscanw(stdscr, fmt, ap) : ERR;
	va_end(ap);
	return (code);
}

int mvwscanw(WINDOW *win, int y, int x, const char *fmt, ...)
{
int code;
va_list ap;

	va_start(ap, fmt);
	code = (wmove(win, y, x) == OK) ? vwscanw(win, fmt, ap) : ERR;
	va_end(ap);
	return (code);
}
