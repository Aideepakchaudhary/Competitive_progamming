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

// Question  Link: https://www.spoj.com/problems/PRATA/


int max_parathe(int time_alloted, int r) {  // no of maximum paratha cooked in given time alloted.
	int beg = 0, end = time_alloted, ans = 0;
	while (beg <= end) {
		int mid = (beg + end) / 2; // check for mid no. of parathas
		int time_for_mid = (r * (mid + 1) * mid) / 2;
		if (time_for_mid <= time_alloted)
			ans = mid, beg = mid + 1;
		else
			end = mid - 1;
	}
	return ans;
}

int no_of_p(int time, int *r, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += max_parathe(time, r[i]);
	}
	return ans;
}


void solve() {
	int p, n; cin >> p >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int beg = 0, end = a[0] * p * (p + 1) / 2, ans = 0;
	while (beg <= end) {
		int mid = (beg + end) / 2;
		if (no_of_p(mid, a, n) >= p) // if no of paratha for the mid is greater eqaul to no. of paratha needed then we search for the smaller time.
			end = mid - 1, ans = mid;
		else
			beg = mid + 1;
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