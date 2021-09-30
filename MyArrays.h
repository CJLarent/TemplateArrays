#pragma once

#include<cassert>
#include<iostream>
using namespace std;
template<class T>
class UnordredArray

{
public:
	inline UnordredArray(int size, int GrowBy = 1) :
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
			if (m_ItemNumber >= m_MaxSize)
			{
				Resize();

			}
			m_BaseArray[m_ItemNumber] = item;
			m_ItemNumber++;

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
private:

	bool Resize()
	{
		if (m_Grow <= 0)// build a try and catch 
		{
			return false;
		}
		T* temp = new T[m_MaxSize + m_Grow];
		assert(temp != nullptr);

		// copying over to the same place in memory
		//memccpy(temp,m_BaseArray,sizeof(T)*m_MaxSize);

		// clean up 
		delete[]m_BaseArray;
		// then asign temp 
		temp = nullptr;

		m_MaxSize += m_Grow;
		return true;

	}

private:
	
	
	
	
	T* m_BaseArray;
	int m_MaxSize;
	int m_Grow;
	int m_ItemNumber;

	
};