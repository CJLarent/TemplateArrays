#include<iostream>
#include"MyArrays.h"

using namespace std;

int main()
{
	
	//UnordredArray<int>arrayC(6);
	UnordredArray<char>Barray(4);
	UnordredArray<int>arrayC(3);
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
	
	


	return 0;
}