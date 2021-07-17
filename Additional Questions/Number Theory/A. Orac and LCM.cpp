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
typedef long long ll;

// typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

//  https://codeforces.com/contest/1349/problem/A

vi prime_factor(int n) {
	vi result;
	for (int i = 2; i * i <= n; i++) {
		if (n % i)
			continue;

		result.pb(i);
		while (!(n % i))
			n /= i;
	}
	if (n > 1)
		result.pb(n);

	return result;
}


vi a(100000);
map<int, int>cnt;

void add(int p, int n) {
	vi pw;

	for (int i = 0; i < n; i++) {
		int num = a[i], temp = 0;

		while (!(num % p))
			num /= p, temp++;

		pw.pb(temp);
	}
	sort(pw.begin(), pw.end());
	cnt[p] = pw[1];
}

void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vi p = prime_factor(a[0]);

	for (int i : p)
		add(i, n);

	p = prime_factor(a[1]);

	for (int i : p)
		add(i, n);

	int ans = 1;

	for (auto p : cnt) {
		int pw = p.ss;
		while (pw--)
			ans *= p.ff;
	}

	cout << ans << "\n";
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