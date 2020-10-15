run: main.o mergeSort.o quickSort.o
	g++ -std=c++17 -O2 -Wall main.o mergeSort.o quickSort.o -o run
mergeSort.o: mergeSort.cpp mergeSort.h
	g++ -c mergeSort.cpp mergeSort.h
quickSort.o: quickSort.cpp quickSort.h
	g++ -c quickSort.cpp quickSort.h
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o run