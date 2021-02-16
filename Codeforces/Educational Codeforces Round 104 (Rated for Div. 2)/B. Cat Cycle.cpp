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


void solve() {
	int n, k; cin >> n >> k;
	k--;
	if (n % 2 == 0)
	{
		cout << (k % n) + 1 << "\n";
	}
	else {
		int mid = n / 2; // At the mid a gap is there
		int total_gap = k / mid;
		int ans = (total_gap + k) % n + 1;
		cout << ans << "\n";
	}
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