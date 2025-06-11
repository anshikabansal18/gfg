class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n=color.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(!st.empty() && (color[st.top()]==color[i] && radius[st.top()]==radius[i])){
                while(!st.empty() && (color[st.top()]==color[i] && radius[st.top()]==radius[i])){
                    st.pop();
                }
            }else st.push(i);
        }
        return st.size();
    }
};