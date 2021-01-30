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
	int n, k; cin >> n >> k;
	int a[n];
	int no = 0, sec = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == -1)
			no++;
		else
			sec = max(sec, a[i]);
	}
	int solve = n - no;
	// cout << ceil(n / 2) << " \n";
	int temp = 0;
	if (n % 2 == 0)
		temp = n / 2;
	else
		temp = n / 2 + 1;

	if (solve < temp) {
		cout << "Rejected\n";
	}
	else if (sec > k) {
		cout << "Too Slow\n";
	}
	else if (sec <= 1 and solve == n) {
		cout << "Bot\n";
	}
	else {
		cout << "Accepted\n";
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