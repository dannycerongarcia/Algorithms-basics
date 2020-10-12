run: mergeSort.o
	g++ -std=c++17 -O2 -Wall mergeSort.o -o run
mergeSort.o: mergeSort.cpp
	g++ -c mergeSort.cpp
clean:
	rm *.o run