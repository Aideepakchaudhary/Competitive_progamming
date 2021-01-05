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

void solve()
{
	int n, x; cin >> n >> x;
	int a[n];
	int mini = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % x == 0) {
			maxi += a[i] / x;
		}
		else {
			maxi += (a[i] / x) + 1;
		}
		mini += a[i];
	}
	if (mini % x != 0) {
		mini = (mini / x) + 1;
	}
	else {
		mini = mini / x;
	}
	cout << mini << " " << maxi << "\n";

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