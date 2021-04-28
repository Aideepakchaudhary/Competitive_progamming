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

// stock and span problem......



void solve() {
	int n; cin >> n;
	vi a(n), preg(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	stack<int> s;  // store previous greater elements indicies...

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() and a[s.top()] <= a[i])
			s.pop();

		s.empty() ? preg[i] = -1 : preg[i] = s.top();

		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << (i - preg[i]) << " ";
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