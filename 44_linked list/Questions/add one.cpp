/*
Input: head->[2]->[5]->[3]->[4]->[7]->NULL +1 = 2 5 3 4 7
                                                      + 1
                                                2 5 3 4 8
Output: head->[2]->[5]->[3]->[4]->[8]->NULL
*/

//brute force
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




//better using recursion
int helper(Node* temp) //add kar rha and aage badh rha
{
        if (temp == NULL) 
            return 1; //last mai add karna na toh jaise he list ke end mai aye return 1 coz addition ka rule units places se addition starts hota hi
        carry=helper(temp->next) // tab tak jab tak 1 return nhi hota i.e list ends 
        temp->data=temp->data+carry; //temp ke data mai add karte ja rhe 

        if(temp->data < 10) 
            return 0; //carry 0 coz less than 10 hi

        //agar maanlo sum aya 10
        temp->data=0; // current node pe zero he hoga na 10%10=0  10/10=1
        return 1; //carry bacha 1
    }

Node* fun(Node* head) //execution starts here
{
    int carry = helper(head);
    if (carry == 1) //agar puri list khtm hua and carry bacha hi 1
    {
        Node* newNode = new Node(1); //toh new node create karo and dalo
        newNode->next = head; //
        return newNode; //head abhi bhi purane node pe hi usko rehne do apna kaam ab newhead se ho he jayega kon jhanjhat le head deletion ka headh abhi bhi purani wali node ko he point karta kahega but hum bhje he newNode ko rhe hi 
    }
    return head; //agar carry nhi toh seedha head return
}

