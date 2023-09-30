#include "parse_text.h"

int ParseText::currentWord;

void ParseText::openFile(const std::string& fileName) {
	f = fopen(fileName.c_str(), "r");
}

void ParseText::parseFile() {
	char buf[1024];
	const char signes[] = ".!?,;:-()[]{}@#$%^&*+_=|/<>№~`";
	int count = fscanf(f, "%s ", buf);

	while(count > 0){
		std::string word = buf;

		for (auto v : words){
			for (int i = sizeof(signes)-1; i != -1; i--){
				if (word == "")
					break;
				if (word.back() == signes[i] | word.back() == '"'){
					word.pop_back();
				}
			}
		}

		if (word != ""){
			std::transform(word.begin(), word.end(), word.begin(), tolower);
			words.push_back(word);	
		}
		count = fscanf(f, "%s ", buf);
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
	int i = 0;
	for (std::string v : words){
		if (i == words.size()-1)
			return {v, true};
		if (i++ == currentWord){
			currentWord++;
			return {v, false};
		}
	}
	return {"В файле ничего нет", true};
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