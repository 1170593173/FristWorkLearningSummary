#include <iostream>
#include <map>
#include <set>
using namespace std;

struct myKey
{
	int nid;
	int nVersion;
	int nNote;
};

struct myValue
{
	string strText;
};

struct cmp_key
{
	bool operator()(const myKey &k1, const myKey &k2)const {
		if (k1.nid!=k2.nid)
		{
			return k1.nid < k2.nid;
		}
		if (k1.nNote!=k2.nNote)
		{
			return k1.nNote < k2.nNote;
		}
		if (k1.nVersion < k2.nVersion) {
			return k1.nVersion < k2.nVersion;
		}
		return false;
	}
};


struct testStrut
{
	int frist;
	int second;
};

struct mcmp
{
	bool operator() (const testStrut&k1 ,const testStrut&k2 ) {
		if (k1.frist!=k2.frist)
		{
			return k1.frist < k2.frist;
		}
		if (k1.second!=k2.second)
		{
			return k1.second < k2.second;
		}
		return false;
	}
};

/*¶Ômap½øÐÐÅÅÐò*/
int main() {
	std::map<myKey, myValue, cmp_key>mymap;
	myKey k1;
	k1.nid = 1;
	k1.nNote = 2;
	k1.nVersion = 3;
	myValue v1;
	v1.strText = "k1:id=1 version=2 note=3";

	myKey k2;
	k2.nid = 2;
	k2.nNote = 2;
	k2.nVersion = 3;
	myValue v2;
	v2.strText = "k2:id=2 version=2 note=3";

	myKey k3;
	k3.nid = 2;
	k3.nNote = 2;
	k3.nVersion = 5;
	myValue v3;
	v3.strText = "k3:id=2 version=2 note=5";

	mymap[k1] = v1;
	mymap[k3] = v3;
	mymap[k2] = v2;

	for (auto i = mymap.begin(); i != mymap.end();++i)
	{
		cout << i->second.strText.c_str() << endl;
	}

	set<myKey, cmp_key>m_set;
	m_set.insert(k2);
	m_set.insert(k3);
	m_set.insert(k1);
	for (auto it = m_set.begin(); it != m_set.end();++it)
	{
		cout << (*it).nid << (*it).nNote << (*it).nVersion<< endl;
	}


	testStrut kk1;
	kk1.frist = 2;
	kk1.second = 1;
	testStrut kk2;
	kk2.frist = 1;
	kk2.second = 2;

	set<testStrut,mcmp>m_test;

	m_test.insert(kk1);
	m_test.insert(kk2);


	return 0;
}