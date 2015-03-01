#include <iostream>
#include  <vector>
#include  <list>
using namespace std;

template<class Container>
typename Container::iterator rep(Container & A)
{
	typename Container::iterator i = A.end();
	bool c = true;
	while (c && i != A.begin())
	{
		i--;
		for (typename Container::iterator j = i; j != A.begin() && c; )
		{
			j--;
			if (*j == *i) c = false;
		}
	}
	if (i == A.begin())
		return A.end();
	return i;
}

int main()
{
	vector<int> v(15, 8);
	v[14] = 76;
	v[12] = 2;
	v[13] = 2;
	list<int> b(5, 1);
	vector<int>::iterator r = rep(v);
	list<int>::iterator r1 = rep(b);
	cout << *r << ' ' << *r1;
	system("pause");
}