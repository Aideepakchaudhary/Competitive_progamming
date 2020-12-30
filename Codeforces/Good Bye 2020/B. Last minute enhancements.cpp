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
	int n; cin >> n;
	int a[n];
	mp mp1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mp1[a[i]] == 1) {
			mp1[a[i] + 1]++;
		}
		mp1[a[i]]++;
	}
	int result = 0;
	// for (int i =0; i<mp1.size(); i++) {
	// 	if(mp1[i])
	// }
	// for (auto x : mp1) {
	// 	if (x.ss > 1) {
	// 		result += 2;
	// 	}
	// 	else {
	// 		result++;
	// 	}
	// }

	cout << mp1.size() << "\n";

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