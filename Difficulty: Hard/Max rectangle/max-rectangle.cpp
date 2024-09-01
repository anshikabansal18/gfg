//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int lhist(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
    
        for (int i = 0; i <= n; i++) { // Note: Changed i < n to i <= n to handle the end case
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
    
        return maxArea;
    }
    
    // Function to calculate the maximum rectangular area of 1s in a binary matrix
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxArea = 0;
        vector<int> heights(m, 0); // Use a single vector for the histogram heights
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Update the histogram heights based on the current row
                heights[j] = (M[i][j] == 1) ? heights[j] + 1 : 0;
            }
            // Calculate the max area for the histogram at the current row
            maxArea = max(maxArea, lhist(heights));
        }
    
        return maxArea;
    }
    
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends