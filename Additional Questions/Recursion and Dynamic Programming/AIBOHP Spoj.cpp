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

string s;
int dp[6200][6200];


int get_pal(int i, int j)
{

	if (i == j)
		return 0;

	if (j < i)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	else {
		if (s[i] != s[j]) {
			int a = get_pal(i + 1, j) + 1;
			int b = get_pal(i, j - 1) + 1;
			dp[i][j] = min(a, b);
		}
		else
			dp[i][j] = get_pal(i + 1, j - 1);
	}
	return dp[i][j];

}


void solve()
{
	memset(dp, -1, sizeof(dp));
	cin >> s;
	int n = s.size();
	cout << get_pal(0, n - 1) << "\n";
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