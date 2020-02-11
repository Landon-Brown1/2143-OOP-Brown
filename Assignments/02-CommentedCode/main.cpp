 /***************************************************************************                   
 * Author:           LANDON BROWN						                    *
 * Email:            LANDONBROWN.COLLEGE@GMAIL.COM			                *
 * Label:            ASSIGNMENT 02   					                    *
 * Title:            COMMENTING C++ CODE 					                *
 * Course:           2143-OBJECT-ORIENTED-PROGRAMMING			            *
 * Semester:         SPRING 2020						                    *
 *									                                        *
 * Description:								                                *
 *       refresh on good comments in code 				                    *
 *									                                        *
 * Usage:								                                    *
 *        N/A                               				                *
 *									                                        *
 * Files:            main.cpp	                                            *
 ***************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int A[100];

//node structure to hold data for our class object
struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

//class object to make a doubly linked list of nodes
class List
{
  private:
    Node *Head;
    Node *Tail;
    int Size;

  public:
//default (empty) constructor
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

/*************************************************************
 * DESCRIPTION: push a new value on to the list              *
 * RETURN: none                                              *
 * PRECONDITION: a list exists                               *
 * POSTCONDITION: the list has one more node added on to it  *
 ************************************************************/
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

/*********************************************************************
 * DESCRIPTION: push a new node to a specific spot in a list         *
 * RETURN: none                                                      *
 * PRECONDITION: a list exists                                       *
 * POSTCONDITION: a new node is added to the list in the right place *
 ********************************************************************/
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

/*************************************************************
 * DESCRIPTION: print the last data in the list              *
 * RETURN: none                                              *
 * PRECONDITION: a list exists                               *
 * POSTCONDITION: the tail is printed out if it has a value  *
 ************************************************************/
    void PrintTail()
    {
        if(Tail)
        cout << Tail->x << endl;
    }

/*************************************************************************
 * DESCRIPTION: print the list of items with arrows                      *
 * RETURN: string                                                        *
 * PRECONDITION: a list exists                                           *
 * POSTCONDITION: the list is printed out with arrows if it has values   *
 ************************************************************************/
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

/**************************************************************
 * DESCRIPTION: pop a value from the list                     *
 * RETURN: int                                                *
 * PRECONDITION: a list exists                                *
 * POSTCONDITION: an item is popped from the list and returned*
 *************************************************************/
    // not implemented 
    int Pop()
    {
        Size--;
        return 0; 
    }

/****************************************************************
 * DESCRIPTION: overloaded addition operator                    *
 * RETURN: List                                                 *
 * PRECONDITION: a list exists                                  *
 * POSTCONDITION: the list's contents are added to another list *
 ***************************************************************/
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

/*************************************************************
 * DESCRIPTION: overloaded bracket operator                  *
 * RETURN: int                                               *
 * PRECONDITION: a list exists                               *
 * POSTCONDITION: a value in (index) position is returned    *
 *      if it is in the bounds of the array                  *
 ************************************************************/
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

/*************************************************************
 * DESCRIPTION: [FRIEND] overloaded ostream operator         *
 * RETURN: ostream&                                          *
 * PRECONDITION: a list exists                               *
 * POSTCONDITION: the list is printed out (if it has values) *
 *      using this format "ostream << List"                  *
 ************************************************************/
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;
    List L2;

//push values from 1-24 to L1
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }

//push values from 50-99 to L2
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

//print both lists
    L1.PrintTail();
    L2.PrintTail();

//add them and print the new list
    List L3 = L1 + L2;
    cout << L3 << endl;

//print index 5 of the new list
    cout << L3[5] << endl;
    return 0;
}
