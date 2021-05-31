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
#define loop(a,b) for(int i = a; i < b; i++)

// Ques Link: https://codeforces.com/contest/177/problem/D2

void solve()
{
	int n, m, c; cin >> n >> m >> c;
	vi a(n);
	loop(0, n)
	cin >> a[i];
	vi b(m);
	loop(0, m)
	cin >> b[i];

	vi pre(n + 2, 0);

	for (int i = 0; i < m; i++)
	{
		pre[i] += b[i];
		pre[n - m + i + 1] -= b[i];
		// cout << pre[i] << " ";
	}
	// cout << "\n";

	for (int i = 1; i < n; i++)
		pre[i] += pre[i - 1];

	for (int i = 0; i < n; i++) {
		pre[i] += a[i];
	}


	for (int i = 0; i < n; i++)
		cout << pre[i] % c  << " ";

	cout << "\n";

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