#include <iostream>
#include "Transport1.h"



int main()
{
	Transport<int> S;
	list<string> i;
	i.push_back("jlkashdkhs");
	i.push_back("jlkashdkhse");
	i.push_back("aklsdj");
	S.newTrans(35, "b", pair<list<string>::iterator, list<string>::iterator>(i.begin(), i.end()));
	i.pop_back();
	i.pop_front();
	S.newTrans(9, "b", pair<list<string>::iterator, list<string>::iterator>(i.begin(), i.end()));
	auto f = S.TransXY("b", 9, 35);
	while (f.first != f.second)
	{
		cout << (**(f.first)).first << (**(f.first)).second << ' ';
		++(f.first);
	}
	S.delStop("jlkashdkhse");
	cout << S.numStop() << ' ' << S.numTrans() << " " << S.maxTr()<<endl;
	S.newStop("aklsdjasd");
	cout << S.numStop() << ' ' << S.numTrans() << " " << S.maxTr() << endl;
	//S.delStop("aklsdj");
	//cout << S.numStop() << ' ' << S.numTrans() << " " << S.maxTr() << endl;
	S.delTrans(35, "b");
	cout << S.numStop() << ' ' << S.numTrans() << " " << S.maxTr()<<endl;
	auto s = S.noTrans();
	while (s.first != s.second)
	{
		cout << *(s.first) <<' ';
		++(s.first);
	}
	system("pause");
}
