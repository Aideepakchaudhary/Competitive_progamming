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
	int r, b, d; cin >> r >> b >> d;
	if (d == 0) {
		if (r == b) {
			cout << "YES\n";
			return;
		}
		else
			cout << "NO\n";
		return;
	}
	if (min(r, b) * (d + 1) < max(r, b)) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
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