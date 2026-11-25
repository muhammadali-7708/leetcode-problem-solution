class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long MOD1 = 1000000007;
        const long long MOD2 = 1000000009;
        const long long BASE = 911382;

        vector<long long> pow1(n + 1), pow2(n + 1);
        vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);
        pow1[0] = pow2[0] = 1;
        for (int i = 0; i < n; i++) {
            pow1[i + 1] = pow1[i] * BASE % MOD1;
            pow2[i + 1] = pow2[i] * BASE % MOD2;
            pref1[i + 1] = (pref1[i] * BASE + nums[i] + 1007) % MOD1;
            pref2[i + 1] = (pref2[i] * BASE + nums[i] + 1007) % MOD2;
        }

        auto getHash = [&](int l, int len, vector<long long>& pref,
                           vector<long long>& pw, long long mod) {
            long long res = (pref[l + len] - pref[l] * pw[len]) % mod;
            if (res < 0) res += mod;
            return res;
        };

        auto hasUnique = [&](int len) {
            unordered_map<long long, int> cnt;
            cnt.reserve(n * 2);
            for (int i = 0; i + len <= n; i++) {
                long long h1 = getHash(i, len, pref1, pow1, MOD1);
                long long h2 = getHash(i, len, pref2, pow2, MOD2);
                long long key = h1 * MOD2 + h2;
                cnt[key]++;
            }
            for (auto &p : cnt) {
                if (p.second == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};