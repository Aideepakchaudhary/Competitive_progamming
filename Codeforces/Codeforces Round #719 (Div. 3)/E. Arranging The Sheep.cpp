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
	string s; cin >> s;
	int first = 0;
	vi pos;
	for (int i = 0; i < n; i++)
		if (s[i] == '*') {
			first++;
			pos.pb(i);
		}

	if (pos.size() == 0) {
		cout << "0\n";
		return;
	}
	int  mid = first / 2;

	int tmp = 1;
	int ans = 0;

	for (int i = 0; i < mid; i++)
	{
		ans += pos[mid] - pos[i] - tmp;
		tmp++;
	}
	tmp = 1;

	for (int i = mid + 1 ; i < first ; i++)
	{
		ans += pos[i] - pos[mid] - tmp;
		tmp++;
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