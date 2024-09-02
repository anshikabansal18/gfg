//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n) {
        vector<int> spanCount(n); // Initialize the span count vector with size n
        stack<pair<int, int>> st; // Correct stack declaration
    
        for (int i = 0; i < n; i++) {
            int span = 1; // Reset span to 1 for each new price
    
            // Calculate span by comparing with previous days' prices
            while (!st.empty() && st.top().first <= price[i]) {
                span += st.top().second; // Add the span of the top element
                st.pop(); // Remove the top element
            }
    
            st.push({price[i], span}); // Push current price and its span into the stack
            spanCount[i] = span; // Store the span in the result vector
        }
    
        return spanCount; // Return the vector containing spans
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends