class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n=s.size();
        vector<int>ans;
        vector<pair<int,int>>last_idx(26,{-1,-1});
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=int(s[i]);
            last_idx[s[i]-'a']={i,sum};
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            int idx=last_idx[s[i]-'a'].first;
            if(idx!=i &&idx!=-1){
                int val=last_idx[s[i]-'a'].second;
                int d=int(s[i]);
                int non_zero=val-2*d-currSum;
                if(non_zero)ans.push_back(non_zero);
                last_idx[s[i]-'a'].first=-1;
            }
            currSum+=s[i];
        }
        return ans;
    }
};