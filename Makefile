CC=gcc -g -Wall -Wextra
MAINCFILES=$(wildcard ./src/main/*.c)
MAINOBJFILES=$(MAINCFILES:.c=.o)
MAINHFILES=$(wildcard ./src/main/include/*.h)

STACKCFILES=$(wildcard ./src/stack/*.c)
STACKOBJFILES=$(STACKCFILES:.c=.o)
STACKHFILES=$(wildcard ./src/stack/include/*.h)

MENUCFILES=$(wildcard ./src/menus/*.c)
MENUOBJFILES=$(MENUCFILES:.c=.o)
MENUHFILES=$(wildcard ./src/menus/include/*.h)

TOKENCFILES=$(wildcard ./src/token/*.c)
TOKENOBJFILES=$(TOKENCFILES:.c=.o)
TOKENHFILES=$(wildcard ./src/token/include/*.h)

FPPCFILES=$(wildcard ./src/file_preprocessing/*.c)
FPPOBJFILES=$(FPPCFILES:.c=.o)
FPPHFILES=$(wildcard ./src/file_preprocessing/include/*.h)

EXEFILE=./puny
TARGETS=$(wildcard idata/tests/*.py)
# TARGETS=./idata/tests/07cs_three.py

LX=flex
FLEXFILE=flex/punylex.l
FLEXOUT=src/lexer/punylex.c
FLEXOUTO=src/lexer/punylex.o
FLEXHOUT=src/lexer/include/punylex.h

all: objs $(FLEXOUTO)
	$(CC) $(FLEXOUTO) $(MAINOBJFILES) $(STACKOBJFILES) $(MENUOBJFILES) $(TOKENOBJFILES) $(FPPOBJFILES) -o $(EXEFILE) -lm

$(FLEXOUTO): $(FLEXOUT)
	$(CC) -c $(FLEXOUT) -o $(FLEXOUTO)

$(FLEXOUT):
	$(LX) -o $(FLEXOUT) $(FLEXFILE)

objs: $(MAINCFILES) $(MAINHFILES) $(STACKHFILES) $(MENUHFILES) $(TOKENHFILES) $(FPPHFILES)
	$(CC) -c ./src/main/main.c -o ./src/main/main.o -lm
	$(CC) -c ./src/menus/menus.c -o ./src/menus/menus.o -lm
	$(CC) -c ./src/stack/stack.c -o ./src/stack/stack.o -lm
	$(CC) -c ./src/token/token_type.c -o ./src/token/token_type.o -lm
	$(CC) -c ./src/token/token.c -o ./src/token/token.o -lm
	$(CC) -c ./src/token/token_list.c -o ./src/token/token_list.o -lm
	$(CC) -c ./src/file_preprocessing/file_preprocessing.c -o ./src/file_preprocessing/file_preprocessing.o -lm

vim:
	nvim $(MAINCFILES) $(STACKCFILES) $(MENUCFILES) $(TOKENCFILES) $(FPPCFILES) $(FLEXFILE)

vimh:
	nvim $(HFILES) 

run:
	$(EXEFILE) $(TARGETS)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) $(TARGETS)

feh:
	feh docs/uml.png&

plant:
	plantuml docs/uml.txt
	convert docs/uml.png -channel RGB -negate docs/uml.png

git-update:
	git add Makefile README.md src/ flex/ bin/ docs/ idata/

clean:
	rm $(MAINOBJFILES) $(STACKOBJFILES) $(MENUOBJFILES) $(TOKENOBJFILES) $(FPPOBJFILES) $(FLEXOUTO)
	rm $(EXEFILE)
	rm $(FLEXOUT)
