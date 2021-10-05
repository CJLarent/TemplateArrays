#pragma once

#include<cassert>
#include<iostream>

using namespace std;
template<class T>
class UnordredArray 

{
public:
	 UnordredArray(int size, int GrowBy = 1) :
		m_BaseArray(NULL), m_MaxSize(0), m_Grow(0), m_ItemNumber(0)
	{
		if (size)
		{
			m_MaxSize = size;
			m_BaseArray = new T[m_MaxSize];// changeing the size during run time 
			memset(m_BaseArray,0,sizeof(T)*m_MaxSize);// saving a spot of memory for the array
			m_Grow=((GrowBy > 0) ? GrowBy : 0);// using a bitwise if statment 

		}
	}
	~UnordredArray()
	{// array clean up
		if (m_BaseArray != nullptr)
		{
			delete[]m_BaseArray;
			m_BaseArray = nullptr;
		}
		
	}
	
		void Push(T item)
		{
			assert(m_BaseArray != nullptr);
			bool doubles = false;
			for (int i = 0; i < m_ItemNumber;i++)
			{
				
				
				if (item == m_BaseArray[i])
				{
					doubles = true;
					cout << "Double found !!! " << item << endl;
					
				
				}
			}
			
			
			if (m_ItemNumber >= m_MaxSize)
			{
				Resize();

			}
			if (doubles == false)
			{
				m_BaseArray[m_ItemNumber] = item;
				m_ItemNumber++;
			}
			

		}
	
	
	void Pop()
	{
		if (m_ItemNumber > 0)
			m_ItemNumber--;
	}
	void Delete(int index)
	{
		assert(m_BaseArray != nullptr);

		for (int i = index; i < m_ItemNumber; i++)
		{
			// Burat force 
			if (i + 1 < m_ItemNumber)
			{
				m_BaseArray[i] = m_BaseArray[i + 1];
			}
		}
		m_ItemNumber--;
	}
	int LinerSearch(T item)
	{
		
		assert(m_BaseArray != nullptr);

		for (int i = 0; i < m_ItemNumber; i++)
		{
			if (m_BaseArray[i] == item)// When array index is the same  as the item is found
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
		assert(m_BaseArray != nullptr && index < m_ItemNumber);
		// return the item ID
		return m_BaseArray[index];

	}
	void Clear()
	{
		m_ItemNumber = 0;
	}
	int GetSize() { return m_ItemNumber; }
	int GetGrowSize() { return m_Grow; }
	int GetMax() { return m_MaxSize; }

	int SetSize(int item)
	{
		assert(item >= 0);
		m_Grow = item;

	}
	void MargeSort( )
	{	
		
		assert(m_BaseArray != nullptr);
		T* tempArray = new T[m_ItemNumber];
		assert(tempArray != nullptr);
		MargeSort(tempArray, 0, m_ItemNumber - 1);
		delete[]tempArray;
	}

private:

	bool Resize()
	{
		if (m_Grow <= 0)
		{
			cout << "less then zero ! ! !" << endl;
			return false;
		}
		T* temp = new T[m_MaxSize + m_Grow];
		assert(temp != nullptr);

		// copying over to the same place in memory
		memcpy(temp, m_BaseArray, sizeof(T) * m_MaxSize);

		// clean up 
		delete[]m_BaseArray;
		// then asign temp 
		temp = nullptr;

		m_MaxSize += m_Grow;
		return true;

	}
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
		cout <<"marge has started" << endl;
		int tempLow = low, tempMidponit = middle - 1;
		int index = 0;

		while (low<=tempMidponit&&middle<=upper)
		{
			if (m_BaseArray[low] < m_BaseArray[middle])// the middle becomes the new lowbound 
			{
				tempArray[index++] = m_BaseArray[low++];// prefix notion used++ checkes before going though the array 
					
			}
			else
			{
				tempArray[index++] = m_BaseArray[middle++];
			}
		}
		while (low<=tempMidponit)
		{
			tempArray[index++] = m_BaseArray[low++];
		}
		while (middle<=upper)
		{
			tempArray[index++] = m_BaseArray[middle++];
		}
		for (int i = 0; i < upper - tempLow+ 1; i++)
		{
			m_BaseArray[tempLow + i] = tempArray[i];
		}
	}
	
private:
	
	
	
	
	T* m_BaseArray;
	int m_MaxSize;
	int m_Grow;
	int m_ItemNumber;

	
};