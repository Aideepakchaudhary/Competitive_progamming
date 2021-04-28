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

question link: https://www.codechef.com/problems/KNPSK

void solve()
{
	int n; cin >> n;
	int m = 0;
	vi one(n), two(n);

	// Initialize..

	for (int i = 0; i < n; i++) {
		int t, cost; cin >> t >> cost;
		if (t == 1)
			one.pb(cost);
		else
			two.pb(cost);
		m += t;
	}

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());

	// For Even m..

	int cur = 0;
	vi ans(m + 1), ONE = one, TWO = two;

	for (int i = 2; i <= m; i += 2) {
		int cost1 = 0, cost2 = 0;
		if (two.size() >= 1)
			cost2 = two.back();

		int flag = 1;
		if (one.size() > 1) {
			cost1 = one.back();
			cost1 += one[one.size() - 2];
		}
		else if (one.size() >= 1)
			cost1 += one.back(), flag = 2;

		if (cost2 >= cost1) {
			cur += cost2;
			two.pop_back();
		}
		else {
			cur += cost1;
			if (flag == 1)
				one.pop_back(), one.pop_back();
			else
				one.pop_back();
		}
		ans[i] = cur;
	}

	// For Odd m..
	one = ONE, two = TWO;
	cur = 0;
	if (one.size() >= 1) {
		cur = one.back();
		one.pop_back();
	}
	ans[1] = cur;

	for (int i = 3; i <= m; i += 2) {
		int cost1 = 0, cost2 = 0;

		if (two.size() >= 1)
			cost2 = two.back();

		int flag = 1;
		if (one.size() > 1) {
			cost1 = one.back();
			cost1 += one[one.size() - 2];
		}
		else if (one.size() >= 1)
			cost1 += one.back(), flag = 2;

		if (cost2 >= cost1) {
			cur += cost2;
			two.pop_back();
		}
		else {
			cur += cost1;
			if (flag == 1)
				one.pop_back(), one.pop_back();
			else
				one.pop_back();
		}

		ans[i] = cur;
	}

	for (int i = 1 ; i <= m; i++)
		cout << ans[i] << " ";
	cout << '\n';

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// int t; cin >> t;
	// while (t--)
	solve();
	return 0;
}