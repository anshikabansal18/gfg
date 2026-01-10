class Solution {
  public:
      int countSubstr(string& s, int k) {
        int n = s.length();
        int subs = 0;

        for (int start = 0; start < n; start++) {
            int freq[26] = {0};
            int distinct = 0;

            for (int end = start; end < n; end++) {
                int idx = s[end] - 'a';

                if (freq[idx] == 0)
                    distinct++;

                freq[idx]++;

                if (distinct == k)
                    subs++;
                else if (distinct > k)
                    break;
            }
        }

        return subs;
    }     
};