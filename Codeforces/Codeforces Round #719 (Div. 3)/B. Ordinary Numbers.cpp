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
	string d = to_string(n);
	int sz = d.size();
	int ans = (sz - 1) * 9;
	int tmp = 1;
	int i = 1;


	while (i <= sz - 1) {
		tmp = tmp * 10 + 1;
		i++;
	}
	int p = tmp;
	while (tmp <= n)
	{
		tmp += p;
		ans++;
	}

	cout << ans << "\n";
	// while

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