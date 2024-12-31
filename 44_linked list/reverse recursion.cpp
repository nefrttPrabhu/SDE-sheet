//Eg:  head->[5]->[4]->[3]->[2]->[1]->NULL
//end tak jao baki ko waiting mai rakho prev head ke sath and wait karo tabtak jabtak end nhi hoti coz tab hume new head mil jayega joki last node of the list hoga


Node* reverseLinkedList(Node* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting 
    // from the second node (head->next).
    Node* newHead = reverseLinkedList(head->next); //I1: 4 coz head=5 se toh bheja he tha aise karte karte last head->[1] jaeyga but head->NULL hi toh return [1] hoga jo ki new head banega then neeche wale waiting cases execute honge
    
    // Save a reference to the node following
    // the current 'head' node. //I1:head->[5]->[4]->[3]->[2]->[1]->NULL I2:head->[4]->[3]->[2]->[1]->NULL I3:head->[3]->[2]->[1]->NULL I4:head->[2]->[1]->NULL ...I5 will be executed 1st then again list links will be changed for I4 then for I3
    Node* front = head->next; 
    
    // Make the 'front' node point to the current
    // 'head' node in the reversed order.
                        //          recusive call   h    f               h    f                    h    f                         h    f
    front->next = head; //I5:NULL<-[1]<-newHead I4:[2]->[1]<-newHead I3:[3]->[2]<-[1]<-newHead I2:[4]->[3]<-[2]<-[1]<-newHead I1:[5]->[4]<-[3]<-[2]<-[1]<-newHead
    
    // Break the link from the current 'head' node
    // to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new
    // head of the reversed linked list.
    return newHead; // ye hamesha wahi last wale node ko return kar rha hi as the newHead ie [1] next //I5:NULL<-[1]<-newHead I4:NULL<-[2]<-[1]<-newHead I3:NULL<-[3]<-[2]<-[1]<-newHead I2:NULL<-[4]<-[3]<-[2]<-[1]<-newHead I1:NULL<-[5]<-[4]<-[3]<-[2]<-[1]<-newHead
}


int main(){
    int* rev = reverseLinkedList(head); //head->[5]->[4]->[3]->[2]->[1]->NULL
    print(rev); //NULL<-[5]<-[4]<-[3]<-[2]<-[1]<-newHead
}
