//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> knowMe(n, 0);
        vector<int> iKnow(n, 0);
    
        // Count how many people know each person and how many each person knows
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
    
        // Check if there is a celebrity
        for (int i = 0; i < n; i++) {
            if (knowMe[i] == n - 1 && iKnow[i] == 0) {
                return i;  // i is a celebrity
            }
        }
    
        return -1;  // No celebrity found
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends