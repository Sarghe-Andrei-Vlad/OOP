#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
//exercitiul 3
class MyVector
{
	int tablou[100];
	int size = 0;
public:
	bool Add(int x)
	{
		tablou[size] = x;
		if (tablou[size] == x)
		{
			size++;
			return true;
		}
	}
	bool Delete(int index)
	{
		int i;
		for (i = index; i < size - 1; i++)
		{
			tablou[i] = tablou[i + 1];
		}
		if (tablou[i + 1] == tablou[size])
		{
			size--;
			return true;
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
			cout << tablou[i] << " ";
		cout << endl;
	}
	void Iterate(void (*change)(int& tablou))
	{
		for (int i = 0; i < size; i++)
		{
			change(tablou[i]);
		}
	}
	void Filter(bool(*elim)(int& tablou))
	{
		for (int i = 0; i < size; i++)
		{
			if (elim(tablou[i]) == true)
				Delete(i);
		}
	}
};
int main()
{
	//exercitiul 1
	vector<string> v = { "abe","abc","acce","a" };
	sort(v.begin(), v.end(), [](string a, string b) -> bool { return a < b; });
	//sort(primul,ultimul, functia lambda)
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	//exercitiul 2
	list<int> array = { 1, 5, 6, 13, 2 };
	auto maxim = [](list<int> lista) {
		int max = -999;
		for (auto it = lista.begin(); it != lista.end(); ++it)
		{
			if (*it >= max)
			{
				max = *it;
			}
		}
		return max;
	};
	cout << maxim(array) << '\n';
	//exercitiul 3
	MyVector nums;
	nums.Add(3);
	nums.Add(5);
	nums.Add(1);
	nums.Add(15);
	nums.Add(14);
	nums.Print();
	nums.Delete(3);
	nums.Print();
	nums.Iterate([](int& nums) {nums = nums * 3; });
	nums.Print();
	nums.Filter([](int& nums) {if (nums % 2 == 0) return true; });
	nums.Print();
}