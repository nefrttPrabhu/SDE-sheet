/*
  Input:
  Linked list: head->[1]->[2]->[3]->[4]->[5]->[6]->NULL
  
  Execution:
  Step 1: slow = 1, fast = 1
  Step 2: slow = 2, fast = 3
  Step 3: slow = 3, fast = 5
  Step 4: slow = 4, fast = NULL
*/

Node* middle(Node* head) {
    if (head == NULL) 
      return NULL; 

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL){ //1st fast NULL na ho coz ie NULL ka next which is invalid and fast->next NULL na ho coz ie also same NULL ka NULL which is invalid due to line 10 
                                                //and fast ka he check kar rhe coz slow 1 se badh rha and fast 2 se 
        fast = fast->next->next;               
        slow = slow->next;
    }

    return slow; // `slow` points to the middle node
}
