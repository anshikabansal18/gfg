class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        
        int ans = -1;
        int i = 0;
        int n = s.size();
        long long p1 = 1, p2 = 1;
        long long base1 = 31, base2 = 37;
        long long mod1 = 1e9 + 1, mod2 = 1e9 + 7;
        vector<long long> hash1(2,0);
        vector<long long> hash2(2,0);
        
        while(i<n-1){
            
             hash1[0] = (hash1[0] + (((s[i]-'a'+1)*p1) %mod1)) % mod1;
             hash1[1] = (hash1[1] + (((s[i]-'a'+1)*p2) %mod2)) % mod2;
             hash2[0] = ((hash2[0]*base1)%mod1 + (s[n-i-1]-'a'+1)) % mod1;
             hash2[1] = ((hash2[1]*base2)%mod2 + (s[n-i-1]-'a'+1)) % mod2;
             
             if(hash1 == hash2){
                 ans = n-i-1;
                 break;
             }
             
             
             p1=(p1*base1)%mod1;
             p2=(p2*base2)%mod2;
             i++;
             
             
            
        }
        
        return ans;
        
    }
};