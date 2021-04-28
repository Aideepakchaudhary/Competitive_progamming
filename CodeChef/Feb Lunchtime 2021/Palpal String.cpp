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
	// int n; cin >> n;
	string s; cin >> s;
	unordered_map<char, int>mp1;
	vi v(26);
	for (int i = 0; i < s.length(); i++) {
		v[s[i] - 'a']++;
	}
	int odd = 0, even = 0;
	for (int i = 0; i < 26; i++) {
		even += v[i] / 2;
		odd += v[i] % 2;
	}
	even *= 2;
	// cout << even << " " << odd << " ";
	if (odd <= even / 2) {
		cout << "YES\n";
	}
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