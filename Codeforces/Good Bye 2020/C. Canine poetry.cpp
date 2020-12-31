#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
#define ff first
#define ss second
#define pi pair<int,int>
#define lcm(a,b)  a*b / (__gcd(a,b))
#define mp  unordered_map<int,int>


void solve()
{
	string s; cin >> s;
	int count  = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i + 1] and s[i] != ')' and i + 1 < n) {
			count++;
			s[i + 1] = ')';
		}
		if (s[i] == s[i + 2] and s[i] != ')' and i + 2 < n) {
			count++;
			s[i + 2] = ')';
		}
	}
	cout << count << "\n";
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