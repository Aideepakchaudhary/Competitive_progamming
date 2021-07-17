#define ll long long

//https://leetcode.com/problems/coin-change/

class Solution {

    ll dp[10001];   // min coin required..

    void initialize() {
        for (ll i = 0; i < 10001; i++)
            dp[i] = -1;
    }

    ll rec(vector<int> &coin, ll k) {

        if (k == 0)
            return 0;

        if (dp[k] != -1)
            return dp[k];

        dp[k] = 1000000000000;

        for (ll i : coin) {
            if (i <= k) {
                dp[k] = min(dp[k], rec(coin, k - i) + 1);
            }
        }
        return dp[k];
    }

public:
    ll coinChange(vector<int>& coins, ll amount) {
        initialize();

        ll ans = rec(coins, amount);
        if (ans == 1000000000000) {
            return -1;
        }
        return ans;
    }
};