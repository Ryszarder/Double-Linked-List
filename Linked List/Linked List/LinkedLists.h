#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T m_Data;
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
		pNewNode->m_Data = value;

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
		pNewNode->m_Data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;
		itter->m_pNext->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;

		count++;
	}

	void InsertStart(T value)
	{
		Node* itter = m_pStart;

		Node* pNewNode = new Node();
		pNewNode->m_Data = value;

		pNewNode->m_pNext = itter->m_pNext;
		pNewNode->m_pPrev = itter;
		itter->m_pNext->m_pPrev = pNewNode;
		itter->m_pNext = pNewNode;

		count++;
	}

	void InsertEnd(T value)
	{
		Node* itter = m_pEnd;

		Node* pNewNode = new Node();
		pNewNode->m_Data = value;

		pNewNode->m_pPrev = itter->m_pPrev;
		pNewNode->m_pNext = itter;
		itter->m_pPrev->m_pNext = pNewNode;
		itter->m_pPrev = pNewNode;

		count++;
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
			if (pCurrent->m_Data == value)
			{
				return pCurrent;
			}

			pCurrent = pCurrent->m_pNext;
		}
		return nullptr;
	}

	Node* GetNode(int nIndex)
	{
		Node* pCurrent = m_pStart->m_pNext;
		for (int i = 0; i < nIndex; i++)
		{
			if (i == nIndex)
				return pCurrent;

			pCurrent = pCurrent->m_pNext;
		}

		return pCurrent;
	}

	int GetCount()
	{
		return count;
	}

	bool Empty()
	{
		return (count == 0);
	}

	Node* GetFirstNode()
	{
		return m_pStart->m_pNext;
	}
	
	Node* GetLastNode()
	{
		return m_pEnd->m_pPrev;
	}

	void Print()
	{
		Node* n = m_pStart->m_pNext;
		while (n != m_pEnd)
		{
			std::cout << (n->m_Data) << std::endl;
			n = n->m_pNext;
		}
	}

	void Swap(Node* B, Node* C)
	{
		//A -> B -> C -> D
		Node* A = B->m_pPrev;
		Node* D = C->m_pNext;

		A->m_pNext = C;
		C->m_pPrev = A;

		C->m_pNext = B;
		B->m_pPrev = C;

		B->m_pNext = D;
		D->m_pPrev = B;
	}

	void Sort(int count)
	{
		Node* key;
		Node* comp;
		int j;

		for (int i = 1; i < count; ++i)
		{
			key = GetNode(i);
			j = i - 1;
			comp = GetNode(j);
			while (j >= 0 && key->m_Data < comp->m_Data)
			{
				Swap(GetNode(j), GetNode(j + 1));
				j = j - 1;
				comp = GetNode(j);
			}
		}
	}

private:
	Node* m_pStart;
	Node* m_pEnd;

	int count;
};
