class Solution {
  public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        // Sort by radius increasing.
        // For equal radius, sort height decreasing so that
        // discs with the same radius cannot be chained.
        sort(discs.begin(), discs.end(), [](const auto &a, const auto &b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        });

        // h[i] <= 1000, so we can directly use height as index.
        const int MAXH = 1000;

        // Fenwick tree storing maximum stack height.
        vector<int> bit(MAXH + 1, 0);

        auto query = [&](int x) {
            int ans = 0;

            while (x > 0) {
                ans = max(ans, bit[x]);
                x -= x & -x;
            }

            return ans;
        };

        auto update = [&](int x, int value) {
            while (x <= MAXH) {
                bit[x] = max(bit[x], value);
                x += x & -x;
            }
        };

        int answer = 0;

        for (auto &[radius, height] : discs) {

            // Need previous height to be STRICTLY smaller.
            int bestBelow = query(height - 1);

            int current = bestBelow + height;

            update(height, current);

            answer = max(answer, current);
        }

        return answer;
    }
};