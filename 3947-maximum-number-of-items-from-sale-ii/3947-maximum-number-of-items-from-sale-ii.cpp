class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        if (n == 0) return 0;
        long long B = budget;
        long long minPrice = LLONG_MAX;
        for (auto &it : items) minPrice = min(minPrice, (long long)it[1]);
        vector<int> cnt(n + 1, 0);
        for (auto &it : items) {
            if (it[0] <= n) cnt[it[0]]++;
        }
        vector<int> mult(n + 1, 0);
        for (int f = 1; f <= n; f++) {
            int s = 0;
            for (int m = f; m <= n; m += f) s += cnt[m];
            mult[f] = s;
        }
        vector<pair<long long,long long>> arr;
        arr.reserve(n);
        for (auto &it : items) {
            long long p = it[1];
            long long freeCnt = 0;
            if (it[0] <= n) freeCnt = (long long)mult[it[0]] - 1;
            if (freeCnt < 0) freeCnt = 0;
            arr.push_back({p, freeCnt});
        }
        sort(arr.begin(), arr.end());
        long long cost = 0;
        long long taken = 0;
        for (auto &pr : arr) {
            long long p = pr.first;
            long long freeCnt = pr.second;
            if (p >= 2 * minPrice) break;
            if (freeCnt == 0) continue;
            if (cost >= B) break;
            long long can = (B - cost) / p;
            long long take = min(freeCnt, can);
            cost += take * p;
            taken += take;
        }
        long long ans = 2 * taken + (B - cost) / minPrice;
        long long base = B / minPrice;
        if (base > ans) ans = base;
        return (int)ans;
    }
};