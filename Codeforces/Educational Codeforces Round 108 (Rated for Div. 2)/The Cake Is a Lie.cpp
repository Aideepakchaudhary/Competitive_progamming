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
	int n, m, k; cin >> n >> m >> k;

	int maxi = max(n, m);
	int cost = maxi - 1;

	int mini = min(n, m);

	for (int i = 1; i < mini; i++) {
		cost += maxi;
	}

	// cout << cost << " ";
	if (cost == k) {
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