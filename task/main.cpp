#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <numeric>

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
	std::cout << std::count_if(std::begin(P1), std::end(P1), [](auto n) {return n % 2 != 0; })
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


	std::cout << "	8) substitute numbers in P1 with their squares" << std::endl;
	std::transform(std::begin(P1), std::end(P1), std::begin(P1), [](auto n) {return std::pow(n, 2); });
	show_sequence(P1);
	std::cout << std::endl;


	std::cout << "	9) create a sequence P2 consists of N elements, N - length of P1" << std::endl;
	std::vector <int> P2;
	std::random_device rad;
	std::mt19937 mers(rad());
	std::uniform_int_distribution<> un_distrib(1, 100);
	for (auto i = 0; i < std::size(P1); ++i) {
		P2.push_back(un_distrib(mers));
	}
	show_sequence(P2);
	std::cout << std::endl;


	std::cout << "	10) sum of elements in P2 " << std::endl;
	auto sum = std::accumulate(std::begin(P2), std::end(P2), 0);
	std::cout << sum << std::endl;


	std::cout << "	11) change some first elements in P2 " << std::endl;
	std::transform(std::begin(P2), std::next(std::begin(P2), 3), std::begin(P2), [](auto n) {return 1; });
	show_sequence(P2);
	std::cout << std::endl;


	std::cout << "	12) create sequence P3 with elements equal to subrtaction of P1 and P2 " << std::endl;
	std::vector <int> P3;
	std::sort(std::begin(P1), std::end(P1));
	std::sort(std::begin(P2), std::end(P2));
	std::cout << "P1: ";
	show_sequence(P1);
	std::cout << std::endl;
	std::cout << "P2: ";
	show_sequence(P2);
	std::cout << std::endl;

	std::set_difference(
		P2.cbegin(), P2.cend(),
		P1.cbegin(), P1.cend(),
		std::back_inserter(P3));

	std::cout << "P3: ";
	show_sequence(P3);
	std::cout << std::endl;



	std::cout << "	13) replace negative numbers with zero  " << std::endl;
	// there are no negative numbers, so i'm going to push them back into P3
	P3.push_back(-3);
	P3.push_back(-234);
	std::cout << "Before: ";
	show_sequence(P3);
	std::cout << std::endl;
	std::transform(std::begin(P3), std::end(P3), std::begin(P3), [](auto n) { if (n < 0) return 0; else return n; });
	std::cout << "After: ";
	show_sequence(P3);
	std::cout << std::endl;


	std::cout << "	14) delete zero's in P3  " << std::endl;
	P3.erase(std::remove(std::begin(P3), std::end(P3), 0), std::end(P3));
	show_sequence(P3);
	std::cout << std::endl;




	system("pause");
	return EXIT_SUCCESS;
}