#include <iostream>
class Cat
{
public:
	Cat(char*, char, int = 0);
	virtual	void Cat::show()
	{
		std::cout << std::endl << "Cat " << name << ". Cat's age is " << age << ". It's a ";
		if (sex == 'M' || sex == 'm') std::cout << "male";
		else std::cout << "female";
	}
protected:
	char name[20];
	char sex;
	int age;
};

class Kitten :public Cat
{
public:
	Kitten(char*, char*, char*, char, int = 0);
	virtual void Kitten::show()
	{
		std::cout << std::endl << "Kitten " << "name" << ". " << name << "'s age is " << age << ". It's a ";
		if (sex == 'M' && sex == 'm') std::cout << "male. ";
		else std::cout << "female. ";
		std::cout << "His mother is " << mother << ". His father is " << father << "." << std::endl;
	}
protected:
	char mother[20];
	char father[20] ;

};