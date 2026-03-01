class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int pos=0;
        int n=arr.size();
        //shifting of non zero elements 
        for(int i =0;i<n;i++){
           if(arr[i]!=0){
               arr[pos]=arr[i];
               pos++;
           } 
        }
        
        //filling the remaining position with zeroes
        while(pos<n){
            arr[pos]=0;
            pos++;
        }
    
        
    }
};