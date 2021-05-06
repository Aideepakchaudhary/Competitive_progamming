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
	int tmp = n * n;

	if (n == 1) {
		cout << "1\n";
		return;
	}
	else if (n == 2) {
		cout << "-1\n";
		return;
	}

	int front = 1, last = n * n;

	vector<int> v[n + 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((i + j) % 2 == 0) {
				v[i].pb(front);
				front++;
				// cout << v[i][j] << " ";
			}
			else {
				v[i].pb(last);
				// cout << v[i][j] << " ";
				last--;
			}
		}
		cout << "\n";
	}
	// cout << v[n][n] << "\n";
	swap(v[1][1], v[n][n - 1]);
	// cout << v[2][3] << "\n";

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << v[i][j] << " ";

		cout << "\n";
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