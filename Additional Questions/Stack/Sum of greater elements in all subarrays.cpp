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


void solve() {
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	stack<int> p_greater;
	stack<int> n_greater;
	vi temp1(n), temp2(n);

	// For previous greater..

	for (int i = 0; i < n; i++) {
		while (p_greater.size() and a[i] >= a[p_greater.top()])
			p_greater.pop();

		temp1[i] = p_greater.size() ? p_greater.top() : -1;
		p_greater.push(i);
	}

	// For next greater..

	for (int i = n - 1; i >= 0 ; --i) {
		while (n_greater.size() and a[i] >= a[n_greater.top()])
			n_greater.pop();

		temp2[i] = n_greater.size() ? n_greater.top() : n;
		n_greater.push(i);
	}
	int ans = 0;
	
	// Calculate total no. of subarrays...

	for (int i = 0; i < n; i++) {
		ans += (i - temp1[i]) * (temp2[i] - i) * a[i];
	}
	cout << ans << "\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}