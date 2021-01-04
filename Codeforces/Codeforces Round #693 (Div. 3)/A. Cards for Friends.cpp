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
	int w, h, n; cin >> w >> h >> n;
	if (w & 1 and h & 1 and n > 1 ) {
		cout << "NO\n";
		return;
	}
	int count = 1;
	while (w > 0) {
		if (w % 2 == 0) {
			count *= 2;
			w = w / 2;
		}
		else {
			break;
		}
	}
	while (h > 0) {
		if (h % 2 == 0) {
			count *= 2;
			h = h / 2;
		}
		else {
			break;
		}
	}
	if (count >= n) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
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
