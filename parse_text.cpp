#include "parse_text.h"

int ParseText::currentWord;

void ParseText::openFile(const std::string& fileName) {
	f = fopen(fileName.c_str(), "r");
}

void ParseText::parseFile() {
	char buf[1024];
	int count = fread(buf, 1, 1024, f);
	std::string bufStr = buf;
	std::string word = "";

	for (auto value : bufStr){
		if (97 <= value && value <= 122){
			word += value;
			continue;
		}
		if (word != ""){
               		words.push_back(word);
			word = "";
		}
	}	
}

void ParseText::closeFile() {
	fclose(f);
}

ParseText::ParseText(const std::string& fileName) {
	openFile(fileName);
	parseFile();
	closeFile();

};
ParseText::ParseText(const std::string& fileName, unsigned long long int maxWords) {
	openFile(fileName);
	parseFile();
	closeFile();
	while (words.size() > maxWords)
		words.pop_back();
};

const std::pair<std::string, bool> ParseText::getNextWord() const {
	currentWord++;
	int i = 0;
	for (std::string v : words){
		if (i == words.size()-1)
			return {v, true};
		if (i++ == currentWord){
			return {v, false};
		}
	}
	return {"", true};
};

const std::string ParseText::getWordAt(int index) const {
	int i = 0;
	for (std::string v : words){
		if (i == index)
			return v;
		i++;
	}
	return "";
};
