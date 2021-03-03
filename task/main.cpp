#include<iostream>
#include <vector>

int main() {

	std::cout << "1) create a sequence P1" << std::endl;
	std::vector <int> P1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto const& element : P1)
		std::cout << element << ' ';



	system("pause");
	return EXIT_SUCCESS;
}