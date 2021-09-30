#include<iostream>
#include"MyArrays.h"
using namespace std;

int main()
{
	UnordredArray<int>arrayA(4);
	arrayA.Push(10);
	arrayA.Push(19);
	arrayA.Push(3867);
	arrayA.Push(2);
	arrayA[2] = 6;
	arrayA.Pop();
	arrayA.Delete(2);

	cout << "items in the array"<<endl;
	
	for (int i = 0; i < arrayA.GetSize(); i++)
	{
		cout << arrayA[i] << "Item" << endl;
	}
	cout << endl;

	cout << arrayA.LinerSearch(19) << endl;
	cout << arrayA.LinerSearch(9) << endl;

	return 0;
}