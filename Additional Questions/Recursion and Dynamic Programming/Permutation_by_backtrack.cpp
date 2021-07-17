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

void get_permutation1(vi &cur, vi &mark)
{
	if (cur.size() == n ) {
		for (int i : cur)
			cout << i << " ";
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!mark[i])
		{
			// Do the stuff..
			cur.pb(i);
			mark[i] = 1;

			get_permutation1(cur, mark);

			// Undo the stuff..
			cur.pop_back();
			mark[i] = 0;
		}
	}

}

// By swaping in real array..
void get_permutation2(vi &arr, int i = 0)
{
	if (i == arr.size()) {
		for (int j : arr)
			cout << j << " ";
		cout << "\n";
		return;
	}
	for (int j = i; j < arr.size(); j++) {
		swap(arr[i], arr[j]);
		get_permutation2(arr, i + 1);
		swap(arr[i], arr[j]);
	}
}

void solve()
{
	// cin >> n;
	// vi marked(n + 1), cur;
	// get_permutation1(cur, marked);

	vi arr{1, 2, 3};

	get_permutation2(arr);
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