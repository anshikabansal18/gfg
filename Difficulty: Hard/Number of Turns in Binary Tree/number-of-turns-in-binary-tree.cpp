/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* LCA(Node *root , int p , int q){
         if(root == nullptr){
             return nullptr;
         }
         if(root->data == p || root->data == q){
             return root;
         }
         Node *leftLCA = LCA(root-> left , p , q);
         Node *rightLCA = LCA(root-> right , p , q);

         if(leftLCA && rightLCA){
             return root;
         }

         if(leftLCA != nullptr) return leftLCA;

         return rightLCA;
     }

     int ans = 1000000;
     void turnsFromLCA(Node *root , int x , int turns , int prev){
         if(root == nullptr){
             return;
         }
         if(root->data == x){
             ans = turns;
             return;
         }
         if(prev == 0){ // means i am coming from left
             turnsFromLCA(root->left , x , turns , prev);
             turnsFromLCA(root->right , x , turns+1 , 1);
         }else{
             turnsFromLCA(root->right , x , turns , prev);
             turnsFromLCA(root->left , x , turns+1 , 0);
         }


     }

     int numberOfTurns(Node* root, int p, int q) {
         //code here
         Node *lowestCommonAncestor = LCA(root , p , q);

         // Find minimum turns from LCA to p
         ans = 1000000;
         turnsFromLCA(lowestCommonAncestor, p, 0, 0);
         int forP = ans;

         ans = 1000000;
         turnsFromLCA(lowestCommonAncestor, p, 0, 1);
         forP = min(ans, forP);

         // Find minimum turns from LCA to q
         ans = 1000000;
         turnsFromLCA(lowestCommonAncestor, q, 0, 0);
         int forQ = ans;

         ans = 1000000;
         turnsFromLCA(lowestCommonAncestor, q, 0, 1);
         forQ = min(ans, forQ);


         int result = forP + forQ +
                (lowestCommonAncestor->data == p ||
                 lowestCommonAncestor->data == q ? 0 : 1);

         return result == 0 ? -1 : result;
     }
};