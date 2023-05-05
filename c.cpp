/*

c)

Stack minimum- Details of stack data structure is available in https://www.geeksforgeeks.org/stack-data-structure/ Stack has functions of push and pop. 
Can you also add a function 'min' to the stack and it should also execute in O(1).
If you are not aware  of O(1), refer to some videos online. Eg https://en.wikipedia.org/wiki/Big O notation
Explain one real world use case where stack is better used data structure than arrays.

*/

#include <bits/stdc++.h>
using namespace std;

// creating a linked list;
class Node {
public:
 int data;
 Node* link;
 Node* minlink;

 // Constructor
 Node(int n)
 {
  this->data = n;
  this->link = NULL;
  this->minlink = NULL;
 }
};

class Stack {
 Node* top;
 Node *Min;

public:
 Stack() { top = NULL; Min = NULL;}

 void push(int data)
 {

  // Create new node temp and allocate memory in heap
  Node* temp = new Node(data);

  // Check if stack (heap) is full.
  // Then inserting an element would
  // lead to stack overflow
  if (!temp) {
   cout << "\nStack Overflow";
   exit(1);
  }

  // Initialize data into temp data field
  temp->data = data;

  // Put top pointer reference into temp link
  temp->link = top;
  
  if(Min==NULL || Min->data>data){
      temp->minlink=Min;
      Min=temp;
  }

  // Make temp as top of Stack
  top = temp;
 }

 // Utility function to check if
 // the stack is empty or not
 bool isEmpty()
 {
  // If top is NULL it means that
  // there are no elements are in stack
  return top == NULL;
 }

 // Utility function to return top element in a stack
 int peek()
 {
  // If stack is not empty , return the top element
  if (!isEmpty())
   return top->data;
  else
   exit(1);
 }
	
 int min(){
     if (!isEmpty())
   return Min->data;
  else
   exit(1);
 }

 // Function to remove
 // a key from given queue q
 void pop()
 {
  Node* temp;

  // Check for stack underflow
  if (top == NULL) {
   cout << "\nStack Underflow" << endl;
   exit(1);
  }
  else {

   // Assign top to temp
   temp = top;
   
   if(Min==temp) Min=temp->minlink;

   // Assign second node to top
   top = top->link;

   // This will automatically destroy
   // the link between first node and second node

   // Release memory of top node
   // i.e delete the node
   free(temp);
  }
 }

 // Function to print all the
 // elements of the stack
 void display()
 {
  Node* temp;

  // Check for stack underflow
  if (top == NULL) {
   cout << "\nStack Underflow";
   exit(1);
  }
  else {
   temp = top;
   while (temp != NULL) {

    // Print node data
    cout << temp->data;

    // Assign temp link to temp
    temp = temp->link;
    if (temp != NULL)
     cout << " -> ";
   }
  }
 }
};

// Driven Program
int main()
{
 // Creating a stack
 Stack s;

 // Push the elements of stack
 s.push(11);
 s.push(22);
 s.push(33);
 s.push(44);

 // Display stack elements
 s.display();

 // Print top element of stack
 cout << "\nTop element is " << s.peek() << endl;

 // Delete top elements of stack
 s.pop();
 s.pop();

 // Display stack elements
 s.display();

 // Print top element of stack
 cout << "\nTop element is " << s.peek() << endl;
 cout << "\nMin element is " << s.min() << endl;

 return 0;
}

/*

A stack is better than an array for dealing with nested structures, such as parentheses, braces, or tags in HTML/XML code, 
because it simplifies the code, provides a natural way to keep track of the structure, and is generally more efficient. 
Using an array would require more complex code and could be less efficient for large or deeply nested structures.

*/