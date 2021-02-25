#include "NumberList.h"

int main()
{
	NumberList L;
	L.Init();
	L.Add(1);
	L.Add(3);
	L.Add(17);
	L.Add(3);
	L.Add(3);
	L.Add(12);
	L.Add(3);
	L.Add(2);
	L.RemoveNumber(3);
	L.Sort();
	L.Insert(1, 3);
	L.Print();
	return 0;
}