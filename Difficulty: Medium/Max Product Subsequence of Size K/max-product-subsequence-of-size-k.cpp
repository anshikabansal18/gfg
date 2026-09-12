class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
           // code here
           int n=arr.size();
           sort(arr.begin(),arr.end());
           int ans=0,prod=1;
           vector<int> suff(n,0);
           suff[n-1]=arr[n-1];
           for(int i=n-2;i>=0;i--){
               suff[i]=suff[i+1]*arr[i];
           }
           ans=suff[n-k];
           for(int i=0;i<n;i++){
               prod*=arr[i];
               int rem_idx=n-k+(i+1);
               if(rem_idx>=0 && rem_idx<n) ans=max(ans,prod*suff[rem_idx]);
               else if(i+1==k){
                   ans=max(ans,prod);;
                   break;
               }
           }
           return ans;
       }
};