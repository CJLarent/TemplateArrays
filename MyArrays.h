#pragma once
#pragma once
#include<cassert>

template <class T>
class UnordredArray
{
	UnordredArray(int size, int GrowBy = 1);
	m_BaseArray(NULL), m_MaxSize(0);
	m_Grow(0), m_ItemNumber;
	if (size)
	{
		m_MaxSize = size;
		m_BaseArray = new T[m_MaxSize]; // Changing array size during run time 
		m_Grow = (GrowBy > 0) ? GrowBy : 0 );// using bitwise or to check the size is greater than zero
	}

	~UnordredArray() // array cleanup 
	{
		if (m_BaseArray != NULL)
			delete[] = m_BaseArray;
		m_BaseArray = NULL;
	}

private:
	// funcions local to the class 
	int GetSize(return m_ItemNumber;)
		int GetMaxSize(return m_MaxSize;)
		int GetGrowSize(return m_Grow;)
		void SetGrowSize(int value)
	{
		assert[value] >= 0;
		m_Grow = value;
	}
	T* m_BaseArray;
	int m_MaxSize;
	int m_Grow;
	int m_ItemNumber;
};