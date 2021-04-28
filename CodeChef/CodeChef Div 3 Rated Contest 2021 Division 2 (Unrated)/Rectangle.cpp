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
	int n, m; cin >> n >> m;
	string s[n];
	int total_one = 0;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1')
				total_one++;
		}
	}

	// Check intial position of 1...
	int x1 = 0, y1 = 0, x2 = 0, y2 = m - 1;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				x1 = i;
				y1 = j;
				ok = true;
				break;
			}
		}
		if (ok)
			break;
	}

	// Check Final position of 1 in same row...
	for (int i = y1; i < m; i++)
	{
		if (s[x1][i] != '1') {
			y2 = i - 1;
			break;
		}
	}

	int count = 0;
	bool flag = false;
	int temp = -1;
	for (int i = x1; i < n; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (s[i][j] == '1') {
				count++;
				temp = j;
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	// cout << y2 << "\n";
	if (count == total_one and temp == y2)
		cout << "YES\n";
	else
		cout << "NO\n";
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