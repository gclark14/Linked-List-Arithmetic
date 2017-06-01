all: hw09

hw09: findSign.o addVal.o getVal.o setVal.o assign.o subVal.o compareTo.o main.o trim.o constructors.o mulVal.o getLength.o outputNodeAdd.o menu.o addZeros.o hw09.h appendants.o
	g++ -g -o p -Wall $^

findSign.o: findSign.cpp
	g++ -g -c findSign.cpp

appendants.o: appendants.cpp
	g++ -g -c appendants.cpp

addVal.o: addVal.cpp
	g++ -g -c addVal.cpp

getVal.o: getVal.cpp
	g++ -g -c getVal.cpp

setVal.o: setVal.cpp
	g++ -g -c setVal.cpp

assign.o: assign.cpp
	g++ -g -c assign.cpp

subVal.o: subVal.cpp
	g++ -g -c subVal.cpp

compareTo.o: compareTo.cpp
	g++ -g -c compareTo.cpp

main.o: main.cpp
	g++ -g -c main.cpp

menu.o: menu.cpp
	g++ -g -c menu.cpp

trim.o: trim.cpp
	g++ -g -c trim.cpp

constructors.o: constructors.cpp
	g++ -g -c constructors.cpp

mulVal.o: mulVal.cpp
	g++ -g -c mulVal.cpp

getLength.o: getLength.cpp
	g++ -g -c getLength.cpp

outputNodeAdd.o: outputNodeAdd.cpp
	g++ -g -c outputNodeAdd.cpp

addZeros.o: addZeros.cpp
	g++ -g -c addZeros.cpp

clean: 
	rm -v findSign.o appendants.o addVal.o getVal.o setVal.o assign.o subVal.o compareTo.o main.o trim.o constructors.o mulVal.o getLength.o outputNodeAdd.o menu.o addZeros.o

## Macros below specify the type of clean.

ctar: 
	rm -v *tar

cscr:
	rm -v *.scr

cx:
	rm -v p

tar: hw09.tar

hw09.tar:
	tar -cvf hw09.tar hw09.scr addVal.cpp getVal.cpp setVal.cpp assign.cpp subVal.cpp compareTo.cpp main.cpp trim.cpp constructors.cpp mulVal.cpp getLength.cpp outputNodeAdd.cpp addZeros.cpp menu.cpp Makefile hw09.h
