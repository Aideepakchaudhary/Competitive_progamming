#include <bits/stdc++.h>
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
#define mp  unordered_map<int,int>

// vi sieve()
// {
// 	int N = 100000000;
// 	vi visited(N, 0);
// 	vi result;
// 	for (int i = 2; i * i < N; i++) {
// 		if (!visited[i]) {
// 			for (int j = i * i; j <= N; j += i)
// 				visited[j] = 1;
// 		}
// 	}
// 	for (int i = 2; i <= N; i++) {
// 		if (!visited[i])
// 			result.pb(i);
// 	}
// 	return result;
// }

void solve() {
	// vi factor = sieve();
	int t; cin >> t;
	// mp mp1;s
	while (t--)
	{
		int l, r; cin >> l >> r;
		cout << "1000003\n";
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