class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=INT_MIN,r=INT_MAX;
        for(int i:left)
        {
            l=max(l,i);
        }
        for(int j:right)
        {
            r=min(r,j);
        }
        return max(l,n-r);
    }
};