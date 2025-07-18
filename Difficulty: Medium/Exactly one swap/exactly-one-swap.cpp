class Solution {
  public:
    int countStrings(string &s) {
        vector<int> mp(26, 0);
        for(char c: s){
            mp[c-'a']++;
        }
        int ans = 0;
        bool duplicate = 0;
        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                ans += mp[i] * mp[j];
            }
            if(mp[i] > 1) duplicate = 1;
        }
        if(duplicate) ans++;
        return ans;
    }
};
