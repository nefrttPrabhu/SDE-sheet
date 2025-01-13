/* M1: optimal using priority queue(nothing just self sorting queue by default min heap)
Eg: lists = [
    1 -> 4 -> 5,
    1 -> 3 -> 4,
    2 -> 6 ]
  
 Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

 S1: sabke heads ko store karliya head value and node pair mai then head value se pq apne aap he sort karlegi 
 S2: then create dummy node 
 S3: point temp to dummy and while(!pq.empty()) temp ko front se pont kardo and top wale ko pop(jo ki by defalut smallest hoga in the pq
 S4: then agar vo list jiska head smallest hi agar uska next!=null hi toh then usko pq mai andar dalo vo khud ba khud he sort ho jayega 
  */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Min-heap to store pairs of (value, ListNode*)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push the head of each non-empty list into the priority queue
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // Create a dummy node to simplify the result list construction
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // While the priority queue is not empty, process nodes
        while (!pq.empty()) {
            // Get the smallest node from the priority queue
            pair<int, ListNode*> p = pq.top();
            pq.pop();

            // Add the smallest node to the result list
            temp->next = p.second;
            temp = temp->next;

            // Push the next node of the extracted list into the priority queue
            if (p.second->next) {
                pq.push({p.second->next->val, p.second->next});
            }
        }

        return dummyNode->next; // Return the head of the merged list
    }
};

// Utility function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example input: k sorted linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    // Merge k sorted lists
    ListNode* mergedList = solution.mergeKLists(lists);

    // Print the merged list
    printList(mergedList);

    return 0;
}

