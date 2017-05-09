//Jinhao Chen
//
#include "List.h"

const int NULL_VALUE = -1;
NodeType node[NUMNODES];
int freeptr;


// Any program that uses this module must execute
// the folloowing function before creating any Lists
void Init_Storage_Pool()
{
	freeptr = 0;
	// complete the code to make the free list
	// consist of all entries in the array in 
	// the normal sequential order
	node[freeptr].next = 1;
	node[1].next = 4;
	node[2].next = 5;
	node[3].next = 2;
	node[4].next = 3;
	node[5].next = 6;
	node[6].next = 8;
	node[7].next = 9;
	node[8].next = 7;
	node[9].next = NULL_VALUE;


}

int NewNode()
{
	// You provide the code for this function
	int free;
	free = freeptr;
	freeptr = node[freeptr].next;
	node[free].next = NULL_VALUE;
	return free;
}

void freeNode(int i)
{
	// You provide the code for this function
	
	node[i].next = freeptr;
	node[i].data = 0;
	freeptr = i;

}



// Place class implementation below

// definition of class constructor
List::List(){
	mySize = 0;
	first = NULL_VALUE;
}

// definition of empty()

bool List::empty() const{
	return mySize == 0;
}


// definition of display()
void List::display(ostream & out) const{

	cout << "List Size now is : " << mySize << "   the following 0 means no data "<< endl;
	cout << "           data       next" << endl;
	for (int i = 0; i < NUMNODES; i++){
		cout << "[" << i << "]         " << node[i].data << "         " << node[i].next << endl;
	}
}

// definition of insert()

void List::insert(ElementType item, int pos){
	if (mySize == NUMNODES)
	{
		cout << "*** NO space to insert element  ***" << endl;
		return;
	}
	if (pos < 0 || pos > mySize){
		cout << "*** Illegal Location to insert  position " << pos << " So List unchaged. ***" << endl;
		return;
	}
		if (empty())
		{
			 
			first = NewNode();
			node[first].next = NULL_VALUE;
			node[first].data = item;
			mySize++;
		}
		else if (pos == 0)
		{
			int in = NewNode();
			node[in].data = item;
			node[in].next = node[first].next;
			first = in;
			mySize++;
		}
		else if (pos == mySize)
		{
			int in = NewNode();
			node[in].next = NULL_VALUE;
			node[FindPred(pos)].next = in;
			node[FindByPos(pos)].data = item;
			mySize++;
		}
		else
		{
			int in = NewNode();
			node[in].next = node[FindPred(pos)].next;
			node[FindPred(pos)].next = in;
			node[FindByPos(pos)].data = item;
			mySize++;

		}

}

// definition of replace()

void List::replace(ElementType item, int pos){
	
	if (pos < 0 || pos >= mySize){
		cout << " Illegal location to replace  position " << pos << " so list unchanged " << endl;
		return;
	}
		node[FindByPos(pos)].data = item;
	
	
}

// definition of earse()

void List::erase(int pos){

	if (mySize == 0){
		cout << " *** List is empty *** you do not have any data to delete in position " << pos << endl;
		return;
	}
	if (pos < 0 || pos >= mySize){
		cout << " Illegal location to delete  position " << pos << "  so List unchanged. " << endl;
		return;
	}

	 if (pos == 0) {
			int tmp = node[FindByPos(pos)].next;
			freeNode(FindByPos(pos));
			first = tmp;
		}
		else if (pos == mySize) {
			node[FindPred(pos)].next = NULL_VALUE;
			freeNode(FindByPos(pos));
		}
		else {
			int tmp = node[FindByPos(pos)].next;
			freeNode(FindByPos(pos));
			node[FindPred(pos)].next = tmp;
		}
		mySize--;



}

// definition of FindPred() 

int List::FindPred(int pos){
	int Pre = first;
	int n = 0;
	while (node[Pre].next != NULL_VALUE && (n + 1) < pos) {
		Pre = node[Pre].next;
		n++;
	}
	return Pre;

}

// definition of FindBypos()

int List::FindByPos(int pos){
	int cur = first;
	int n = 0;
	while (node[cur].next != NULL_VALUE && n < pos){
		cur = node[cur].next;
		n++;
	}
	return cur;
}
//  definition of output operator
ostream & operator<< (ostream & out, const List & aList){
	aList.display(out);
	return out;
}

