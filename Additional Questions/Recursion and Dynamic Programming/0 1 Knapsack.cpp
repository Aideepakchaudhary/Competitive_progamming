#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
#define ff first
#define ss second
#define pi pair<int,int>
#define pii std::vector<pi>
#define lcm(a,b)  a*b / (__gcd(a,b))
// #define mp  unordered_map<int,int>



void solve()
{
	int n, W; cin >> n >> W;
	int dp[n + 1][W + 1];

	vi w(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++)
			if (i == 0 or j == 0)
				dp[i][j] = 0;

			else if (w[i] > j)
				dp[i][j] = dp[i - 1][j];

			else
				dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
	}

	cout << dp[n][W] << "\n";

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t;
	// while (t--)
	solve();
	return 0;
}