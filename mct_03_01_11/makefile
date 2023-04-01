CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)cdii.o $(O)functions.o

.PHONY: clean debug release

release: app.exe

debug: CFLAGS += -DDEBUG -g3
debug: app.exe

app.exe: out $(OBJS)
    $(CC) -o $@ $(OBJS)

$(O)main.o: $(S)main.c $(I)functions.h $(I)cdio.h
    $(CC) $(CFLAGS) $< -o $@

$(O)functions.o: $(S)functions.c $(I)functions.h
    $(CC) $(CFLAGS) $< -o $@

$(O)cdio.o: $(S)cdio.c $(I)cdio.h
    $(CC) $(CFLAGS) $< -o $@

out:
    mkdir out

clean:
    rm -f $(O) *.o *.exe
    rm -fv *.DS_Store