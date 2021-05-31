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
#define ld long double
// #define mp  unordered_map<int,int>

// https://www.codechef.com/UAPRAC/problems/RNDWAEZ

ld find_dist(int x1, int y1, int x2, int y2) {
	return sqrtl(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

void solve()
{
	int n; cin >> n;
	ld no_of_perm = 0;
	vi x(n), y(n);

	for (int i = 0 ; i < n; i++)
		cin >> x[i] >> y[i];

	int qx, qy, rx, ry; cin >> qx >> qy >> rx >> ry;
	ld max_dist = find_dist(qx, qy, rx, ry);

	// find starting point in array..

	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (rx == x[i] and ry == y[i]) {
			idx = i;
			break;
		}
	}

	if (idx != -1) {
		x.erase(x.begin() + idx);
		y.erase(y.begin() + idx);
		n--;
	}

	vi perm(n);
	for (int i = 0; i < n; ++i) perm[i] = i;

	ld valid_dist = 0.0;
	ld ans = 0.0;
	cout.precision(8);

	do {
		for (int i = 1; i < n; i++)
			ans += find_dist(x[perm[i]], y[perm[i]], x[perm[i - 1]], y[perm[i - 1]]);

		// distance from rx/ry to first number..
		ans += find_dist(rx, ry, x[perm[0]], y[perm[0]]);

		if (ans <= max_dist)
			valid_dist++;

		no_of_perm++;
		ans = 0.0;
	} while (std::next_permutation(perm.begin(), perm.end()));

	// cout << max_dist << "\n";

	ld result = valid_dist / no_of_perm;
	cout << std::fixed << result << "\n";
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