#include <iostream>
using namespace std;
char * task1CountSym(char * str1, char * str2)
{
	bool isIn1Str[256];
	char * ans = new char[256];
	_asm
	{
			mov ecx, 256
		zero:
			and isIn1Str[ecx - 1], 0
			loop zero

			mov edi, str1
			mov eax, 0
		s1ne :
			mov al, [edi]
			mov isIn1Str[eax], 1
			cmp [edi], 0
			je s1e
			inc edi
			jmp  s1ne
			

		s1e:
			mov edi, str2
			mov esi, ans
		s2ne:
			mov al, [edi]
			cmp isIn1Str[eax], 1
			jne n1s
			mov [esi], al
			mov isIn1Str[eax], 0
			inc esi
		n1s:
			cmp [edi], 0
			je s2e
			inc edi
			jmp s2ne
		s2e:
	}
	return ans;
}

void task2Inv(unsigned int ** matr, int m, int n)
{
	_asm
	{
		mov eax, 0
		mov ecx, n
		mov ebx, matr
		mov edx, [ebx]
	nl:
		mov esi, ecx
		dec esi
		mov edi, [edx + esi * 4]
		not edi
		mov[edx + esi * 4], edi
		loop nl
		inc eax
		add ebx, 4
		cmp eax, m
		je end_
		mov edx, [ebx]
		mov ecx, n
		jmp nl
	end_:

	}
}

void task2Inv(int ** matr, int m, int n)
{
	_asm
	{
			mov eax, 0
			mov ecx, n
			mov ebx, matr
			mov edx, [ebx]
		nl:
			mov edi, [edx + ecx * 4 - 4]
			mov esi, edi
			and esi, 10000000000000000000000000000000b
			not edi
			shl edi, 1
			shr edi, 1
			add edi, esi
			mov[edx + ecx * 4 - 4], edi
			loop nl

			inc eax
			add ebx, 4
			cmp eax, m
			je end_
			mov edx, [ebx]
			mov ecx, n
			jmp nl
		end_ :

	}
}

int main()
{
	char str1[] = {"add 0"};
	char str2[] = { "kljkl gg 0" };

	char* ans = task1CountSym(str1, str2);
	//cout << ans << endl;
	delete[] ans;

	int n = 5, m = 4;
	int ** matr = new int *[m];
	
	for (int i = 0; i < m; i++)
	{
		matr[i] = new int[n];
		for (int j = 0; j < n; j++)
			matr[i][j] = -i*j;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	task2Inv(matr, m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}