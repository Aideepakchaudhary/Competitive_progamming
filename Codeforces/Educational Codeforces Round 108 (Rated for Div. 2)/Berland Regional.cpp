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
	int n; cin >> n;
	vi lst[n + 1];
	vi u(n);
	for (int i = 0; i < n; i++)
		cin >> u[i], u[i]--;

	for (int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		lst[u[i]].pb(tmp);
	}

	for (int i = 0; i < n; i++) {
		sort(lst[i].rbegin(), lst[i].rend());
	}

	vi pre[n];

	for (int i = 0; i < n; i++)
	{
		if (lst[i].size()) {
			// int sum = 0;
			pre[i].pb(lst[i][0]);
			for (int j = 1; j < lst[i].size(); j++ ) {
				// sum += lst[i][j];
				// pre[i].pb(sum);
				pre[i].pb(pre[i][pre[i].size() - 1] + lst[i][j]);
			}
			// reverse(pre[i].begin(), pre[i].end());
		}
	}

	vi ans(n + 1);

	for (int i = 0; i < n; i++)
	{
		if (lst[i].size()) {
			for (int j = 1; j < lst[i].size() + 1; j++)
				ans[j] += pre[i][(lst[i].size() / j) * j - 1];
		}
	}

	for (int i = 1; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";

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