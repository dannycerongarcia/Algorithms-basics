run: main.o mergeSort.o 
	g++ -std=c++17 -O2 -Wall main.o mergeSort.o -o run
mergeSort.o: mergeSort.cpp mergeSort.h
	g++ -c mergeSort.cpp mergeSort.h
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o run