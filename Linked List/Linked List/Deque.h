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

private:
	LinkedList<T> m_Data;
};
