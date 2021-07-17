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

// https://codeforces.com/problemset/problem/546/D

const int n = 5000001;

int pre[n + 5];
int pr[n + 5];

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;

	for (int i = 2; i <= n; i++) {
		if (!pr[i]) {
			for (int j = i; j <= n; j += i) {
				int num = j;
				pr[j] = 1;
				while (num % i == 0) {
					num /= i;
					pre[j]++;

				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		pre[i] += pre[i - 1];
	}
	while (t--)
	{
		int a, b; cin >> a >> b;
		cout << pre[a] - pre[b] << "\n";
	}

	return 0;
}