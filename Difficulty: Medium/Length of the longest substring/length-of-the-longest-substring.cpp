//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int> mpp(256, -1);
        int left=0, right = 0;
        int n = S.size();
        int len = 0;
        while(right < n){
            if(mpp[S[right]] != -1){
                left = max(left, mpp[S[right]] + 1);
            }
            
            mpp[S[right]] = right;
            len = max(len, right-left+1);
            right++;
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends