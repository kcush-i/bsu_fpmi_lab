#include <iostream>
using namespace std;





int main()
{
	int * mas;
	mas = new int[18]{98, 3, 45, 6, 7, 1, 9, 15, 98, 6, 98, 86, 644, 98, 0, -9, -12, 8};
	

	unsigned int n = 17;
	unsigned int comp1, comp2, step, poz;
	int * mas1;
	mas1 = new int[n];

	_asm
	{
			mov step, 2
			mov comp1, 0
			mov comp2, 1
			mov poz, 0
			mov eax, 1
			mov ebx, 2


		start:
			cmp comp1, eax
			je ec1

			cmp comp2, ebx
			je ec2
			mov esi, n
			cmp comp2, esi
			je ec2

			mov ecx, comp1
			mov esi, mas
			mov edx, [esi + ecx * 4]
			mov ecx, comp2
			mov esi, mas
			cmp edx, [esi + ecx * 4] // comp1 < comp2
			jg c1g

			mov ecx, comp1
			inc comp1


		cp :
			mov esi, mas
			mov edx, [esi + ecx * 4]
			mov ecx, poz
			mov esi, mas1
			mov [esi + ecx * 4], edx
			inc poz


			jmp start


		c1g :
			mov ecx, comp2
			inc comp2
			jmp cp



		ec1 :
			mov ecx, n
			cmp poz, ecx
			jge endr
			mov ecx, comp2

			mov esi, mas
			mov edx, [esi + ecx * 4]
			mov ecx, poz
			mov esi, mas1
			mov[esi + ecx * 4], edx
			inc poz
			inc comp2

			cmp comp2, ebx
			jl ec1
			jmp nr//

		ec2 :
			mov ecx, n
			cmp poz, ecx
			jge endr


			mov ecx, comp1
			mov esi, mas
			mov edx, [esi + ecx * 4]
			mov ecx, poz
			mov esi, mas1
			mov[esi + ecx * 4], edx

			inc poz
			inc comp1

			cmp comp1, eax
			jl ec2

		nr :
		mov comp1, ebx
			add eax, step
			mov comp2, eax
			add ebx, step

			cmp eax, n
			jge ec2

			jmp start

		endr :

			mov esi, mas1
			mov edx, mas
			mov mas, esi
			mov mas1, edx
			mov comp1, 0
			mov eax, step
			mov comp2, eax
			shl step, 1
			mov ebx, step
			mov poz, 0

			cmp eax, n
			jl start
	}

	delete[] mas1;

	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	delete[] mas;
	system("pause");
}
