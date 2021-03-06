------------------------------------------------------------------------------
--                                                                          --
--                       GNAT ncurses Binding Samples                       --
--                                                                          --
--                                 Sample                                   --
--                                                                          --
--                                 B O D Y                                  --
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
--  Version Control
--  $Revision: 1.5 $
------------------------------------------------------------------------------
with Text_IO;

with Ada.Characters.Latin_1; use Ada.Characters.Latin_1;
with Ada.Exceptions; use Ada.Exceptions;

with Terminal_Interface.Curses; use Terminal_Interface.Curses;
with Terminal_Interface.Curses.Panels; use Terminal_Interface.Curses.Panels;
with Terminal_Interface.Curses.Menus; use Terminal_Interface.Curses.Menus;
with Terminal_Interface.Curses.Menus.Menu_User_Data;
with Terminal_Interface.Curses.Menus.Item_User_Data;

with Sample.Manifest; use Sample.Manifest;
with Sample.Helpers; use Sample.Helpers;
with Sample.Function_Key_Setting; use Sample.Function_Key_Setting;
with Sample.Keyboard_Handler; use Sample.Keyboard_Handler;
with Sample.Header_Handler; use Sample.Header_Handler;
with Sample.Explanation; use Sample.Explanation;

with Sample.Menu_Demo.Handler;
with Sample.Curses_Demo;
with Sample.Form_Demo;
with Sample.Menu_Demo;
with Sample.Text_IO_Demo;

with GNAT.OS_Lib;

package body Sample is

   type User_Data is
      record
         Data : Integer;
      end record;
   type User_Access is access User_Data;

   package Ud is new
     Terminal_Interface.Curses.Menus.Menu_User_Data
     (User_Data, User_Access);

   package Id is new
     Terminal_Interface.Curses.Menus.Item_User_Data
     (User_Data, User_Access);

   procedure Whow is
      procedure Main_Menu;
      procedure Main_Menu
      is
         function My_Driver (M : Menu;
                             K : Key_Code;
                             Pan : Panel) return Boolean;

         package Mh is new Sample.Menu_Demo.Handler (My_Driver);

         I : constant Item_Array (1 .. 4) :=
           (New_Item ("Curses Core Demo"),
            New_Item ("Menu Demo"),
            New_Item ("Form Demo"),
            New_Item ("Text IO Demo"));

         M : Menu := New_Menu (I);

         D1, D2 : User_Access;
         I1, I2 : User_Access;

         function My_Driver (M : Menu;
                             K : Key_Code;
                             Pan : Panel) return Boolean
         is
            Idx : constant Positive := Get_Index (Current (M));
         begin
            if K in User_Key_Code'Range then
               if K = QUIT then
                  return True;
               elsif K = SELECT_ITEM then
                  if Idx in 1 .. 4 then
                     Hide (Pan);
                     Update_Panels;
                  end if;
                  case Idx is
                     when 1 => Sample.Curses_Demo.Demo;
                     when 2 => Sample.Menu_Demo.Demo;
                     when 3 => Sample.Form_Demo.Demo;
                     when 4 => Sample.Text_IO_Demo.Demo;
                     when others => null;
                  end case;
                  if Idx in 1 .. 4 then
                     Top (Pan);
                     Show (Pan);
                     Update_Panels;
                     Update_Screen;
                  end if;
               end if;
            end if;
            return False;
         end My_Driver;

      begin

         if Item_Count (M) /= I'Length then
            raise Constraint_Error;
         end if;

         D1 := new User_Data'(Data => 4711);
         Ud.Set_User_Data (M, D1);

         I1 := new User_Data'(Data => 1174);
         Id.Set_User_Data (I (1), I1);

         Set_Spacing (Men => M, Row => 2);

         Default_Labels;
         Notepad ("MAINPAD");

         Mh.Drive_Me (M, " Demo ");

         Ud.Get_User_Data (M, D2);
         pragma Assert (D1 = D2);
         pragma Assert (D1.Data = D2.Data);

         Id.Get_User_Data (I (1), I2);
         pragma Assert (I1 = I2);
         pragma Assert (I1.Data = I2.Data);

         Delete (M);
      end Main_Menu;

   begin
      Initialize (PC_Style_With_Index);
      Init_Header_Handler;
      Init_Screen;

      if Has_Colors then
         Start_Color;

         Init_Pair (Pair => Default_Colors,  Fore => Black,   Back => White);
         Init_Pair (Pair => Menu_Back_Color, Fore => Black,   Back => Cyan);
         Init_Pair (Pair => Menu_Fore_Color, Fore => Red,     Back => Cyan);
         Init_Pair (Pair => Menu_Grey_Color, Fore => White,   Back => Cyan);
         Init_Pair (Pair => Notepad_Color,   Fore => Black,   Back => Yellow);
         Init_Pair (Pair => Help_Color,      Fore => Blue,    Back => Cyan);
         Init_Pair (Pair => Form_Back_Color, Fore => Black,   Back => Cyan);
         Init_Pair (Pair => Form_Fore_Color, Fore => Red,     Back => Cyan);
         Init_Pair (Pair => Header_Color,    Fore => Black,   Back => Green);

         Set_Background (Ch => (Color => Default_Colors,
                                Attr  => Normal_Video,
                                Ch    => ' '));
         Set_Character_Attributes (Attr  => Normal_Video,
                                   Color => Default_Colors);
         Erase;

         Set_Soft_Label_Key_Attributes (Color => Header_Color);
         --  This propagates the attributes to the label window
         Clear_Soft_Label_Keys; Restore_Soft_Label_Keys;
      end if;

      Init_Keyboard_Handler;

      Set_Echo_Mode (FALSE);
      Set_Raw_Mode;
      Set_Meta_Mode;
      Set_KeyPad_Mode;

      --  Initialize the Function Key Environment
      --  We have some fixed key throughout this sample
      Main_Menu;
      End_Windows;

   exception
      when Event : others =>
         Terminal_Interface.Curses.End_Windows;
         Text_IO.Put ("Exception: ");
         Text_IO.Put (Exception_Name (Event));
         Text_IO.New_Line;
         GNAT.OS_Lib.OS_Exit (1);

   end Whow;

end Sample;
