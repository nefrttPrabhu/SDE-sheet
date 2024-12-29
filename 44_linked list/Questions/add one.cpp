/*
Input: head->[2]->[5]->[3]->[4]->[7]->NULL +1 = 2 5 3 4 7
                                                      + 1
                                                2 5 3 4 8
Output: head->[2]->[5]->[3]->[4]->[8]->NULL
*/

//M1: brute force
Node reverse(Node head){
    if(head == NULL || head->next ==NULL){
        return head; 
    }
    Node *newhead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}


Node *addOne(Node *head)
{   
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp!=NULL){
        temp->data = temp->data+carry;
        if(temp->data<10){
            carry =0;
            break;
        }
        else{
            temp->data =0;
            carry =1;
        }

        temp= temp->next;
    }
    if(carry ==1){
        Node* newNode= new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }
    head = reverse(head);
    return head;  
}




//M2: better using recursion
int helper(Node* temp) // Add one recursively
{
    if (temp == NULL)
          return 1; //last mai add karna na toh jaise he list ke end mai aye return 1 coz addition ka rule units places se addition starts hota hi

        int carry = helper(temp -> next) // tab tak jab tak 1 return nhi hota i.e list ends 
        temp->data = temp->data + carry; //temp ke data mai add karte ja rhe 

    if (temp->data >= 10) { // current node pe zero he hoga na 10%10=0  10/10=1
        temp->data = 0; // Set current node's value to 0 (as 10 % 10 = 0)
        return 1; //carry bacha 1    
    }
    return 0; // No carry to propagate
}
/* Option 2
  int helper(Node* temp) {
    if (temp == nullptr) 
        return 1; // Base case: Return carry = 1 to add 1 at the last node

    // Recursive call to the next node
    int carry = helper(temp->next);

    // Add carry to the current node's data
    temp->data += carry;

    // If the sum is less than 10, no carry is needed
    if (temp->data < 10) 
        return 0; // No carry to propagate further

    // If the sum is 10 or more, set current node's data to 0 and return carry = 1
    if (temp->data >= 10) {
    temp->data = 0;
    return 1; // Propagate carry
}
return 0;
 // Propagate carry to the previous node
}
*/

Node* fun(Node* head) //execution starts here
{
    int carry = helper(head);
    if (carry == 1) //agar puri list khtm hua and carry bacha hi 1
    {
        Node* newNode = new Node(1); //toh new node create karo and dalo
        newNode -> next = head; //
        return newNode; //head abhi bhi purane node pe hi usko rehne do apna kaam ab newhead se ho he jayega kon jhanjhat le head deletion ka headh abhi bhi purani wali node ko he point karta kahega but hum bhje he newNode ko rhe hi 
    }
    return head; //agar carry nhi toh seedha head return
}

//M3: 
