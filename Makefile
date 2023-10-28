all : main.o test.o task2.o
	g++ -g main.o test.o task2.o

task2.o : task2.cpp
	g++ -c -g task2.cpp

main.o : main.cpp
	g++ -c -g main.cpp

test.o : test.cpp
	g++ -c -g test.cpp

clean :
	rm -rf *.o *.*~
