#include <iostream>
using namespace std;

class Node{
public:
  int data;   //to store the value at the node
  Node* next; //a pointer to store the address of the node

  Node(int data) //constructor jo jo humlog new node create karte jayenge vo value assign hoti jayegi new node mai and uska address null store ho jayega
  {
    this ->data=data; //naya node bana and uske data ko jo value pass hue vo assign kardi
    this ->next=NULL; //new node bana and uske end mai apne aap he next pointer ko NULL value store kardi
  }
};


void insertAtTail(Node* &tail,int val)
{
    
  Node* temp=new Node(val); //ek new temporary node create kiya jisko value pass store karwadi
  tail->next=temp;          // head ko temp node se point karwa do
  tail=tail->next (temp);   // temp ka jo next hi jo ki null (by default)ko point kar rha tha usko hata kar existing node ke head se point karwa do
}


void printlist(Node* &head)
{
  Node* temp=head;
  while(temp!=NULL)
  {
    cout<< temp->data<<" ";
    temp= temp->next;
  }
  cout<<endl;
}


int main()
{
  Node* node1=new Node(10); //aise he jitne new node chaho banao
  
  Node* head=node1; //points to 1st node of the linked list 
  Node* tail=node1; //pointer that store the address of the node1 on creation and single node hi start mai tail bolo head 

  insertAtTail(tail,20);
  printlist(head); //printing hum abhi bhi head se karwa rhe coz tail toh end mai he rahe gi na and uske baad NULL 

  insertAtTail(tail,30);
  printlist(head);
  
}


















