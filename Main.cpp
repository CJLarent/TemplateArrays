#include<iostream>
#include"MyArrays.h"

using namespace std;

int main()
{

	UnordredArray<int>arrayC(4);
	UnordredArray<char>Barray(4);
	
	const char * message = "NOT VALID PUSH !!!";

	arrayC.Push(12);
	arrayC.Push(8);
	arrayC.Push(3);
	arrayC.Push(7);


	for (int i = 0; i< arrayC.GetSize(); i++)
	 {
		cout << arrayC[i] << " Item" << endl;
	}

	arrayC.MargeSort();

	for (int i = 0; i < arrayC.GetSize(); i++)
	{
		cout << arrayC[i] << " Item" << endl;
	}
	cout << endl;

	Barray.Push('V');
	Barray.Push('C');
	Barray.Push('u');
	Barray.Push('b');
	Barray.Push('i');


	for (int i = 0; i < Barray.GetSize(); i++)
	{
		cout << Barray[i] << " Latter" << endl;
	}
	Barray.MargeSort();
	for (int i = 0; i < Barray.GetSize(); i++)
	{
		cout << Barray[i] << " Latter" << endl;
	}

	
	OderedArray<double>Carray(5);

	Carray.Push(1.35);
	Carray.Push(4.46);
	Carray.Push(7.15);
	Carray.Push(6.22);
	Carray.Push(9.67);
	for (int i = 0; i < Carray.GetSize(); i++)
	{
		cout << Carray[i] << " Item" << endl;
	}
	Carray.MargeSort();

	for (int i = 0; i < Carray.GetSize(); i++)
	{
		cout << Carray[i] << " Item" << endl;
	}

	return 0;
}