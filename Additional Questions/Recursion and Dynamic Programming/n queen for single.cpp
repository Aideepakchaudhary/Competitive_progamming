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
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
int n;
int q[11][11];

bool under_attack(int r, int c)
{
	for (int i = 0; i < c; i++) {
		if (q[r][i])
			return true;
	}
	for (int i = 0; i < r; i++) {
		if (q[i][c])
			return true;
	}
	for (int i = r, j = c; min(i, j) >= 0 ; i--, j--) {
		if (q[i][j])
			return true;
	}
	for (int i = r, j = c; i >= 0 and j < n ; i--, j++) {
		if (q[i][j])
			return true;
	}
	return false;
}


bool backtrack(int r =  0)
{
	if (r == n) {
		return true;
	}

	for (int c = 0; c < n; c++)
	{
		if (!under_attack(r, c)) {
			q[r][c] = 1;

			bool done = backtrack(r + 1);

			if (done)
				return true;
			q[r][c] = 0;
		}
	}
	return false;

}


void solve()
{
	cin >> n;

	bool check = backtrack();

	if (check)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << q[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
		cout << "Not possible\n";
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