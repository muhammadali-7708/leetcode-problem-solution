class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = INT_MAX;
        for (auto &it : items) mn = min(mn, it[1]);
        vector<int> val(n, 0);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) cnt++;
            }
            val[i] = cnt;
        }
        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int c = budget - p; c >= 0; --c) {
                if (dp[c] != NEG) {
                    dp[c + p] = max(dp[c + p], dp[c] + val[i]);
                }
            }
        }
        long long ans = 0;
        for (int c = 0; c <= budget; c++) {
            if (dp[c] == NEG) continue;
            long long cur = (long long)dp[c] + (budget - c) / mn;
            ans = max(ans, cur);
        }
        return (int)ans;
    }
};