CROSS = yes

ifeq ($(CROSS),yes)
prefix = m68k-atari-mint-
else
prefix =
endif

CC = $(prefix)gcc
AS = vasm #$(prefix)as
STRIP = $(prefix)strip -s
STACK = $(prefix)stack

DEBUG =
#DEBUG = -DDEBUG
#DEBUG = -DDEBUG -DLOWDEBUG
#DEBUG = -DDEBUG -DLOWDEBUG -DIODEBUG

FLAGS = $(EXT_FLAGS) -O2 -DATARI $(DEBUG) -Wall -fomit-frame-pointer -fno-strength-reduce
FLAGS030 = -m68020-40 $(FLAGS)

PARCLIENT =  parcp.c parcp.h cfgopts.h parcplow.h parcplow.c crc32.c parcommo.c parftpcl.c sort.c

ZAKL_OBJS = match.o cfgopts.o parcp68k.o global.o
ZAKL_OBJS030 = match030.o cfgopts030.o parcp68k.o global.o

OBJS = parcp.o $(ZAKL_OBJS)
OBJS030 = parcp030.o $(ZAKL_OBJS030)
SEROBJS = server_parcp.o $(ZAKL_OBJS)
SEROBJS030 = server_parcp030.o $(ZAKL_OBJS030)

SHELL_FLAGS = -DSHELL $(FLAGS)
SHELL_FLAGS030 = -DSHELL $(FLAGS030)
SHELL_OBJS = shell_parcp.o shell.o box.o menu.o viewer.o $(ZAKL_OBJS)
SHELL_OBJS030 = shell_parcp030.o shell030.o box030.o menu030.o viewer030.o $(ZAKL_OBJS030)

parshell : $(SHELL_OBJS)
	$(CC) $(SHELL_FLAGS) -o parcp $(SHELL_OBJS) -lpanel -lncurses
	$(STRIP) parcp
	$(STACK) --fix=64k parcp

parshell030 : $(SHELL_OBJS030)
	$(CC) $(SHELL_FLAGS030) -o parcp030 $(SHELL_OBJS030) -lpanel -lncurses
	$(STRIP) parcp030
	$(STACK) --fix=64k parcp030

parcp : $(OBJS)
	$(CC) $(FLAGS) -o parcp $(OBJS)
	$(STRIP) parcp
	$(STACK) --fix=64k parcp

parcp030 : $(OBJS030)
	$(CC) $(FLAGS030) -o parcp030 $(OBJS030)
	$(STRIP) parcp030
	$(STACK) --fix=64k parcp030

parserve : $(SEROBJS)
	$(CC) $(FLAGS) -o parserve $(SEROBJS)
	$(STRIP) parserve
	$(STACK) --fix=32k parserve

parserve030 : $(SEROBJS030)
	$(CC) $(FLAGS030) -o parser30 $(SEROBJS030)
	$(STRIP) parser30
	$(STACK) --fix=32k parser30

par_io : par_io.c
	$(CC) $(FLAGS) par_io.c -o par_io
	$(STRIP) par_io

par_in : parinout.c parcp.h
	$(CC) $(FLAGS) -DIN parinout.c -o par_in
	$(STRIP) par_in
	$(STACK) --fix=16k par_in

par_out : parinout.c parcp.h
	$(CC) $(FLAGS) -DOUT parinout.c -o par_out
	$(STRIP) par_out
	$(STACK) --fix=16k par_out

partest : partest.o $(ZAKL_OBJS)
	$(CC) $(FLAGS) -o partest partest.o $(ZAKL_OBJS)
	$(STRIP) partest
	$(STACK) --fix=64k partest

all : parshell parshell030 parserve parserve030 par_in

tgz : all
	mv parcp parcp.ttp
	mv parcp030 parcp030.ttp
	mv parserve parserve.tos
	mv parser30 parser30.tos
	mv par_in par_in.prg
	tar czvf parcp.tgz parcp.ttp parcp030.ttp parserve.tos parser30.tos par_in.prg
	rm parcp.ttp parcp030.ttp parserve.tos parser30.tos par_in.prg

clean :
	rm -f *.o parshell parshell030 parserve parserve030 par_in parcp.ttp parcp030.ttp parserve.tos parser30.tos par_in.prg parcp.tgz

###############################

parcp.o : $(PARCLIENT)
	$(CC) $(FLAGS) -c parcp.c

partest.o : partest.c $(PARCLIENT)
	$(CC) $(FLAGS) -c partest.c

shell_parcp.o : $(PARCLIENT)
	$(CC) $(SHELL_FLAGS) -c parcp.c -o shell_parcp.o

server_parcp.o : $(PARCLIENT)
	$(CC) -DPARCP_SERVER $(FLAGS) -c parcp.c -o server_parcp.o

shell.o : shell.c shell.h parcp.h cfgopts.h
	$(CC) $(SHELL_FLAGS) -c shell.c

box.o : box.c box.h shell.h
	$(CC) $(SHELL_FLAGS) -c box.c

menu.o : menu.c menu.h shell.h
	$(CC) $(SHELL_FLAGS) -c menu.c

viewer.o : viewer.c
	$(CC) $(SHELL_FLAGS) -c viewer.c

global.o : global.c global.h
	$(CC) $(SHELL_FLAGS) -c global.c

parcp68k.o : parcp68k.asm
	$(AS) -quiet -Faout -x parcp68k.asm -o parcp68k.o

match.o : match.c match.h
	$(CC) $(FLAGS) -c match.c

cfgopts.o : cfgopts.c cfgopts.h
	$(CC) $(FLAGS) -c cfgopts.c

parcp030.o : $(PARCLIENT)
	$(CC) $(FLAGS030) -c parcp.c -o parcp030.o
	
shell_parcp030.o : $(PARCLIENT)
	$(CC) $(SHELL_FLAGS030) -c parcp.c -o shell_parcp030.o

shell030.o : shell.c parcp.h cfgopts.h menu.c viewer.c box.c
	$(CC) $(SHELL_FLAGS030) -c shell.c -o shell030.o

box030.o : box.c box.h
	$(CC) $(SHELL_FLAGS030) -c box.c -o box030.o

menu030.o : menu.c menu.h
	$(CC) $(SHELL_FLAGS030) -c menu.c -o menu030.o

viewer030.o : viewer.c viewer.h
	$(CC) $(SHELL_FLAGS030) -c viewer.c -o viewer030.o

server_parcp030.o : $(PARCLIENT)
	$(CC) -DPARCP_SERVER $(FLAGS030) -c parcp.c -o server_parcp030.o

match030.o : match.c match.h
	$(CC) $(FLAGS030) -c match.c -o match030.o

cfgopts030.o : cfgopts.c cfgopts.h
	$(CC) $(FLAGS030) -c cfgopts.c -o cfgopts030.o

