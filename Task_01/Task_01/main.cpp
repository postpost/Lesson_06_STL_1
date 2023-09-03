#include <iostream>
#include <set>
#include <map>
#include <algorithm>

int main() {

	char letter[] = { "Hello world!!" };
	std::string str = letter;

	std::cout << "[IN]: ";
	for (const auto& el : letter)
		std::cout << el;

	auto it = str.cbegin();
	//std::cout << *it << typeid(it).name();

	std::multimap <char, int> mmis; // to copy letters array
	std::map<char, int> mci; //remove duplicate


	int count = 0;
	for (; it != str.end(); ++it) {
		mmis.insert(std::make_pair(str[count], count));
		count++;
	}
	//make new pairs for mci (std::map)
	for (auto itr = mmis.begin(); itr != mmis.end(); ++itr) {
		//std::cout << mmis.count((*itr).first) << " " << (*itr).first << std::endl;
		mci.insert(std::make_pair((*itr).first, mmis.count((*itr).first)));
	}

	//MAKE COUNT BY KEY, NOT VALUE!
	//char - key(k.first), int - value (k.second);
	/*std::cout << "\n---MAP---\n" << mci.size() << std::endl;
	for (const auto& k : mci) {
		std::cout << k.first << ": " << k.second << std::endl;
	}*/
	//create new container to sort by int and "greater"
	std::multimap<int, char, std::greater<int>> mmic_new;
	for (auto itr = mci.begin(); itr != mci.end(); ++itr) {
		mmic_new.insert(std::make_pair((*itr).second, (*itr).first));
	}
	
	std::cout << "\n[OUT]:\n";
	for (const auto& k : mmic_new) {
		std::cout << k.first << ": " << k.second << std::endl;
	}

	return 0;
}