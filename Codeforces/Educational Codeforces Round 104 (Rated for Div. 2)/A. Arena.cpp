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
// #define mp  unordered_map<int,int>


void solve() {
	int n; cin >> n;
	int a[n];
	int mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mini = min(mini, a[i]);
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != mini)
			count++;
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
	{
		solve();
	}
	return 0;
}