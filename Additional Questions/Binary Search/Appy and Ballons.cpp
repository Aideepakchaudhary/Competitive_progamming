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

// Question  Link: https://www.codechef.com/OCT18A/problems/HMAPPY

bool is_possible(int k, int *a, int *b, int m, int n)
{
	int min_ballons = 0;
	for (int i = 0; i < n; i++) {
		int ceil_of_exp = (a[i] *  b[i] - k + b[i] - 1) / b[i]; // ceil(a[i]*b[i] - k)/b[i];
		ceil_of_exp = max(0ll, ceil_of_exp);
		min_ballons += ceil_of_exp;
	}
	return min_ballons <= m;
}

void solve() {
	int n, m; cin >> n >> m;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];


	// smallest such k s.t. it is possible to have max(ci) <= k;
	int beg = 0, end = 1e18, ans;
	while (beg <= end) {
		int k = (beg + end) / 2;
		if (is_possible(k, a, b, m, n))
			ans = k, end = k - 1;
		else
			beg = k + 1;
	}
	cout << ans << "\n";
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
