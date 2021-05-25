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
	
	//std::cout << List.GetCount() << std::endl;

	//List.Remove(5);

	//std::cout << List.GetCount() << std::endl;

	//List.Insert(6, 10);

	//std::cout << List.GetCount() << std::endl;

	//List.RemoveStart();

	//std::cout << List.GetCount() << std::endl;

	//List.InsertStart(4);

	//std::cout << List.GetCount() << std::endl;

	//List.InsertEnd(7);

	//std::cout << List.GetCount() << std::endl;

	List.GetCount();

	std::cout << "Count is: " << List.GetCount() << std::endl;

	List.GetFirstNode();

	std::cout << "First Node is: " << List.GetFirstNode()->m_Data << std::endl;

	List.GetLastNode();

	std::cout << "Last Node is: " << List.GetLastNode()->m_Data << std::endl;

	//List.Print();
	return 0;
}