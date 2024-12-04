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
int helper(Node* temp) {
        if (temp == NULL) return 1;
        int sum = helper(temp->next) + temp->data;
        temp->data = sum % 10;
        return sum / 10;
    }

    Node* addOne(Node* head) {
        int carry = helper(head);
        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        return head;
    }
}
