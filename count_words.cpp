#include "count_words.h"

const int maxCountWords = 10;
CountWords::CountWords(){};
CountWords::~CountWords(){};
int CountWords::getCountWord(const std::string& word) const {
	if (countWords.count(word) == 0)
		return 0;
	return countWords.at(word);
}

int CountWords::addWord(const std::string& word){
	countWords[word]++;
	return countWords.at(word);
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
