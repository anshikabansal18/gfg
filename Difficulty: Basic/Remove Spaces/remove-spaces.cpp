class Solution {
  public:
    string removeSpaces(string& s) {
        //Time Complexity : O(n) 
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
        // Time Complexity : O(n^2) 
        /*
        int i = 0, j = s.size();
        while(i < s.size()) { // O(n)
            if(s[i] == ' ') s.erase(i,1); // for erase() -> O(n)
            else i++;
        }
        return s;
        */
    }
};