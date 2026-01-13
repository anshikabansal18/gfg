class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int n=arr.size();
        int c_5=0;
        int c_10=0;
        int c_20=0;
        for(int i=0;i<n;i++){
    if(arr[i]==5){
        c_5++;
    }
   else if(arr[i]==10){
        if(c_5>0){
            c_10++;
            c_5--;
        }else{
            return false;
        }
    }else{
         if(c_5>0&&c_10>0){
            c_5--;
            c_10--;
        }else if(c_5>2){
            c_5-=3;
        }
        else{
            return false;
        }
    }
        }
        return true;
    }
};