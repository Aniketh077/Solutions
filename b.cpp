/*

b) Linked List:  The link shows a program to find the nth element of a linked list. 

  Find a way to find the kth to the last element of linked list assume lengths of linked list is not known
  Can you minimize the number of times you run through the loop

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
 int data;
 struct Node* next;
};

void printKthFromLast(struct Node* head, int K)
{
 struct Node* temp = head;
    queue<struct Node*> qe;
 while (temp != NULL) {
     qe.push(temp);
     if(qe.size()>K) qe.pop();
  temp = temp->next;
 }
 if(qe.size()<K){
     cout<<"Size of the LinkedList is less than K"<<endl;
 }
 else cout<<qe.front()->data<<endl;

 return ;
}

void push(struct Node** head_ref, int new_data)
{
 struct Node* new_node = new Node();
 new_node->data = new_data;
    new_node->next = (*head_ref);
 (*head_ref) = new_node;
}

int main()
{
 struct Node* head = NULL;

 push(&head, 20);
 push(&head, 4);
 push(&head, 15);
 push(&head, 35);
	
 printKthFromLast(head, 3);
 return 0;
}
