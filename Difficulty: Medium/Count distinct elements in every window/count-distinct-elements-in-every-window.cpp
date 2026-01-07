class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        int j = k;
        int i =0;
        while(j<arr.size()){
            mp[arr[i]]--;
            if(mp[arr[i]] == 0)mp.erase(arr[i]);
            i++;
            mp[arr[j]]++;
            j++;
            ans.push_back(mp.size());
        }
        
        return ans;
    }
};