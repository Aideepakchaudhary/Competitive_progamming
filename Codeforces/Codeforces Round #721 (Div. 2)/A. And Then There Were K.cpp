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

int square(int n)
{
	int a = 2;
	while ((a * 2) <= n)
		a *= 2;
	return a;
}

void solve()
{
	int n; cin >> n;
	int tmp = square(n);
	tmp--;
	// cout << tmp << " ";
	if (n == tmp) {
		cout << "0\n";
	}
	else {
		cout << tmp << "\n";
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}