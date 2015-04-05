#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
using namespace std;

template<class T> class Transport
{
public:
	class trans
	{
	private:
		T num;
		string tipe;
	public:
		trans(T n, string t)
		{
			num = n;
			tipe = t;
		}
		pair<T, string> operator * ()
		{
			return pair<T, string>(num, tipe);
		}
		friend bool operator == (const trans&a, const trans&d);
		friend bool operator< (list<trans>::iterator const &a, list<trans>::iterator const &b);
	};

	
	
private:
	map<string, set<list<trans>::iterator>> Stops; // iterator void operator++()?
	list<trans> Trans;
	list<trans>::iterator finding(trans it)
	{
		list<trans>::iterator i;
		for (i = Trans.begin(); i != Trans.end(); ++i)
		{
			if (it == *(i)) return i;
		}
		return i;
	}


public:
	class iterator
	{
		map<string, set<list<Transport::trans>::iterator>>::iterator it;
		map<string, set<list<Transport::trans>::iterator>>::iterator end;
	public:

		iterator(map<string, set<list<Transport::trans>::iterator>>::iterator n, map<string, set<list<Transport::trans>::iterator>>::iterator e)
		{
			it = n;
			end = e;
		}
		void operator++ ()
		{
			if (it != end) ++it;
			while (it != end && it->second.size()!=0) ++it;// Stops.end()? no static doesn't work
		}
		bool operator== (iterator&b)
		{
			return it == b.it;
		}
		bool operator!= (iterator&b)
		{
			return it != b.it;
		}
		string operator*()
		{
			return it->first;
		}
	};


	//1
	void newTrans(T n, string t, pair<list<string>::iterator, list<string>::iterator> l)
	{
		trans newT(n, t);
		Trans.push_back(newT);
		for (list<string>::iterator i = l.first; i != l.second;	++i)
		{
			map<string, set<list<trans>::iterator>>::iterator it = Stops.find(*i);
			if (it != Stops.end())
			{
				it->second.insert(--Trans.end());
			}
			else
			{
				pair<string, set <list<trans>::iterator>> ns;
				ns.first = (*i);
				auto tr = Stops.emplace(ns);
				tr.first->second.insert(--Trans.end());
			}
		}
	}
	//2
	void delTrans(T n, string t)
	{
		trans del(n, t);
		list<trans>::iterator d = finding(del);
		for (map<string, set<list<trans>::iterator>>::iterator i = Stops.begin(); i != Stops.end(); ++i)
		{
			set<list<trans>::iterator>::iterator it = i->second.find(d);
			//while (it != i->second.end())
			if (it != i->second.end())
			{
				i->second.erase(it);
				//it = i->second.find(d);
			}
		}
		Trans.erase(d);
	}
	//3
	void newStop(string s)
	{
		pair < string, set<list<trans>::iterator>> n;
		n.first = s;
		Stops.insert(n);
	}
	//4
	void delStop(string s)//доделать
	{
		map<string, set<list<trans>::iterator>>::iterator del = Stops.find(s);
		bool *m;
		m = new bool[del->second.size()];
		for (int i = 0; i < del->second.size(); i++) m[i] = 0;
		for (map<string, set<list<trans>::iterator>>::iterator i = Stops.begin(); i != Stops.end(); ++i)
		{
			int k = 0;
			for (set<list<trans>::iterator>::iterator j = del->second.begin(); j != del->second.end(); ++j, k++)
			{
				if (!m[k])
					if (i->second.find(*j) != i->second.end())
						m[k] = true;
			}
		}

		int k = 0;
		for (set<list<trans>::iterator>::iterator j = del->second.begin(); j != del->second.end(); ++j, k++)
		{
			if (!m[k])
				Trans.erase(find(Trans.begin(), Trans.end(), **j));
				
		}

	}
	//5
	int numStop()
	{
		return Stops.size();
	}
	//6
	int numTrans()
	{
		return Trans.size(); 
	}
	//7
	pair<set<list<trans>::iterator>::iterator, set<list<trans>::iterator>::iterator> TransSrop(string s)
	{
		return pair<set<list<trans>::iterator>::iterator, set<list<trans>::iterator>::iterator>(Stops.find(s)->second.begin(), Stops.find(s)->second.end());
	}

	//8
	pair<list<trans>::iterator, list<trans>::iterator> TransXY(string t, T x, T y)
	{
		trans tx(t, x), ty(t, y);
		return pair<list<trans>::iterator, list<trans>::iterator>(finding(tx), (++finding(ty)));
	}

	//9
	pair<iterator, iterator> noTrans()
	{
		map<string, set<list<trans>::iterator>>::iterator bg;
		bg = Stops.end();
		for (map<string, set<list<trans>::iterator>>::iterator i = Stops.begin(); i != Stops.end() && bg == Stops.end(); ++i)
		{
			if (i->second.size() == 0) bg = i;
		}
		iterator i(bg, Stops.end()), e(Stops.end(), Stops.end());
		return pair<iterator, iterator>(i,e);
	}
	//10
	string maxTr()
	{
		
		map<string, set<list<trans>::iterator>>::iterator it = Stops.begin();
		int lmax = it->second.size();
		for (map<string, set<list<trans>::iterator>>::iterator j = Stops.begin(); j != Stops.end(); ++j)
		{
			int n = j->second.size();
			if (n > lmax)
			{
				it = j;
				lmax = n;
			}
		}
		return it->first;
	}


};

template<class T>
bool operator< (list<Transport<T>::trans>::iterator const &a, list<Transport<T>::trans>::iterator const &b)
{
	if ((*a).tipe == (*b).tipe)
		return (*a).num < (*b).num;
	return (*a).tipe < (*b).tipe;
}

template<class T>
bool operator == (const Transport<T>::trans&a, const Transport<T>::trans&d)
{
	return d.num == a.num && d.tipe == a.tipe;
}


