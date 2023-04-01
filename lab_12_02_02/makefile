CC := gcc
I := ./inc/
O := ./out/
S := ./src/
CFLAGS = -std=c99 -I$(I) -Wall -Werror -pedantic -c
OBJSCH := $(O)check_fibonacci.o $(O)fibonacci.o
              
.PHONY: clean unit func
.NOTPARALLEL: release debug

out:
	mkdir out

release: $(O) $(O)release.lastbuildstate fibonacci.dll main.py
	python3 main.py

debug: CFLAGS += -DDEBUG -g3
debug: out $(O)release.lastbuildstate fibonacci.dll main.py
	python3 main.py

app.exe: $(O) $(O)fibonacci fibonacci.dll main.py
	python3 main.py

unit: unit_tests.exe
	./$^ 
unit_tests.exe: out $(OBJSCH)
	$(CC) -o $@ $(OBJSCH) -lcheck -lpthread

fibonacci.dll: $(O) $(O)fibonacci.o 
	$(CC) -shared $(O)fibonacci.o -Wl,--subsystem,windows -o fibonacci.dll 

$(O)fibonacci.o: $(S)fibonacci.c $(I)fibonacci.h
	$(CC) $(CFLAGS) -c $(S)fibonacci.c -o $(O)fibonacci.o

$(O)debug.lastbuildstate: $(O)
	touch $(O)debug.lastbuildstate

$(O)release.lastbuildstate: $(O)
	touch $(O)release.lastbuildstate

$(O)check_fibonacci.o: $(U)check_fibonacci.c $(I)fibonacci.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(O)*.o *.exe
	rm -fr $(O)
	rm -fv *.DS_Store
	rm -fr *.dll

func: test.exe
	./$^ 
test.exe: test.o $(O)fibonacci.o
	$(CC) -o test.exe test.o $(O)fibonacci.o && ./test.exe
