#include "count_words.h"

const int maxCountWords = 10;
CountWords::CountWords(){};
CountWords::~CountWords(){};

int CountWords::insertWordsPair(const std::pair<std::string, std::string>& pair_word){
	if (pair_word.first == pair_word.second | pair_word.first.back() | (not(97 <= pair_word.first.back() && pair_word.first.back() <= 120) && not(65 <= pair_word.first.back() && pair_word.first.back() <= 90)))
		return countWordsPairs.count(pair_word);
	countWordsPairs[pair_word]++;
	return countWordsPairs.count(pair_word);
}

std::tuple<std::string, std::string, int> CountWords::getWordPair(const std::pair<std::string, std::string>& pair_word){
	std::tuple<std::string, std::string, int> tuple {pair_word.first, pair_word.second, countWordsPairs.count(pair_word)};
	return tuple;
}

int CountWords::getCountWord(const std::string& word) const {
	if (countWords.count(word) == 0)
		return 0;
	return countWords.at(word);
}

int CountWords::addWord(const std::string& word){
	std::string Word;
	for (auto value : word){
		if (65 <= value && value <= 90){
			value += 32;
		}
		Word.push_back(value);
	}
	countWords[Word]++;
	return countWords.at(Word);
}

const std::list<std::pair<std::string, int>> CountWords::getMaxCountWord() const {
	std::list<std::pair<std::string, int>> list;
	for (auto value : countWords){
		if (list.empty()){
			list.push_back(value);
			continue;
		}
		auto begin = list.begin();
		for (auto l : list){
			if (value.second >= l.second){
				list.insert(begin, value);
				break;
			}
			begin++;
			if (begin == list.end()){
				list.insert(begin, value);
				break;
			}
		}
		if (list.size() > maxCountWords)
			list.pop_back();
	}
	return list;
} // возвращает список слов, которые встретились чаще других не более 10 слов
const std::list<std::pair<std::string, int>> CountWords::getMinCountWord() const {
	std::list<std::pair<std::string, int>> list;
	for (auto value : countWords){
		if (list.empty()){
			list.push_back(value);
			continue;
		}
		auto begin = list.begin();
		for (auto l : list){
			if (value.second <= l.second){
				list.insert(begin, value);
				break;
			}
			begin++;
			if (begin == list.end()){
				list.insert(begin, value);
				break;
			}
		}
		if (list.size() > maxCountWords)
			list.pop_back();
	}
	return list;
} // возвращает список слов, которые встретились реже других не более 10 слов
