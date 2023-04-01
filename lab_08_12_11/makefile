CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)math_functions.o $(O)cdio.o
OBJSCH := $(O)check_main.o $(O)cdio.o $(O)check_cdio.o $(O)math_functions.o $(O)check_math_functions.o

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

$(O)main.o: $(S)main.c $(I)math_functions.h $(I)error_codes.h $(I)cdio.h
	$(CC) $(CFLAGS) $< -o $@

$(O)math_functions.o: $(S)math_functions.c $(I)math_functions.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)cdio.o: $(S)cdio.c $(I)cdio.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_main.o: $(U)check_main.c $(I)cdio.h $(I)math_functions.h $(I)check_math_cdio.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_math_functions.o: $(U)check_math_functions.c $(I)check_math_cdio.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_cdio.o: $(U)check_cdio.c $(I)check_math_cdio.h
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

