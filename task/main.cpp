#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void show_sequence(std::vector<int> vec) {
	for (auto const& element : vec)
		std::cout << element << ' ';
}

auto isPrime(int n) {
	
	if (n == 1)
		return 0;
	for (auto k = 2; k < n; ++k) {
		if (n % k == 0)
			return 0;
		else
			return 1;
	}
}

int main() {

	std::cout << "	1) create a sequence P1" << std::endl;
	std::vector <int> P1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	show_sequence(P1);
	std::cout << std::endl;

	std::cout << "	2) add some numbers in P1" << std::endl;
	P1.push_back(11);
	P1.push_back(9);
	show_sequence(P1);
	std::cout << std::endl;

	std::cout << "	3) mix elements of P1" << std::endl;
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::shuffle(std::begin(P1), std::end(P1), mersenne);
	show_sequence(P1);
	std::cout << std::endl;

	std::cout << "	4) delete duplicates in P1" << std::endl;
	std::sort(std::begin(P1), std::end(P1));
	P1.erase(std::unique(std::begin(P1), std::end(P1)), std::end(P1));
	show_sequence(P1);
	std::cout << std::endl;

	std::cout << "	5) count odd numbers in P1" << std::endl;
	std::cout << std::count_if(std::begin(P1), std::end(P1), [](int n) {return n % 2 != 0; })
		<< " numbers " << std::endl;

	std::cout << "	6) define max and min numbers in P1" << std::endl;
	std::cout << "Max: " << *std::max_element(std::begin(P1), std::end(P1)) << std::endl;
	std::cout << "Min: " << *std::min_element(std::begin(P1), std::end(P1)) << std::endl;

	std::cout << "	7) define prime numbers in P1" << std::endl;
	auto x = std::find_if(std::begin(P1), std::end(P1), [](auto n) {return isPrime(n); });
	if (x == std::end(P1))
		std::cout << "No prime numbers " << std::endl;
	else 
		std::cout << *x << " numbers" << std::endl;






	system("pause");
	return EXIT_SUCCESS;
}