/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
     class Box
  {
      public: 
      bool BST;
      int size, min, max;
      
      Box()
      {
          BST = 1;
          size = 0;
          min = INT_MAX;
          max = INT_MIN;
      }
  };
  
  Box* find(Node*root, int &Totalsize)
  {
      //root doesn't exist
      if(!root)
      {
          return new Box();
      }
      //root exist
      
      Box* lefthead = find(root->left,Totalsize);
      Box* righthead = find(root->right,Totalsize);
      
      if(lefthead->BST && righthead->BST && lefthead->max<root->data && righthead->min>root->data)
      {
         Box* head = new Box();
         head->size = 1+lefthead->size+righthead->size;
         head->min = min(root->data,lefthead->min);
         head->max = max(root->data,righthead->max);
         Totalsize = max(Totalsize,head->size);
         return head;
      }
      else
      {
          lefthead->BST=0;
          return lefthead;
      }
      
  }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        int Totalsize = 0;
        find(root,Totalsize);
        return Totalsize;
    }
};