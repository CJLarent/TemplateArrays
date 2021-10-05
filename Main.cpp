#include<iostream>
#include"MyArrays.h"

using namespace std;

int main()
{
	
	UnordredArray<int>Array(7);

	const char * message = "NOT VALID PUSH !!!";

	Array.Push(10);
	Array.Push(5);
	Array.Push(2);
	Array.Push(7);
	Array.Push(3);
	Array.Push(1);
	Array.Push(5);
	Array.Push(11);
	Array.Push(15);

	for (int i = 0; i< Array.GetSize(); i++)
	 {
		cout << Array[i] << " Item" << endl;
	}
	
	Array.MargeSort();

	for (int i = 0; i < Array.GetSize(); i++)
	{
		cout << Array[i] << " Item" << endl;
	}
	
	
	
	


	return 0;
}