/*
--> runtime pe he jitna expand ya shrink karna hi karlo
--> no waste of memory
-->heap mai kahin bhi memory milti ja rhi ye unko use karta jayega and connect hote jayenge address se sab
--> types
  1. Singly linked list 
  2. Doubly linked list
  3. Circular linked list
  4. Circular doubly linked list

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


int main()
{
  Node* node1=new Node(10); //aise he jitne new node chaho banao
  cout<<node1->data; //ye node1 specifically ka data jo uspe stored hi uski value
  cout<<node1->next; //ye node1 ke 
}


















