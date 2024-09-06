//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        int n = cardPoints.size();
        int total = 0;
        //leftsum
        for(int i=0; i<k; i++){
            total += cardPoints[i];
        }
        
        int max_sum = total;
        
        //rightsum
        for(int i=0; i<k; i++){
            total = total - cardPoints[k-1-i] + cardPoints[n-1-i];
            max_sum = max(max_sum, total);
        }
        
        return max_sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> cardPoints;
        while (ss >> num)
            cardPoints.push_back(num);

        int k;
        cin >> k;
        cin.ignore(); // Consume the newline character

        Solution ob;
        cout << ob.maxScore(cardPoints, k) << endl;
    }

    return 0;
}

// } Driver Code Ends