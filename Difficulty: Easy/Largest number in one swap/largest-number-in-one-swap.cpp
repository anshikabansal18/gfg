class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        stack<int>st;
        st.push(0);
        for(int i = 1 ;i<s.size() ; i++){
            if(s[i]>s[st.top()]){
                int maxi = i;
                for(int j = i+1 ; j<s.size() ; j++){
                    if(s[maxi] <=s[j]){
                        maxi = j;
                    }
                }
                int prev = st.top();
                st.pop();
                while(!st.empty() && s[st.top()] <s[maxi]){
                    prev = st.top();
                    st.pop();
                }
                swap(s[prev] , s[maxi]);
                return s;
            }else if(s[i] <s[st.top()])st.push(i);
        }
        return s;
    }
};