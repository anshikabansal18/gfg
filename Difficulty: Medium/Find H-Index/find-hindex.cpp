class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        int ans=0;
        sort(citations.begin(),citations.end(),greater<>());
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1){
                ans= i+1;
            }
        }
        return ans;
        
    }
};