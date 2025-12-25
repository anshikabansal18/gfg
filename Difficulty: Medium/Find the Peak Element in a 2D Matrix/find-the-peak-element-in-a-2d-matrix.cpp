class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        // code here
        vector<int> ans;
       int n= arr.size();
       int m= arr[0].size();
       int j=0;
       bool a=false;
       if(n==1&&m==1)
       {
           ans.push_back(0);
           ans.push_back(0);
           return ans;
       }
       if(n==1){
           int u=INT_MIN;
           int h=0;
           for(int i=0;i<m;i++){
              if(arr[0][i]>u){
                  u=arr[0][i];
                  h=i;
              }
           }
           ans.push_back(0);
           ans.push_back(h);
           return ans;
       }
       if(m==1){
            int u=INT_MIN;
           int h=0;
           for(int i=0;i<n;i++){
              if(arr[i][0]>u){
                  u=arr[i][0];
                  h=i;
              }
           }
           ans.push_back(h);
           ans.push_back(0);
           return ans;
       }
       
       
       
       
       
       for(int i=0;i<n;i++){
           int c=0;
           for( j=0;j<m;j++){
               c=0;
               if(i==n-1){
                   c++;
                   if(arr[i][j]>=arr[i-1][j])
                   c++;
                   else
                   continue;
               }
               else if(i==0){
                   c++;
                   if(arr[i][j]>=arr[i+1][j])
                   c++;
                   else
                   continue;
               }
               else{
                   if(arr[i][j]>=arr[i+1][j]&&arr[i][j]>=arr[i-1][j])
                   c+=2;
                   else
                   continue;
               }
               if(j==0){
                   
               c++;
               if(arr[i][j]>=arr[i][j+1])
               c++;
               else
               continue;
               }
               else if(j==m-1){
                   c++;
                   if(arr[i][j]>=arr[i][j-1])
               c++;
               else
               continue;
               }
               else{
                   if(arr[i][j]>=arr[i][j+1]&&arr[i][j]>=arr[i][j-1])
                   c+=2;
                   else
                   continue;
               } 
            if(c==4){
               ans.push_back(i);
               ans.push_back(j);
               a=true;
               break;
                }
               
           }
           if(a==true)
           break;
       }
        return ans;
    }

};
