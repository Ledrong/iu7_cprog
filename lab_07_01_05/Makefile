CC := gcc
S = ./src/
O = ./out/
I = ./inc/
U = ./unit_tests/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJS := $(O)main.o $(O)key.o $(O)mysort.o $(O)functions.o
OBJSCH := $(O)check_main.o $(O)key.o $(O)mysort.o $(O)functions.o $(O)check_mysort.o $(O)check_key.o

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

$(O)main.o: $(S)main.c $(I)key.h $(I)mysort.h $(I)functions.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)key.o: $(S)key.c $(I)key.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)mysort.o: $(S)mysort.c $(I)mysort.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)functions.o: $(S)functions.c $(I)functions.h $(I)error_codes.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_main.o: ./unit_tests/check_main.c $(I)key.h $(I)mysort.h $(I)functions.h $(I)check_mysort_key.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_mysort.o: $(U)check_mysort.c $(I)check_mysort_key.h
	$(CC) $(CFLAGS) $< -o $@

$(O)check_key.o: $(U)check_key.c $(I)check_mysort_key.h
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
