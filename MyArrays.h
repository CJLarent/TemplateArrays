#pragma once

#include<cassert>
#include<iostream>
#include"BaseArray.h"
using namespace std;
template<class T>
class UnordredArray : public BaseArray<T> 

{
public:
	// inhertied costructor from BaseArray  of type T 
	UnordredArray(){}
	UnordredArray(int size, int GrowBy = 1) :

		BaseArray<T>(size, GrowBy) {
	};
	
		
	

	void Push(T item)
	{
		assert( UnordredArray::m_BaseArray != nullptr);
		bool doubles = false;
		for (int i = 0; i < UnordredArray::m_ItemNumber; i++)
		{


			if (item == UnordredArray::m_BaseArray[i])
			{
				doubles = true;
				cout << "Double found !!! " << item << endl;


			}
		}


		if (UnordredArray::m_ItemNumber >= UnordredArray::m_ItemNumber)
		{
			UnordredArray::Resize();

		}
		if (doubles == false)
		{
			UnordredArray::m_BaseArray[UnordredArray::m_ItemNumber] = item;
			UnordredArray::m_ItemNumber++;
		}


	
	}
	
	

		
	
	
	
	int LinerSearch(T item)
	{
		
		assert(UnordredArray::m_BaseArray != nullptr);

		for (int i = 0; i < UnordredArray::m_ItemNumber; i++)
		{
			if (UnordredArray::m_BaseArray[i] == item)// When array index is the same  as the item is found
			{
				cout << "ITEM FOUND !!!" << endl;
				return i;// then reurn the item index 
			}
			
			
				
			
			
		}
		cout << "ITEM NOT FOUND !!!" << endl;
		return -1; // if an item is not found retrun out of the funchion 
		
	}
	// Overload array[] to take in any item
	T& operator[](int index)
	{
		
		assert(UnordredArray::m_BaseArray != nullptr && index < UnordredArray::m_ItemNumber);
		// return the item ID
		return  UnordredArray::m_BaseArray[index];

	}
	
	void MargeSort( )
	{	
		
		assert(UnordredArray::m_BaseArray != nullptr);
		T* tempArray = new T[UnordredArray::m_ItemNumber];
		assert(tempArray != nullptr);
		MargeSort(tempArray, 0, UnordredArray::m_ItemNumber - 1);
		delete[]tempArray;
	}

private:

	void MargeSort(T* tempArray, int lowwerBound, int upperBound)// Big O = O(N logN)
	{
		

		// base case
		if (lowwerBound == upperBound)
		{
			//cout << "both values are poniting to one item" << endl;

			return;
		}
		int midPonit = (lowwerBound + upperBound) >> 1;
		
		MargeSort(tempArray, lowwerBound, midPonit);
		MargeSort(tempArray,  midPonit+ 1 ,upperBound);
	
		Marge(tempArray, lowwerBound, midPonit+1,upperBound );// recursve call 

	}
	void Marge(T* tempArray, int low, int  middle, int upper)
	{
		int pass = 0;

		cout <<"marge has started pass "<< pass << endl;
		int tempLow = low, tempMidponit = middle - 1;
		int index = 0;
		

		while (low<=tempMidponit&&middle<=upper)
		{
			if (UnordredArray::m_BaseArray[low] < UnordredArray::m_BaseArray[middle])// the middle becomes the new lowbound 
			{
				tempArray[index++] = UnordredArray::m_BaseArray[low++];// prefix notion used++ checkes before going though the array 
					
			}
			else
			{
				tempArray[index++] = UnordredArray::m_BaseArray[middle++];
			}
			
		while (low<=tempMidponit)
		{
			tempArray[index++] = UnordredArray::m_BaseArray[low++];
		}
		while (middle<=upper)
		{
			tempArray[index++] = UnordredArray::m_BaseArray[middle++];
		}
		for (int i = 0; i < upper - tempLow+ 1; i++)
		{
			UnordredArray::m_BaseArray[tempLow + i] = tempArray[i];
		}
		pass++;
		}
	}

	
	
	


	
};
template <class T>
class OderedArray : public BaseArray<T>
{
public:
	OderedArray() {}
	OderedArray(int size, int GrowBy = 1) :

		BaseArray<T>(size, GrowBy) {
};


	void Push( T item)
	{
		assert(OderedArray::m_BaseArray != nullptr);
		bool doubles = false;
		for (int i = 0; i < OderedArray::m_ItemNumber; i++)
		{


			if (item == OderedArray::m_BaseArray[i])
			{
				doubles = true;
				cout << "Double found !!! " << item << endl;


			}
		}


		if (OderedArray::m_ItemNumber >= OderedArray::m_ItemNumber)
		{
			OderedArray::Resize();

		}
		if (doubles == false)
		{
			OderedArray::m_BaseArray[OderedArray::m_ItemNumber] = item;
			OderedArray::m_ItemNumber++;
		}
	}
	T& operator[](int index)
	{

		assert(OderedArray::m_BaseArray != nullptr && index < OderedArray::m_ItemNumber);
		// return the item ID
		return  OderedArray::m_BaseArray[index];

	}

		int LinerSearch(T item)
		{

			assert(UnordredArray::m_BaseArray != nullptr);

			for (int i = 0; i < UnordredArray::m_ItemNumber; i++)
			{
				if (UnordredArray::m_BaseArray[i] == item)// When array index is the same  as the item is found
				{
					cout << "ITEM FOUND !!!" << endl;
					return i;// then reurn the item index 
				}


			}
			cout << "ITEM NOT FOUND !!!" << endl;
			return -1; // if an item is not found retrun out of the funchion 

		}
		
	

		void MargeSort()
		{

			assert(OderedArray::m_BaseArray != nullptr);
			T* tempArray = new T[OderedArray::m_ItemNumber];
			assert(tempArray != nullptr);
			MargeSort(tempArray, 0, OderedArray::m_ItemNumber - 1);
			delete[]tempArray;
		}
		
	
private:
	void MargeSort(T* tempArray, int lowwerBound, int upperBound)// Big O = O(N logN)
	{


		// base case
		if (lowwerBound == upperBound)
		{
			//cout << "both values are poniting to one item" << endl;

			return;
		}
		int midPonit = (lowwerBound + upperBound) >> 1;

		MargeSort(tempArray, lowwerBound, midPonit);
		MargeSort(tempArray, midPonit + 1, upperBound);

		Marge(tempArray, lowwerBound, midPonit + 1, upperBound);// recursve call 

	}
	
	void Marge(T* tempArray, int low, int  middle, int upper)
	{
		int pass = 0;

		cout << "marge has started pass " << pass << endl;
		int tempLow = low, tempMidponit = middle -1;
		int index = 0;


		while (low <= tempMidponit && middle <= upper)
		{
			if (OderedArray::m_BaseArray[low] < OderedArray::m_BaseArray[middle])// the middle becomes the new lowbound 
			{
				tempArray[index++] = OderedArray::m_BaseArray[low++];// prefix notion used++ checkes before going though the array 

			}
			else
			{
				tempArray[index++] = OderedArray::m_BaseArray[middle++];
			}

			while (low <= tempMidponit)
			{
				tempArray[index++] = OderedArray::m_BaseArray[low++];
			}
			while (middle <= upper)
			{
				tempArray[index++] = OderedArray::m_BaseArray[middle++];
			}
			for (int i = 0; i < upper - tempLow + 1; i++)
			{
				OderedArray::m_BaseArray[tempLow + i] = tempArray[i];
			}
		
		}
	}
	
};