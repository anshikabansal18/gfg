// User function template for C++
class Solution {
  public:
     int rowWithMax1s(vector<vector<int>> &arr) {
        int maxCount = 0;
        int rowIndex = -1;

        for (int i = 0; i < arr.size(); i++) {
            int currentCount = 0;
            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] == 1) {
                    currentCount++;
                }
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};