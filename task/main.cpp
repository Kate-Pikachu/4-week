#include <iostream>
#include <vector>

void show_sequence(std::vector<int> vec) {
	for (auto const& element : vec)
		std::cout << element << ' ';
}

int main() {

	std::cout << "1) create a sequence P1" << std::endl;
	std::vector <int> P1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	show_sequence(P1);
	std::cout << std::endl;

	std::cout << "2) add some numbers in P1" << std::endl;
	P1.push_back(11);
	P1.push_back(12);
	show_sequence(P1);
	std::cout << std::endl;



	system("pause");
	return EXIT_SUCCESS;
}