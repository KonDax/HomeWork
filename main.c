#include <iostream>
#include <list>
#include <fstream>
#include "parse_text.h"
#include "count_words.h"

int main() {

	const ParseText parseText("test.txt");
	CountWords countWords;

	std::list<std::pair<std::string, bool>> words;
	FILE* f = fopen("result.txt", "w");

	parseText.getFirstWord();
	words.push_back(parseText.getNextWord());
	while (!words.back().second){
		countWords.addWord(words.back().first);
		words.push_back(parseText.getNextWord());
	}
	countWords.addWord(words.back().first);

	int i = 0;
	for (auto value : words)
		fprintf(f, "%d\t%s\t%d\n", ++i, value.first.c_str(), countWords.getCountWord(value.first));

	fclose(f);

	return 0;
}

//Результат записать в файл с названием «result» в следующем формате:
//№\tword\tcount\n