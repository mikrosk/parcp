# $Id: mk-1st.awk,v 1.20 1997/05/05 21:28:17 tom Exp $
################################################################################
# Copyright 1996,1997 by Thomas E. Dickey <dickey@clark.net>                   #
# All Rights Reserved.                                                         #
#                                                                              #
# Permission to use, copy, modify, and distribute this software and its        #
# documentation for any purpose and without fee is hereby granted, provided    #
# that the above copyright notice appear in all copies and that both that      #
# copyright notice and this permission notice appear in supporting             #
# documentation, and that the name of the above listed copyright holder(s) not #
# be used in advertising or publicity pertaining to distribution of the        #
# software without specific, written prior permission. THE ABOVE LISTED        #
# COPYRIGHT HOLDER(S) DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,    #
# INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT #
# SHALL THE ABOVE LISTED COPYRIGHT HOLDER(S) BE LIABLE FOR ANY SPECIAL,        #
# INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM   #
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE   #
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR    #
# PERFORMANCE OF THIS SOFTWARE.                                                #
################################################################################
# Generate list of objects for a given model library
# Variables:
#	name (library name, e.g., "ncurses", "panel", "forms", "menus")
#	model (directory into which we compile, e.g., "obj")
#	suffix (e.g., "_g.a", for debug libraries)
#	MODEL (e.g., "DEBUG", uppercase; toupper is not portable)
#	DoLinks ("yes" or "no", flag to add symbolic links)
#	rmSoLocs ("yes" or "no", flag to add extra clean target)
#	overwrite ("yes" or "no", flag to add link to libcurses.a
#
# Notes:
#	CLIXs nawk does not like underscores in command-line variable names.
#	Mixed-case is ok.
#	HP/UX requires shared libraries to have executable permissions.
#
function symlink(src,dst) {
		if ( src != dst ) {
			printf "rm -f %s; ", dst
			printf "$(LN_S) %s %s; ", src, dst
		}
	}
function sharedlinks(directory) {
		if ( end_name != lib_name ) {
			printf "\tcd %s && (", directory
			abi_name = sprintf("%s.$(ABI_VERSION)", lib_name);
			symlink(end_name, abi_name);
			symlink(abi_name, lib_name);
			printf ")\n"
		}
	}
function removelinks() {
		if ( end_name != lib_name ) {
			printf "\trm -f ../lib/%s ../lib/%s\n", abi_name, end_name
		}
	}
function installed_name() {
		if ( DO_LINKS == "yes" ) {
			return sprintf("%s.$(REL_VERSION)", lib_name);
		} else {
			return lib_name;
		}
	}
BEGIN	{
		print  ""
		print  "# generated by mk-1st.awk"
		print  ""
		found = 0;
	}
	!/^#/ {
		if ( $2 == "lib" || $2 == "progs" )
		{
			if ( found == 0 )
			{
				printf "%s_OBJS =", MODEL
				if ( $2 == "lib" )
					found = 1
				else
					found = 2
			}
			printf " \\\n\t../%s/%s.o", model, $1
		}
	}
END	{
		print  ""
		if ( found != 0 )
		{
			printf "\n$(%s_OBJS) : %s\n", MODEL, depend
		}
		if ( found == 1 )
		{
			print  ""
			lib_name = sprintf("lib%s%s", name, suffix)
			if ( MODEL == "SHARED" )
			{
				if ( DoLinks == "yes" ) {
					end_name = sprintf("%s.$(REL_VERSION)", lib_name);
				} else {
					end_name = lib_name;
				}
				printf "../lib/%s : $(%s_OBJS)\n", lib_name, MODEL
				print  "\t@-rm -f $@"
				printf "\t$(MK_SHARED_LIB) $(%s_OBJS)\n", MODEL
				sharedlinks("../lib")
				print  ""
				if ( end_name != lib_name ) {
					printf "../lib/%s : ../lib/%s\n", end_name, lib_name
				}
				print  ""
				print  "install \\"
				print  "install.libs \\"
				printf "install.%s :: $(INSTALL_PREFIX)$(libdir) ../lib/%s\n", name, end_name
				printf "\t@echo installing ../lib/%s as $(INSTALL_PREFIX)$(libdir)/%s \n", lib_name, end_name
				printf "\t-rm -f $(INSTALL_PREFIX)$(libdir)/%s \n", end_name
				printf "\t$(INSTALL) ../lib/%s $(INSTALL_PREFIX)$(libdir)/%s \n", lib_name, end_name
				sharedlinks("$(INSTALL_PREFIX)$(libdir)")
				if ( overwrite == "yes" && name == "ncurses" )
				{
					ovr_name = sprintf("libcurses%s", suffix)
					printf "\t@echo linking %s to %s\n", ovr_name, lib_name
					printf "\t-rm -f $(INSTALL_PREFIX)$(libdir)/%s \n", ovr_name
					printf "\t(cd $(INSTALL_PREFIX)$(libdir) && $(LN_S) %s %s)\n", lib_name, ovr_name
				}
				printf "\t- ldconfig\n"
				if ( rmSoLocs == "yes" ) {
					print  ""
					print  "mostlyclean \\"
					print  "clean ::"
					printf "\t@-rm -f so_locations\n"
				}
			}
			else
			{
				end_name = lib_name;
				printf "../lib/%s : $(%s_OBJS)\n", lib_name, MODEL
				printf "\t$(AR) $(AR_OPTS) $@ $?\n"
				printf "\t$(RANLIB) $@\n"
				print  ""
				print  "install \\"
				print  "install.libs \\"
				printf "install.%s :: $(INSTALL_PREFIX)$(libdir) ../lib/%s\n", name, lib_name
				printf "\t@echo installing ../lib/%s as $(INSTALL_PREFIX)$(libdir)/%s \n", lib_name, lib_name
				printf "\t$(INSTALL_DATA) ../lib/%s $(INSTALL_PREFIX)$(libdir)/%s \n", lib_name, lib_name
				if ( overwrite == "yes" && lib_name == "libncurses.a" )
				{
					printf "\t@echo linking libcurses.a to libncurses.a \n"
					printf "\t-rm -f $(INSTALL_PREFIX)$(libdir)/libcurses.a \n"
					printf "\t(cd $(INSTALL_PREFIX)$(libdir) && $(LN_S) libncurses.a libcurses.a)\n"
				}
				printf "\t$(RANLIB) $(INSTALL_PREFIX)$(libdir)/%s\n", lib_name
			}
			print ""
			print "mostlyclean \\"
			print "clean ::"
			printf "\trm -f ../lib/%s\n", lib_name
			printf "\trm -f $(%s_OBJS)\n", MODEL
			removelinks();
		}
		else if ( found == 2 )
		{
			print ""
			print "mostlyclean \\"
			print "clean ::"
			printf "\trm -f $(%s_OBJS)\n", MODEL
		}
	}
