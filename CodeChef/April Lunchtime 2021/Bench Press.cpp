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
#define mp  map<int,int>



void solve()
{
	int n, w, wr; cin >> n >> w >> wr;
	vi a(n);
	mp mp1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp1[a[i]]++;
	}

	if (wr >= w) {
		cout << "YES\n";
		return;
	}
	int sum = 0;

	for (auto x : mp1)
	{
		if (x.ss > 1) {
			sum += ((x.ss / 2) * x.ff) % MOD;
			sum = (sum * 2) % MOD;
			if (sum >= w)
				break;
		}
	}
	// cout << sum << " ";

	if (sum + wr >= w) {
		cout << "YES\n";
	}

	else {
		cout << "NO\n";
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