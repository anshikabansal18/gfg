class Solution {
    public:
    int n;
    int pivot_point(vector<int>& arr,int x){
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[n-1]){
                ans=mid;
                l=mid+1;
            } else r=mid-1;
        }
        return ans+1;
    }
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        n=arr.size();
        int idx=pivot_point(arr,x);
        // cout<<"idx : "<<idx<<endl;
        int left_part=upper_bound(arr.begin(),arr.begin()+idx,x)
        -arr.begin();
        // cout<<"left part : "<<left_part<<endl;
        int right_part=upper_bound(arr.begin()+idx,arr.end(),x)
        -(arr.begin()+idx);
        // cout<<"right part : "<<right_part<<endl;
        return left_part+right_part;
    }
};