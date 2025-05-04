//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_map<char,int>freq;
        unordered_map<char,int>result;
        for (char c:str) {
           freq[c]=1;
        }
        int char_=freq.size();    
        freq.clear();
        int beg=0;
        int min_=INT_MAX;
        int cnt=0;
        for(int end= 0; end<str.size();++end) {
            char cur =str[end];
            result[cur]++;
                if(result[cur]==1)
                cnt++;
            while(cnt ==char_) {
                if(end -beg+1< min_) 
                    min_=end -beg + 1;
                char new_=str[beg];
                result[new_]--;
                if(result[new_]==0) 
                    cnt--;
                beg++;
            }
        }
        
        return min_;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends