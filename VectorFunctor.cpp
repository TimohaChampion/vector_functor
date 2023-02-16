#include<iostream>
#include<vector>

using namespace std;

class Class {
	int* mass = nullptr;
	int value = 0;
	int min = 0;
public:
	Class(int *mass, int value) {
		this->value = value;
		this->mass = new int[value];
		for (int i = 0; i < value; i++) {
			this->mass[i] = mass[i];
		}
	}
	int operator()() {
		min = mass[0];
		for (int i = 1; i < value; i++) {
			if (min > mass[i])min = mass[i];
		}
		return min;
	}
	~Class() {
		delete[]mass;
	}
};

int main() {
	const int value = 6;
	int mass[value]{ 11, 7, 9, 2, 5, 3 };
	Class obj(mass, value);
	cout << obj() << endl;


}
