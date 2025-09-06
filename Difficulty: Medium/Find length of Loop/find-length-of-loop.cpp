/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
     int lengthOfLoop(Node *head) {
        // code here
        Node *fast, *slow;
        fast = slow = head;
        
        if(fast->next == NULL)
          return 0;
        
        fast = fast->next->next;
        slow = slow->next;
        
        while(fast != slow){
            if((fast==NULL) || (fast->next==NULL))
              return 0;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        int count = 1;
        slow = slow->next;
        
        
        while(slow != fast){
            count++;
            slow = slow->next;
        }
        
        return count; 
    }
};