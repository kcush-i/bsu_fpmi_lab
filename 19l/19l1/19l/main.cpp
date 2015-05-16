#include <iostream>
#include <cmath>
using namespace std;

long double fun1(long double x, long double y, int n)
{
	long double temp, ans1, ans2, ans3, ans;
	_asm
	{
		finit
		fldz 
		fst ans 
		mov ecx, n
		cmp ecx, 0
		je end_
		
		fld x
		fmul x
		fdiv y
		fst temp
		fmul x
		fst ans1
		fst ans2
		fst ans3
		fst ans
		sub ecx, 1
		cmp ecx, 1
		jl end_
	go:
		fld temp
		fdiv y
		fstp temp
		fld ans1
		fmul temp
		fstp ans1
		fld ans2
		fadd ans1
		fstp ans2
		fld ans3
		fadd ans2
		fstp ans3
		fld ans
		fadd ans3
		fstp ans
		loop go
	end_:
	}
	return ans;
}




int main()
{

	long double rez = fun1(2, 1, 1);
	cout << rez << endl;
	system("pause");
	return 0;
}