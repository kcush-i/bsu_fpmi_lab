#include "Cat.h"


Cat::Cat(char* n, char s, int a)
{
	int i = 0;
	for (;i < 19 && n[i] != 0; i++)
		name[i] = n[i];
	name[i] = 0;
	sex = s;
	age = a;
}




Kitten::Kitten(char* n, char* m, char* f,  char s, int a) :Cat(n, s, a)
{
	int i = 0;
	for (; i < 19 && m[i] != 0; i++)
		mother[i] = m[i];
	mother[i] = 0;
	for (i = 0; i < 19 && f[i] != 0; i++)
		father[i] = f[i];
	father[i] = 0;
}


