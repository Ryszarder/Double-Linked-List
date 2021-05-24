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
	
	std::cout << List.GetCount() << std::endl;

	List.Remove(5);

	std::cout << List.GetCount() << std::endl;

	List.Insert(6, 10);

	std::cout << List.GetCount() << std::endl;

	List.Print();
	return 0;
}