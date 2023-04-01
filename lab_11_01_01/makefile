CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)my_snprintf.o $(O)dop_functions.o
OBJSCH := $(O)check_mysnprintf.o $(O)my_snprintf.o $(O)dop_functions.o
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

$(O)main.o: $(S)main.c $(I)my_snprintf.h $(I)dop_functions.h
	$(CC) $(CFLAGS) $< -o $@

$(O)my_snprintf.o: $(S)my_snprintf.c $(I)my_snprintf.h
	$(CC) $(CFLAGS) $< -o $@

$(O)dop_functions.o: $(S)dop_functions.c $(I)dop_functions.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_mysnprintf.o: $(U)check_mysnprintf.c $(I)dop_functions.h $(I)my_snprintf.h
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
