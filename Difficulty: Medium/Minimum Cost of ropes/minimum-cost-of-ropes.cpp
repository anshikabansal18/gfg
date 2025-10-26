class Solution {
  public:
    int minCost(vector<int>& arr) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto it:arr) pq.push(it);
        while(pq.size()>1){
            int t=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            
            ans+=t+s;
            pq.push(t+s);
        }
        
        return ans;
    }


};