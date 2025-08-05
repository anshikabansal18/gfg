class Solution {
  public:
    bool isPalinSent(string &s) {
        int n = s.size();
        
        int i = 0, j = n - 1;
        
        while(i < j){
            while(i < j && !isalnum(s[i])) ++i;
            while(i < j && !isalnum(s[j])) --j;
            
            char lefty = tolower(s[i]), righty = tolower(s[j]);
            
            if(lefty != righty) return false;
            
            ++i; --j;
        }
        
        return true;
    }
};