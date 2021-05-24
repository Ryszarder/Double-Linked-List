#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T m_data;
		Node* m_pNext;
		Node* m_Prev;
	};

	LinkedList()
	{
		m_pStart = new Node();
		m_pEnd = new Node();

		m_pStart->m_pNext = m_pEnd;
		m_pStart->m_Prev = nullptr;
		
		m_pEnd->m_pNext = nullptr;
		m_pEnd->m_Prev = m_pStart;

		int count = 0;
	}

	~LinkedList()
	{
		delete m_pStart;
		delete m_pEnd;
	}

	void AddBack(T value)
	{
		Node* pNewNode = new Node();
		pNewNode->m_data = value;

		pNewNode->m_pNext = m_pEnd;
		pNewNode->m_Prev = m_pEnd->m_Prev;
		m_pEnd->m_Prev->m_pNext = pNewNode;
		m_pEnd->m_Prev = pNewNode;
	}

	void Insert(T search, T value)
	{
		Node* itter = Find(search);

		Node* pNewNode = new Node();
		pNewNode->m_data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;
		itter->m_pNect->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;
	}

	void Remove(T value)
	{
		Node* pNodeToRemove = Find(value);

		Node* pPrev = pNodeToRemove->m_pPrev;
		Node* pNext = pNodeToRemove->m_pNext;
		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeToRemove;
	}

	void RemoveAt(int nIndex)
	{

	}

	Node* Find(T value)
	{
		Node* pCurrent = m_pStart->m_pNext;
		while (pCurrent != m_pEnd)
		{
			if (pCurrent->m_data == value)
			{
				return pCurrent;
			}

			pCurrent = pCurrent->m_pNext;
		}
		return nullptr;
	}

private:
	Node* m_pStart;
	Node* m_pEnd;

	int count;
};
