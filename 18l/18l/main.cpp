#include <iostream>
using namespace std;
unsigned int count(unsigned int num)
{
	unsigned int count, cur, result;
	_asm
	{ 
		mov eax, num
		mov result, 0 
		mov count, 0 

	go:
		mov cur, 10
		mov edx, 0

		div cur
		mov cur, 1
		
		cmp dx, 0
		je cont

		mov cx, dx
	go1:
		shl cur, 1
		loop go1

	cont:
		mov edx, cur
		or count, edx
		cmp eax, 0
		jne go

	go2:
		mov eax, count 
		and eax, 1
		cmp eax, 0
		je cont_
		inc result

	cont_:
		shr count, 1 
		cmp count, 0
		jne go2



		// TODO: write your asm code here
	}
	return result;
}
int main()
{
	unsigned int numCount;
	cin >> numCount;
	cout << count(numCount) << endl;
	system("pause");
	return 0;
}