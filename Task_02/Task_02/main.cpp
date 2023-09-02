#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

class compare {
public:
	compare() = default;
	int operator() (int a, int b) {
		return a > b;
	}
};

int main() {

	std::cout << "[IN]: \n";
	std::list<int> li;
	std::list<int>::iterator it = li.begin();
	std::set<int> si;
	int count = 0, num =0, a=0;
	std::cin >> count;

	while (num != count) {
		std::cin >> a;
		si.insert(a);
		num++;
	}
	
	//pass unique set to the list
	for (const auto& el : si) {
		li.insert(it, el);
	}

	//overloaded by greater num
	li.sort(compare());

	//print results
	std::cout << "\n[OUT]: \n";
	for (const auto& el : li) {
		std::cout << el << std::endl;
	}

	return 0;
}