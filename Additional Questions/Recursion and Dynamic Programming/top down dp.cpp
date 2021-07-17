#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
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
#define ld long double
#define inf 1e18
// #define mp  map<int,int>

// typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// https://www.codechef.com/ZCOPRAC/problems/ZCO14002

void solve()
{
	// top down dp..(iterative)

	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int dp[100005];

	dp[0] = a[0];
	dp[1] = a[1];
	dp[2] = a[2];

	for (int i = 3; i < n; i++)
	{
		dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + a[i];
	}

	if (n < 3) {
		cout << min(dp[n - 1], dp[n - 2]) << "\n";
	}
	else
		cout << min({dp[n - 1], dp[n - 2], dp[n - 3]}) << "\n";

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