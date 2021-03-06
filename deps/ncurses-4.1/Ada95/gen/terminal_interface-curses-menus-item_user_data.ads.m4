--  -*- ada -*-
define(`HTMLNAME',`terminal_interface-curses-menus-item_user_data_s.html')dnl
include(M4MACRO)dnl
------------------------------------------------------------------------------
--                                                                          --
--                           GNAT ncurses Binding                           --
--                                                                          --
--               Terminal_Interface.Curses.Menus.Item_User_Data             --
--                                                                          --
--                                 S P E C                                  --
--                                                                          --
--  Version 00.92                                                           --
--                                                                          --
--  The ncurses Ada95 binding is copyrighted 1996 by                        --
--  Juergen Pfeifer, Email: Juergen.Pfeifer@T-Online.de                     --
--                                                                          --
--  Permission is hereby granted to reproduce and distribute this           --
--  binding by any means and for any fee, whether alone or as part          --
--  of a larger distribution, in source or in binary form, PROVIDED         --
--  this notice is included with any such distribution, and is not          --
--  removed from any of its header files. Mention of ncurses and the        --
--  author of this binding in any applications linked with it is            --
--  highly appreciated.                                                     --
--                                                                          --
--  This binding comes AS IS with no warranty, implied or expressed.        --
------------------------------------------------------------------------------
--  Version Control:
--  $Revision: 1.2 $
------------------------------------------------------------------------------

generic
   type User is limited private;
   type User_Access is access User;
package Terminal_Interface.Curses.Menus.Item_User_Data is

   --  The binding uses the same user pointer for menu items
   --  as the low level C implementation. So you can safely
   --  read or write the user pointer also with the C routines
   --
   --  MANPAGE(`mitem_userptr.3x')

   --  ANCHOR(`set_item_userptr',`Set_User_Data')
   procedure Set_User_Data (Itm  : in Item;
                            Data : in User_Access);
   --  AKA
   pragma Convention (C, Set_User_Data);

   --  ANCHOR(`item_userptr',`Get_User_Data')
   procedure Get_User_Data (Itm  : in  Item;
                            Data : out User_Access);
   --  AKA
   pragma Convention (C, Get_User_Data);

end Terminal_Interface.Curses.Menus.Item_User_Data;
