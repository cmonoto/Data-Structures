/*-- List.h -------------------------------------------------------------
 
  This header file defines the data type List for processing lists.
  Basic operations are:
     Constructor
     empty:    Check if list is empty
     insert:   Insert an item
     erase:    Remove an item
     display:  Output the list
     <<, >> :  input and output operators
-----------------------------------------------------------------------*/

#include <iostream>

#ifndef __LIST
#define __LIST
using namespace std;
/*---------Storage Pool ----------------*/

const int NUMNODES = 10;
typedef int ElementType;

struct NodeType
{
  ElementType data;
  int next;
};

class List
{
 public:
 /******** Function Members ********/
   /***** Class constructor *****/
   List();
   /*------------------------------------------------------------------
     Construct a List object.

     Precondition:  None
     Postcondition: An empty List object has been constructed;
         mySize is 0.
   -------------------------------------------------------------------*/

   /***** empty operation *****/
   bool empty() const;
   /*------------------------------------------------------------------
     Check if a list is empty.

     Precondition:  None
     Postcondition: true is returned if the list is empty, 
         false if not.
   -------------------------------------------------------------------*/

   /***** insert, replace and erase *****/
   void insert(ElementType item, int pos);
   /*------------------------------------------------------------------
     Insert a value into the list at a given position.

     Precondition:  item is the value to be inserted; there is an available 
         node in the storage pool if (mySize < NUMNODES); and the position 
         satisfies 0 <= pos <= mySize. 
     Postcondition: item has been inserted into the list at the position
         determined by pos (provided there is room and pos is a legal
         position).
   -------------------------------------------------------------------*/

   void  replace(ElementType item, int pos);
   /*------------------------------------------------------------------
     Replace the value in the list at a given position with iten.

     Precondition:  the position 
         satisfies 0 <= pos < mySize. 
     Postcondition: The value in the node at position pos equals item
   -------------------------------------------------------------------*/

   void erase(int pos);
   /*------------------------------------------------------------------
     Remove a value from the list at a given position.

     Precondition:  The list is not empty and the position satisfies
         0 <= pos < mySize.
     Postcondition: element at the position determined by pos has been
         removed (provided pos is a legal position).
   ------------------------------------------------------------------*/


   /***** output *****/
   void display(ostream & out) const;
   /*------------------------------------------------------------------
     Display a list.

     Precondition:  out is a reference parameter 
     Postcondition: The list represented by this List object has been
         inserted into ostream out. 
   -------------------------------------------------------------------*/

 private:

   /******** Helper Functions ********/
   int FindPred(int pos);
   /*-------------------------------------------------------------------
    Returns the index in the storage pool of the predecessor of the node 
        with position pos in the list
   -------------------------------------------------------------------*/

   int FindByPos(int pos);
   /*-------------------------------------------------------------------
    Returns the index in the storage pool of the node with position pos 
        in the list
   -------------------------------------------------------------------*/

   /******** Data Members ********/
   int mySize; // current size of list
   int first;  // array to store list elements

}; //--- end of List class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);


#endif
