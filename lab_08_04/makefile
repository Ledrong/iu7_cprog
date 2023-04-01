CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)functions.o $(O)cdio.o $(O)multiplication.o
OBJSCH := $(O)check_main.o $(O)multiplication.o $(O)cdio.o $(O)check_multiplication.o $(O)check_cdio.o

.PHONY: clean unit func debug release

release: app.exe

debug: CFLAGS += -DDEBUG -g3
debug: app.exe
	
app.exe: out $(OBJS)
	$(CC) -o $@ $(OBJS)

unit: unit_tests.exe
	./$^ 
unit_tests.exe: out $(OBJSCH)
	$(CC) -o $@ $(OBJSCH) -lcheck -lpthread

$(O)main.o: $(S)main.c $(I)functions.h $(I)error_codes.h $(I)cdio.h $(I)multiplication.h
	$(CC) $(CFLAGS) $< -o $@

$(O)functions.o: $(S)functions.c $(I)functions.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)multiplication.o: $(S)multiplication.c $(I)multiplication.h
	$(CC) $(CFLAGS) $< -o $@

$(O)cdio.o: $(S)cdio.c $(I)cdio.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_main.o: $(U)check_main.c $(I)cdio.h $(I)multiplication.h $(I)check_multiplication_cdio.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_multiplication.o: $(U)check_multiplication.c $(I)check_multiplication_cdio.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_cdio.o: $(U)check_cdio.c $(I)check_multiplication_cdio.h
	$(CC) $(CFLAGS) $< -o $@

out :
	mkdir out

clean:
	rm -f $(O)*.o *.exe
	rm -fr $(O)
	rm -fv *.DS_Store

func: app.exe
		@echo
		cd ./func_tests/ && ./all_tests.cmd
