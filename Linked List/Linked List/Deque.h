#pragma once
#include "LinkedLists.h"
template <typename T>
class Deque
{
public:
	Deque()
	{
	}

	~Deque()
	{
	}

	void PushFront(T value)
	{
		m_Data.InsertStart(value);
	}

	void PushBack(T value)
	{
		m_Data.InsertEnd(value);
	}

	T PopFront()
	{
		T value = m_Data.GetFirstNode()->m_Data;
		m_Data.RemoveStart();

		return value;
	}

	T PopBack()
	{
		T value = m_Data.GetLastNode()->m_Data;
		m_Data.RemoveEnd();

		return value;
	}

	int Count()
	{
		return m_Data.GetCount();
	}

	bool Empty()
	{
		return (m_Data.GetCount() == 0);
	}

private:
	LinkedList<T> m_Data;
};
