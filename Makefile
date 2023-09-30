all : main.o count_words.o parse_text.o
	g++ -g main.c count_words.cpp parse_text.cpp

main.o : main.c
	g++ -c -g main.c

count_words.o : count_words.cpp
	g++ -c -g count_words.cpp

parse_text.o : parse_text.cpp
	g++ -c -g parse_text.cpp

clean :
	rm -rf *.o *.swp