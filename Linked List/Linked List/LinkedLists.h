#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T m_data;
		Node* m_pNext;
		Node* m_pPrev;
	};

	LinkedList()
	{
		m_pStart = new Node();
		m_pEnd = new Node();

		m_pStart->m_pNext = m_pEnd;
		m_pStart->m_pPrev = nullptr;
		
		m_pEnd->m_pNext = nullptr;
		m_pEnd->m_pPrev = m_pStart;

		count = 0;
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
		pNewNode->m_pPrev = m_pEnd->m_pPrev;
		m_pEnd->m_pPrev->m_pNext = pNewNode;
		m_pEnd->m_pPrev = pNewNode;
		count++;
	}

	void Insert(T search, T value)
	{
		Node* itter = Find(search);

		Node* pNewNode = new Node();
		pNewNode->m_data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;
		itter->m_pNext->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;

		count++;
	}

	void InsertStart(T value)
	{

	}

	void InsertEnd(T value)
	{

	}

	void Remove(T value)
	{
		Node* pNodeToRemove = Find(value);

		Node* pPrev = pNodeToRemove->m_pPrev;
		Node* pNext = pNodeToRemove->m_pNext;
		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeToRemove;

		--count;
	}

	void RemoveStart()
	{
		Node* pNodeStart = m_pStart->m_pNext;

		Node* pPrev = pNodeStart->m_pPrev;
		Node* pNext = pNodeStart->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeStart;

		--count;
	}

	void RemoveEnd()
	{
		Node* pNodeEnd = m_pEnd->m_pPrev;

		Node* pPrev = pNodeEnd->m_pPrev;
		Node* pNext = pNodeEnd->m_pNext;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;

		delete pNodeEnd;

		--count;
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

	int GetCount()
	{
		return count;
	}

	void Print()
	{
		Node* n = m_pStart->m_pNext;
		while (n != m_pEnd)
		{
			std::cout << (n->m_data) << std::endl;
			n = n->m_pNext;
		}
	}

private:
	Node* m_pStart;
	Node* m_pEnd;

	int count;
};
