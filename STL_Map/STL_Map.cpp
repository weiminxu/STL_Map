#include <iostream>
#include <map>

using namespace std;

int main()
{
	/*
		1)map, multipmap
		2)red-black tree
		3)insert 4 kinds of approaches
		4)count and find
		5)erase 3 kinds of approaches
	*/

	map<int, string> as;
	map<string, int> msi;
	multimap<int, string> mms;

	/*******************the first methond of insert**********************/
	as.insert(map<int, string>::value_type(1, "One"));
	as.insert(map<int, string>::value_type(2, "Two"));
	as.insert(map<int, string>::value_type(3, "Three"));
	msi.insert(map<string, int>::value_type("zhangsan", 60));
	msi.insert(map<string, int>::value_type("mazi", 70));
	msi.insert(map<string, int>::value_type("lisi", 80));
	msi.insert(map<string, int>::value_type("wanger", 90));

	/*******************the second methond of insert**********************/
	as.insert(pair<int, string>(1000, "One Thousand"));

	/*******************the third methond of insert**********************/
	as.insert(make_pair(-1, "Minus One"));

	/*******************the fourth  methond of insert**********************/
	as[1000000] = "One Million";

	cout << "the number of elements in map are: " << as.size() << endl;

	cout << "these elements are: ";
	map<int, string>::const_iterator ci;
	for (ci = as.begin(); ci != as.end(); ci++)
	{
		cout << "Key: " << ci->first << ", " << "Value: " << ci->second.c_str() << endl;
	}

	mms.insert(multimap<int, string>::value_type(4, "Four"));
	mms.insert(make_pair(5, "Five"));
	mms.insert(pair<int, string>(6, "Six"));
	mms.insert(pair<int, string>(6, "Six"));

	multimap<int, string>::const_iterator mmi;

	cout << endl << endl;
	cout << "the amout of elements in multipmap are: " << mms.size()<< endl;
	for (mmi=mms.begin(); mmi!=mms.end();mmi++)
	{
		cout << "Key: " << mmi->first << ", " <<"Value: "<< mmi->second.c_str() << endl;
	}

	//use find(key) to look for value in multiplemap
	multimap<int, string>::const_iterator mmiFind;
	mmiFind = mms.find(6);
	if (mmiFind != mms.end())
	{
		cout << "it was found!" <<endl;
		size_t n = mms.count(6);
	
		for (size_t i = 0; i < n; i++)
		{
			cout<<"the index is "<<"[ "<< i <<" ], " <<"Key: " << mmiFind->first << ", Value : " << mmiFind->second << endl;
		}
	}
	else
	{
		cout << "it was not found!" << endl;
	}

	//use as[key] to look for value in map

	cout << "the key 1 and the value is : "<< as[1] << endl;

	cout << "the student grade: " << msi["mazi"] << endl;

	//delete the item in map
	if (as.erase(1) > 0)
	{
		cout << endl << "it was deleted successfully" << endl;
	}
	else
	{
		cout << endl << "it was not deleted successfully" << endl;
	}

	//delete the item in multiple map
	multimap<int, string>::iterator misi;
	misi = mms.find(6);
	if (misi != mms.end())
	{
		mms.erase(misi);
		cout << "it was deleted successfully" << endl;
	}

	mmiFind = mms.find(6);
	if (mmiFind != mms.end())
	{
		cout << "it was found!" << endl;
		size_t n = mms.count(6);

		for (size_t i = 0; i < n; i++)
		{
			cout << "the index is " << "[ " << i << " ], " << "Key: " << mmiFind->first << ", Value : " << mmiFind->second << endl;
		}
	}
	else
	{
		cout << "it was not found!" << endl;
	}

	mms.erase(mms.lower_bound(6), mms.upper_bound(6));
	mmiFind = mms.find(6);
	if (mmiFind != mms.end())
	{
		cout << "it was found!" << endl;
		size_t n = mms.count(6);

		for (size_t i = 0; i < n; i++)
		{
			cout << "the index is " << "[ " << i << " ], " << "Key: " << mmiFind->first << ", Value : " << mmiFind->second << endl;
		}
	}
	else
	{
		cout << "it was not found!" << endl;
	}

	return 0;
}