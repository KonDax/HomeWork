#ifndef parse_text_h
#define parse_text_h

#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>

class ParseText {
	private :
		FILE* f;
		std::list<std::string> words;
		static int currentWord;
		void openFile(const std::string& fileName);
		void parseFile();
		void closeFile();
	public :
		ParseText() = delete;
		ParseText(const std::string& fileName);
		ParseText(const std::string& fileName, unsigned long long int maxWords);
		~ParseText() { };
		const std::string& getFirstWord() const {currentWord = 0; return words.front();};
		const std::pair<std::string, bool> getNextWord() const;
		const std::string getWordAt(int index) const;
};

#endif
