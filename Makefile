all : main.o count_words.o parse_text.o
	g++ -g main.c count_words.cpp parse_text.cpp -std=c++17

main.o : main.c
	g++ -c -g main.c -std=c++17

count_words.o : count_words.cpp
	g++ -c -g count_words.cpp -std=c++17

parse_text.o : parse_text.cpp
	g++ -c -g parse_text.cpp -std=c++17

clean :
	rm -rf *.o *.swp
