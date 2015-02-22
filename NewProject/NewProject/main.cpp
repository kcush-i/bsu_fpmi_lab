#include <iostream>
#include "Cat.h"
int main()
{
	std::cout << "hello world!";
	char n[30], m[30], f[30], s;
	int a;



	std::cout << "name: ";
	std::cin >> n;
	std::cout << "sex: ";
	std::cin >> s;
	std::cout << "age: ";
	std::cin >> a;
	Cat* A = new Cat(n, s, a);
	A->show();
	delete A;

	std::cout << "name: ";
	std::cin >> n;
	std::cout << "sex: ";
	std::cin >> s;
	std::cout << "age: ";
	std::cin >> a;
	std::cout << "names of the parents: ";
	std::cin >> m;
	std::cin >> f;
	Kitten B(n, m, f, s, a);
	B.show();
	return 0;
}