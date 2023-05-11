# COMPILATION SETTINGS
CC=gcc
CFLAGS=-Wall -std=c17
LDLIBS=-lMLV -lm -Werror

# DIRECTORIES
OBJDIR=obj
SRCDIR=src
INCDIR=include

# FILES
EXEC=dames
OBJ=obj/display.o obj/dames.o obj/main.o

.PHONY: all run force clean

all: $(EXEC)

$(OBJDIR)/display.o: include/display.h src/display.c
	$(CC) -c src/display.c -o obj/display.o $(CFLAGS) $(LDLIBS) 

$(OBJDIR)/dames.o: include/dames.h src/dames.c
	$(CC) -c src/dames.c -o obj/dames.o $(CFLAGS) $(LDLIBS) 

$(OBJDIR)/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o $(CFLAGS) $(LDLIBS)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LDLIBS)

run: $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LDLIBS)
	./$(EXEC)

force:
	make --always-make

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(EXEC)