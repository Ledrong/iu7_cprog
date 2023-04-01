CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)queue.o $(O)stack.o
OBJSCH := $(O)check_funcs.o $(O)queue.o $(O)stack.o
.PHONY: clean unit release

release: app.exe

app.exe: out $(OBJS)
	$(CC) -o $@ $(OBJS)

unit: unit_tests.exe
	./$^ 
unit_tests.exe: out $(OBJSCH)
	$(CC) -o $@ $(OBJSCH) -lcheck -lpthread

$(O)main.o: $(S)main.c
	$(CC) $(CFLAGS) $< -o $@

$(O)queue.o: $(S)queue.c $(I)queue.h
	$(CC) $(CFLAGS) $< -o $@

$(O)stack.o: $(S)stack.c $(I)stack.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_funcs.o: $(U)check_funcs.c $(I)queue.h $(I)stack.h
	$(CC) $(CFLAGS) $< -o $@

out :
	mkdir out

clean:
	rm -f $(O)*.o *.exe
	rm -fr $(O)