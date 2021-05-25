#pragma once
#include "DynamicArray.h"
template <typename T>
class Stack
{
public:
	Stack()
	{
	}

	~Stack()
	{
	}

	void Push(T value)
	{
		m_Data.Add(value);
	}

	T Pop()
	{
		T value = m_Data[m_Data.GetSize() - 1];
		m_Data.RemoveAt(m_Data.GetSize() - 1);

		return value;
	}

	T Top()
	{
		T value = m_Data[m_Data.GetSize() - 1];
		return value
	}

	int Size()
	{
		return m_Data.GetSize();
	}

private:
	DynmicArray<T> m_Data;
};