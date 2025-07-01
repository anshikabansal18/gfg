class Solution {
  public:
     int substrCount(string &s, int k) {
        // code here
        int dis=0;
        int count=0;
        int start=0;
        unordered_map<char,int> mp;
        int len=s.length();
        if(len<k) return 0;
        for(int i=0;i<k;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1) dis++;
        }
        if(dis==k-1) count++;
        for(int i=k;i<len;i++){
            mp[s[start]]--;
            if(mp[s[start]]==0) dis--;
            start++;
            mp[s[i]]++;
            if(mp[s[i]]==1) dis++;
            if(dis==k-1) count++;
        }
        return count;
    }


};