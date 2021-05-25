#include <iostream>
#include <vector>
#include "LinkedLists.h"

int main()
{
	LinkedList<int> List;
	List.AddBack(2);
	List.AddBack(5);
	List.AddBack(6);
	List.AddBack(8);
	

	List.Remove(5);


	List.Insert(6, 10);


	List.RemoveStart();


	List.InsertStart(4);


	List.InsertEnd(7);


	List.GetCount();

	std::cout << "Count is: " << List.GetCount() << std::endl;

	if (List.Empty())
	{
		std::cout << "Empty" << std::endl;
	}
	else
	{
		std::cout << "Not empty" << std::endl;
	}

	List.GetFirstNode();

	std::cout << "First Node is: " << List.GetFirstNode()->m_Data << std::endl;

	List.GetLastNode();

	std::cout << "Last Node is: " << List.GetLastNode()->m_Data << std::endl;

	//List.Print();
	return 0;
}