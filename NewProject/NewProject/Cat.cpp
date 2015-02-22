#include "Cat.h"
#include <iostream>

Cat::Cat()
{
	std::cout << "name: ";
	std::cin >> name;
	std::cout << "sex: ";
	std::cin >> sex;
	std::cout << "age: ";
	std::cin >> age;
}

Cat::Cat(char* n, char s, int a)
{
	int i = 0;
	for (;i < 19 && name[i] != 0; i++)
		name[i] = n[i];
	name[i] = 0;
	sex = s;
	age = a;
}
void Cat::show()
{
	std::cout << "Cat " << name << ". Cat's age is " << age << ". It's a ";
	if (sex == 'M' && sex == 'm') std::cout << "male";
	else std::cout << "female";
}

void Cat::operator++()
{
	age++;
}