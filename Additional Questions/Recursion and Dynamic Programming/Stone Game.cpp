class Solution {
public:
    bool stoneGame(vector<int>& a) {
        int n =  a.size();

	int dp[n + 1][n + 1];

	vector<int> pre(n + 1);
	pre[0] = a[0];

	for (int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + a[i];

	for (int l = 1; l <= n; l++)
	{
		for (int i = 0; i + l - 1 < n; i++) {

			if (l == 1) {
				dp[i][i] = a[i];
			}

			else {
				int j = i + l - 1;

				int sum = i ? pre[j] - pre[i - 1] : pre[j];

				dp[i][j] = sum - min(dp[i + 1][j], dp[i][j - 1]);
				// cout << dp[i][j] << " ";
			}
		}
		// cout << "\n";
	}
	return 2 * dp[0][n - 1] > pre[n - 1];
    }
};