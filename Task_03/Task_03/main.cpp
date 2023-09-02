#include <iostream>

template <class T>
class vector {
	T* array = nullptr;
	int act_capacity;
	int log_size;
	int last;
public:
	vector() :act_capacity{ 1 }, log_size{0}, last{-1}
	{
		array = new T;
	}
	~vector() {
		delete[] array;
	}

	T at(int index) {
		return array[index];
	}

	void push_back(T value) {
		if (act_capacity < log_size) {
			last += 1;
		}
		if (act_capacity >= log_size) {
			T* new_arr = new T[act_capacity * 2]{0};
			for (int i = 0; i < act_capacity; ++i) {
				new_arr[i] = array[i];

			}
			array = new_arr;
			delete[] new_arr;
			last += 1;
			act_capacity *= 2;
		}
		array[last] = value;
		log_size += 1;
	}

	void print() {
		for (int i = 0; i < log_size; ++i) {
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	int size() {
		return this->log_size;
	}

	int capacity() {
		return this->act_capacity;
	}
};

int main() {
	vector<int> vc;
	vc.push_back(3);
	vc.push_back(1);
	vc.push_back(4);
	vc.push_back(-1);
	vc.print(); 

	std::cout << vc.size() << std::endl;
	std::cout << vc.capacity();
	return 0;
}