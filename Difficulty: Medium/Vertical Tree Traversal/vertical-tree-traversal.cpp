/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
       queue<pair<Node*,int>>q;
       q.push({root,0});
       map<int,vector<int>>mp;
       
       while(!q.empty()){
           auto it=q.front();q.pop();
           Node* nd=it.first;
           int ht=it.second;
           mp[ht].push_back(nd->data);
           if(nd->left)q.push({nd->left,ht-1});
           if(nd->right)q.push({nd->right,ht+1});
       }
       vector<vector<int>>ans;
       for(auto it: mp)ans.push_back(it.second);
       return ans;
        
    }
};