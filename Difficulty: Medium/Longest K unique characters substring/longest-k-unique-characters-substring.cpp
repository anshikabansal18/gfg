//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mpp; 
        int maxlen = -1;// Initialize with -1 to handle the case where no valid substring exists
        int left = 0, right = 0;
        
        while(right<n) {
            mpp[s[right]]++;
            while(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            
            if(mpp.size() == k){
                maxlen = max(maxlen, right-left+1);
            }
            
            right++;
        }
        
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends