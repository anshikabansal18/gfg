//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p) {
        int left = 0, right = 0;
        int sIndex = -1;
        int minlen = 1e9;  // Initialize to a large value
        int n = s.size();
        int m = p.size();
        
        // If pattern length is greater than string length, no window can exist
        if (m > n) return "-1";
        
        vector<int> hash(256, 0);  // Frequency map for pattern p
        vector<int> window(256, 0);  // Frequency map for the current window
        
        int count = 0;  // To count how many characters have been matched from pattern p
    
        // Fill frequency map for pattern p
        for (int i = 0; i < m; i++) {
            hash[p[i]]++;
        }
    
        while (right < n) {
            // Expand the window by adding characters from the right
            window[s[right]]++;
    
            // If the current character is part of the pattern and doesn't exceed its needed frequency
            if (hash[s[right]] != 0 && window[s[right]] <= hash[s[right]]) {
                count++;
            }
    
            // When we've matched all characters of the pattern
            while (count == m) {
                // Try to update the minimum window
                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    sIndex = left;
                }
    
                // Shrink the window from the left
                window[s[left]]--;
                
                // If the character being removed was contributing to the match count
                if (hash[s[left]] != 0 && window[s[left]] < hash[s[left]]) {
                    count--;
                }
                
                left++;  // Move left pointer to shrink the window
            }
    
            right++;  // Move right pointer to expand the window
        }
    
        // If no valid window was found, return -1
        return sIndex == -1 ? "-1" : s.substr(sIndex, minlen);
    }


};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends