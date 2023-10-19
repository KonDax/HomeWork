#ifndef count_words_h
#define count_words_h

#include <map>
#include <string>
#include <list>

class CountWords {
	private :
		std::map<std::string, int> countWords;
		std::map< std::pair<std::string, std::string>, int> countWordsPairs;
	public:
		CountWords();
		~CountWords();
		int insertWordsPair(const std::pair<std::string, std::string>& pair_word);
		std::tuple<std::string, std::string, int> getWordPair(const std::pair<std::string, std::string>& pair_word);
		int getCountWord(const std::string& word) const;
		int addWord(const std::string& word); //возвращает число слов, встретившихся в тексте
		const std::list<std::pair<std::string, int>> getMaxCountWord() const; // возвращает список слов, которые встретились чаще других не более 10 слов
		const std::list<std::pair<std::string, int>> getMinCountWord() const; // возвращает список слов, которые встретились реже других не более 10 слов
		std::map<std::string, int> get(){return countWords;};
};

#endif
