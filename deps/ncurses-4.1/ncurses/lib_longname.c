
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
**	lib_longname.c
**
**	The routine longname().
**
*/

#include <curses.priv.h>

MODULE_ID("$Id: lib_longname.c,v 1.5 1996/12/21 14:24:06 tom Exp $")

char *
longname(void)
{
char	*ptr;

	T(("longname() called"));

	for (ptr = ttytype + strlen(ttytype); ptr > ttytype; ptr--)
		if (*ptr == '|')
			return(ptr + 1);

    return(ttytype);
}
