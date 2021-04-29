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

// Question Link: https://www.codechef.com/UAGA001/problems/FGFS

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
	return a.ss.ss < b.ss.ss;
}

void solve()
{
	int n, k; cin >> n >> k;
	vector<pair<int, pair<int, int>>> v;

	// Taking Input...

	for (int i = 0; i < n; i++) {
		int st, ft, comp; cin >> st >> ft >> comp;
		v.pb({comp, {st, ft}});
	}

	// Sorting on the basis of finish time...
	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	mp m;
	if (n == 0) {
		cout << "0\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (m.find(v[i].ff) == m.end()) {
			ans++;
			m[v[i].ff] = v[i].ss.ss;
		}

		// K compartment already occupied...
		else {
			if (m[v[i].ff] <= v[i].ss.ff) {
				ans++;
				m[v[i].ff] = v[i].ss.ss;
			}
		}
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