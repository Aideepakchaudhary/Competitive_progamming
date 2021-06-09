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

vi get_prime(int l, int r)
{
	vi result(r - l + 1, 1);

	for (int i = 2; i * i <= r; i++) {
		int num = ((l - i + 1) / i) * i;

		for (int j = max(i * i, num); j <= r; j += i) {
			result[j - l] = 0;
		}
	}

	vi ans;
	for (int i = l; i <= r; i++) {
		if (result[i - l])
			ans.push_back(i);
	}
	return ans;
}


void solve()
{
	int l, r; cin >> l >> r;
	vi prime = get_prime(l, r);

	for (int i : prime)
		cout << i << " ";
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