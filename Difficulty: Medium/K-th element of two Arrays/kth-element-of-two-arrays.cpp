class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        int p=0;
        while(i<n && j<m){
            if(a[i]<b[j]){
                p++;
                if(p==k){
                  return a[i];
                }
                i++;
            }
            else{
                p++;
                if(p==k){
                  return b[j];
                }
                j++;
            }
            
        }
        
        while(i<n){
             p++;
             if(p==k){
                return a[i];
             }
             i++;
        }
        
        while(j<m){
            p++;
            if(p==k){
               return b[j];
            }
            j++;
        }
    }
};