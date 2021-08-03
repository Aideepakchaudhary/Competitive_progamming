#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
#define ff first
#define ss second
#define pi pair<int,int>
#define pii std::vector<pi>
#define lcm(a,b)  a*b / (__gcd(a,b))
#define debug(a)  cout<<a<<" "
#define mp  map<int,int>

int pal[5000][5000];
int dp[5000][5000];
string s;

// Recursive Method..

bool is_pal(int i, int j)
{
	if (i == j)
		return 1;
	if (i == j - 1)
		return (s[i] == s[j]);

	if (pal[i][j] != -1)
		return pal[i][j];

	else {
		return pal[i][j] =  is_pal(i + 1, j - 1) and (s[i] == s[j]) ? 1 : 0;
	}
}



int get_pal(int i, int j)
{
	if (i == j)
		return 1;
	if (i == j - 1)
		return 2 + is_pal(i, j);

	if (dp[i][j] != -1)
		return dp[i][j];

	else {
		dp[i][j] = get_pal(i, j - 1) + get_pal(i + 1, j) - get_pal(i + 1, j - 1) + is_pal(i, j);
	}
	return dp[i][j];
}


void solve()
{
	memset(dp, -1, sizeof(dp));
	memset(pal, -1, sizeof(pal));
	cin >> s;
	int q; cin >> q;

	while (q--) {
		int i, j; cin >> i >> j;
		cout << get_pal(i - 1, j - 1) << "\n";
	}
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