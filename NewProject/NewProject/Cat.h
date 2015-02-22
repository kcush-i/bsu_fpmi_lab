class Cat
{
public:
	Cat();
	Cat(char*, char, int = 0);
	virtual void show();
	void operator++();
protected:
	char name[20];
	char sex;
	int age;
};