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
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			if (s[i] != 'a')
				cout << "a";
			else
				cout << "b";
		}
		else {
			if (s[i] != 'z')
				cout << "z";
			else
				cout << "y";
		}
	}
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