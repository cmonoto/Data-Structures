//Jinhao Chen
//
#include "List.h"
#include <iostream>

using namespace std;

extern void Init_Storage_Pool();

int main()
{

	Init_Storage_Pool();


	List L;
	// the following is for insert all 10 elements for node list
	L.insert(5, 0);
	L.insert(3, 1);
	L.insert(9, 2);
	L.insert(4, 3);
	L.insert(1, 4);
	L.insert(3, 5);
	L.insert(6, 6);
	L.insert(8, 7);
	L.insert(9, 8);
	L.insert(2, 9); 
	
	L.display(cout);
	
	L.erase(0); // earase the first position of list, get new list which is start from the second element
	L.erase(3); // earase the third position of list
   L.replace(10, 0); // replace the current list first element


	L.display(cout);
	cin.ignore();


	return 0;
	cin.ignore();
	cin.ignore();
}
