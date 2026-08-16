class Solution {
  public:
    int minProd(vector<int>& arr) {
         // code here

         int mini = INT_MAX, n = arr.size();

         bool flag = false;  // Detects -ve number

         // Handles case if all elements in array are > 0

         for(int i=0;i<n;i++)
         {
             if(arr[i] < 0)
             {
                 flag = true;

                 break;
             }

             mini = min(arr[i], mini);
         }

         if(!flag)
         return mini;

         // Handles case if there's a -ve element in the array

         int prod = 1, negative_max = INT_MIN;

         for(int i=0;i<n;i++)
         {
             if(arr[i] == 0)
             continue;

             prod *= arr[i];

             if(arr[i] < 0)
             negative_max = max(negative_max,arr[i]);
         }

         if(prod > 0)
         prod /= negative_max;      // To make the product -ve again if there is even number of -ve numbers in array

         return prod;
     }
};