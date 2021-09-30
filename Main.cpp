#include<iostream>
#include"MyArrays.h"
using namespace std;

int main()
{
	const char * message = "NOT VALID PUSH!";
	UnordredArray<int>arrayA(4);
	UnordredArray<char>ArrayB(64);
	arrayA.Push(10);
	arrayA.Push(19);
	ArrayB.Push('V');
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

	cout << "Latters in the array" << endl;

	for (int i = 0; i < ArrayB.GetSize(); i++)
	{
		cout << ArrayB[i] << "Item" << endl;
	}
	cout << endl;
	

	cout << arrayA.LinerSearch(19) << endl;
	cout << arrayA.LinerSearch(9) << endl;
	// Exception Handling
	try {
		arrayA.Push('C');
		ArrayB.Push('V');
		throw 'C','V';
	}
	catch ( ...) {
		cerr << message << endl;

	}
	return 0;
}