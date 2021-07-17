#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
// using namespace __gnu_pbds;
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
#define inf 1e18
// #define mp  map<int,int>

// typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// int grid[1000][1000];

// Obtain Maximum Number from an array..

bool cmp(int a, int b)
{
	string s1 = to_string(a);
	string s2 = to_string(b);
	return s1 + s2 > s2 + s1;
}

void solve()
{
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), cmp);

	for (int i : a)
		cout << i;
	cout << "\n";
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