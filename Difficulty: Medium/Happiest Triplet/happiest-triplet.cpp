class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> v;
        int minii = INT_MAX;
        while(i<a.size() && j<b.size() && k<c.size()){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int a1 = a[i];
            int b1 = b[j];
            int c1 = c[k];
            mini = min(mini,min(a1,b1));
            mini = min(mini,c1);
            maxi = max(maxi,max(a1,b1));
            maxi = max(maxi,c1);
            int f = minii;
            minii = min(minii,maxi-mini);
            if(f != minii){
                v.clear();
                v.push_back(a1);
                v.push_back(b1);
                v.push_back(c1);
            }
            if(mini == a1){
                i++;
            }
            else if(mini == b1){
                j++;
            }
            else{
                k++;
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        return v;
    }
};