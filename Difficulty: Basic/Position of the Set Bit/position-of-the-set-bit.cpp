class Solution {
  public:
    int findPosition(int n) {
        // code here
        int ans=-1,t=1;
        while(n){
            if(n&1 && ans==-1)ans=t;
            else if(n&1){
                ans=-1;
                return ans;
            }
            t++;
            n=n>>1;
        }
        return ans;
    }
};