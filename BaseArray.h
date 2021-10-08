#pragma once
#include<iostream>
#include "BaseArray.h"
using namespace std;
template <class T>
class BaseArray
{
public:
	BaseArray(int size, int GrowBy = 1) :
		m_BaseArray(NULL), m_MaxSize(0), m_Grow(0), m_ItemNumber(0)
	{
		if (size)
		{
			m_MaxSize = size;
			m_BaseArray = new T[m_MaxSize];// changeing the size during run time 
			memset(m_BaseArray, 0, sizeof(T) * m_MaxSize);// saving a spot of memory for the array
			m_Grow = ((GrowBy > 0) ? GrowBy : 0);// using a bitwise if statment 

		}
	}
	~BaseArray()
	{// array clean up
		if (m_BaseArray != nullptr)
		{
			delete[]m_BaseArray;
			m_BaseArray = nullptr;
		}

	}
	
	void  Push(T item)
	{
		assert(m_BaseArray != nullptr);
		bool doubles = false;
		for (int i = 0; i < m_ItemNumber; i++)
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

	T& operator[](int index)
	{
		assert(m_BaseArray != nullptr && index < m_ItemNumber);
		// return the item ID
		return m_BaseArray[index];

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


	
	
	


protected:
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
		m_BaseArray = temp;
		// then asign temp 
		temp = nullptr;

		m_MaxSize += m_Grow;
		return true;

	}

protected:
	T* m_BaseArray;
	int m_MaxSize;
	int m_Grow;
	int m_ItemNumber;
	
	

};