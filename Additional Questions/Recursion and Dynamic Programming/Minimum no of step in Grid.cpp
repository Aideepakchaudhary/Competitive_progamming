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
#define mp  unordered_map<int,int>

// You can divide n by 3 and 2 if divisible or -1. task-> n -> 1(minimum no of steps to reach 1)

vi dp;

//   Top-down approach.. Check for all Conditions...

int rec(int n)
{
	if (n == 1)
		return 0;

	if (dp[n] != -1)   // already calculated the ans..
		return dp[n];

	int ans = rec(n - 1) + 1;

	if (n % 2 == 0)
		ans = min(ans, rec(n / 2) + 1);

	if (n % 3 == 0)
		ans = min(ans, rec(n / 3) + 1);

	return dp[n] = ans;
}


void solve()
{
	int n; cin >> n;
	// dp.assign(n + 1, -1);
	// cout << rec(n) << "\n";


	// Bottom-Up approach..
	dp.resize(n + 1);

	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	cout << dp[n] << "\n";
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