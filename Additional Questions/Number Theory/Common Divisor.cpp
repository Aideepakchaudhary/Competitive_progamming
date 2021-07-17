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
#define mp  map<int,int>

// typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

const int lim = 1000001;
int pre[lim];

void solve()
{
	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre[a[i]]++;
	}

	int count = 0;

	for (int i = lim; i >= 0; i--)
	{
		count = 0;
		for (int j = i; j <= lim; j += i)
			count += pre[j];

		if (count > 1 ) {
			cout << i << " ";
			return;
		}
	}
	cout << "1\n";


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