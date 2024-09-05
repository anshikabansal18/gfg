//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        int left = 0, right = 0;
        int n = S.size();
        int maxlen = 0;
        unordered_map<char,int> countMap;
        int maxCount = 0;
        while(right < n){
            countMap[S[right]]++;
            maxCount = max(maxCount, countMap[S[right]]);
            
            if((right - left + 1) - maxCount > K){
                countMap[S[left]]--;
                left++;
            }
            
            maxlen = max(maxlen, right - left + 1);
            
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
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends