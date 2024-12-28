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
  tail->next=temp; // head ko temp node se point karwa do
  tail=tail->next; // temp ka jo next hi jo ki null (by default)ko point kar rha tha usko hata kar existing node ke head se point karwa do
}

void insertAtFront(Node* &head,int val)
{
  Node* temp=new Node(val);
  temp->next=head;
  head=temp;
}

void insertAtMiddle(Npde* &tail,Node* &head,int pos,int val) // idhar handel karne hote hi 3 cases
{
  Node* temp=head;
  int c=1;

  //starting mai insert karne ka case idhar handle ho gya hi
  if(pos==1) //1st pe dalne ko bolenge to error dega as humne start he 1st index se kiya hi toh udhar kaise dal sakte and hume insert karne ke liye pre place wala elements chahiye
  {
    insertAtFront(head,val);
    return;
  }

  //middel mai insert karne ka idhar handle ho gya
  while(c<pos-1 && temp->next!=NULL) // coz agar hum 4th position wale ko peeche karenge toh toh hum khud he 4th ban jayenge na 
  {
    temp=temp->next;
    c++;
  }
  
  //last mai insert karne ka idhar
  if(temp->next=NULL)
    {
      insertAtTail(tail,val);
      return;
    }

  //creating the node to be inserted sab pura uper check karne ke daab ki kahin jo pos mili hi vo 1st toh nhi ya last toh nhi beech ki kahin hi tab add karo nhi toh last or front fng ko call karo and value pass karke in neeche wali line ko ignore karo
  Node* nodetoinsert=new Node(val);
  nodetoinsert->next=temp->next;
  temp->next=nodetoinsert;

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
  
  Node* head=node1; 
  Node* tail=node1; //pointer that store the address of the node1 on creation and single node hi start mai tail bolo head 

  insertAtTail(tail,20);
  printlist(tail);

  insertAtTail(tail,30);
  printlist(tail);

  insertinmiddle(tail,head,3,25);
  print(head);

  cout<<head->data;
  cout<<tail->data;
  
}








