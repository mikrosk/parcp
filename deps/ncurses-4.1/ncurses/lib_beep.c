
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
 *	beep.c
 *
 *	Routines beep() and flash()
 *
 */

#include <curses.priv.h>
#include <term.h>	/* beep, flash */

MODULE_ID("$Id: lib_beep.c,v 1.3 1997/02/02 00:27:01 tom Exp $")

/*
 *	beep()
 *
 *	Sound the current terminal's audible bell if it has one.   If not,
 *	flash the screen if possible.
 *
 */

int beep(void)
{
	T((T_CALLED("beep()")));

	/* FIXME: should make sure that we are not in altchar mode */
	if (bell) {
		TPUTS_TRACE("bell");
		return(putp(bell));
	} else if (flash_screen) {
		TPUTS_TRACE("flash_screen");
		return(putp(flash_screen));
	}
	else
		returnCode(ERR);
}

/*
 *	flash()
 *
 *	Flash the current terminal's screen if possible.   If not,
 *	sound the audible bell if one exists.
 *
 */

int flash(void)
{
	T((T_CALLED("flash()")));

	/* FIXME: should make sure that we are not in altchar mode */
	if (flash_screen) {
		TPUTS_TRACE("flash_screen");
		returnCode(putp(flash_screen));
	} else if (bell) {
		TPUTS_TRACE("bell");
		returnCode(putp(bell));
	}
	else
		returnCode(ERR);
}
