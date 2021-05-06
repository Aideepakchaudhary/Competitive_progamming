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
	unordered_map<int, int> m;
	bool flag = false;
	m[s[0] - 'A']++;
	for (int i = 1 ; i < n; i++) {
		if (s[i] != s[i - 1] and m[s[i] - 'A'] >= 1) {
			flag = true;
			break;
		}
		else {
			m[s[i] - 'A']++;
		}

	}
	if (flag)
		cout << "NO\n";
	else
		cout << "YES\n";
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