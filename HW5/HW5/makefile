all: prog

prog: main.o Cell.o ConnectFourAbstract.o ConnectFourPlus.o ConnectFourDiag.o ConnectFourPlusUndo.o
	g++ main.o Cell.o ConnectFourAbstract.o ConnectFourPlus.o ConnectFourDiag.o ConnectFourPlusUndo.o -o exe -std=c++11

main.o: main.cpp
	g++ -c -ansi -pedantic -errors main.cpp -std=c++11

Cell.o: Cell.cpp
	g++ -c -ansi -pedantic -errors Cell.cpp -std=c++11
	
ConnectFourAbstract.o: ConnectFourAbstract.cpp
	g++ -c -ansi -pedantic -errors ConnectFourAbstract.cpp -std=c++11
	
ConnectFourPlus.o: ConnectFourPlus.cpp
	g++ -c -ansi -pedantic -errors ConnectFourPlus.cpp -std=c++11

ConnectFourDiag.o: ConnectFourDiag.cpp
	g++ -c -ansi -pedantic -errors ConnectFourDiag.cpp -std=c++11

ConnectFourPlusUndo.o: ConnectFourPlusUndo.cpp
	g++ -c -ansi -pedantic -errors ConnectFourPlusUndo.cpp -std=c++11

clean:
	rm *.o exe
