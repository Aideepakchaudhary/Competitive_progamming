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


// https://www.spoj.com/problems/NFACTOR/

const int n = 1000000;

int dp[n + 5][11];
int pr[n + 5];
int spf[n + 5]; // smallest prime factor..

void sieve()
{
	pr[0] = 1;
	pr[1] = 1;
	spf[1] = 1;

	for (int i = 2; i * i <= n; i++)
	{
		if (pr[i])
			continue;

		spf[i] = i;
		for (int j = i * i; j <= n; j += i) {
			pr[j] = 1;
			if (spf[j] == 0)
				spf[j] = i;
		}
	}
}

void get_factor(int x)
{
	int t = x;
	vi fact;

	while (x > 1) {

		int temp = spf[x];

		while (x % temp == 0)
			x /= temp;

		fact.pb(temp);
	}

	dp[t][fact.size()]++;
}

void pre()
{
	for (int i = 1; i <= n; i++)
		get_factor(i);
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	memset(dp, 0, sizeof(dp));

	sieve();
	pre();

	for (int i = 1; i <= n; i++) {
		for (int  j = 0; j <= 10; j++) {
			dp[i][j] += dp[i - 1][j];
		}
	}

	while (t--)
	{
		int a, b, k; cin >> a >> b >> k;
		cout << dp[b][k] - dp[a - 1][k] << "\n";
	}

	return 0;
}