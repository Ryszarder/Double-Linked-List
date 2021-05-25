#include <iostream>
#include <vector>
#include "LinkedLists.h"
#include "DynamicArray.h"
#include "Stack.h"
#include "Deque.h"

int main()
{
	/*LinkedList<int> List;
	List.AddBack(2);
	List.AddBack(5);
	List.AddBack(6);
	List.AddBack(8);
	List.AddBack(3);
	List.AddBack(9);
	List.AddBack(4);

	List.Remove(5);

	List.RemoveStart();

	List.RemoveEnd();

	List.Insert(6, 10);

	List.InsertStart(4);

	List.InsertEnd(7);

	List.GetCount();
	std::cout << "Count is: " << List.GetCount() << std::endl;

	if (List.Empty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "Not empty" << std::endl;

	List.GetFirstNode();
	std::cout << "First Node is: " << List.GetFirstNode()->m_Data << std::endl;

	List.GetLastNode();
	std::cout << "Last Node is: " << List.GetLastNode()->m_Data << std::endl;

	List.Print();*/

	/*DynamicArray<int> myArray(3);
	myArray.Add(5);
	myArray.Add(2);
	myArray.Add(1);
	myArray.Add(6);
	myArray.Add(7);
	myArray.Add(4);
	myArray.Add(10);

	myArray.Remove(4);

	for (int i = 0; i < myArray.GetSize(); i++)
	{
		std::cout << myArray[i] << std::endl;
	}*/

	Stack<int> myStack;

	myStack.Push(5);
	myStack.Push(8);
	myStack.Push(10);
	myStack.Push(2);
	myStack.Push(15);

	/*while (!myStack.Empty())
	{
		int m_nStackArray = myStack.Pop();
		std::cout << "Push: " << m_nStackArray << std::endl;
	}*/

	return 0;
}