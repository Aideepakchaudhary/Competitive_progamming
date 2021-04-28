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
// #define mp  unordered_map<int,int>

// Codeforces marking Pattern...


bool cmp(pair<int, int > a, pair<int, int > b) {
	return a.first < b.first;
}

void solve()
{
	vector<pair<int, int > > v;
	int n; cin >> n;
	vi points(n), decay(n), time(n);

	for (int i = 0; i < n; i++)
		cin >> points[i] >> decay[i] >> time[i];

	for (int i = 0; i < n; i++)
		v.pb({time[i] / decay[i], i});

	sort(v.begin(), v.end(), cmp);

	int score = 0, finish = 0;

	for (auto x : v) {
		cout << x.ff << ' ';
	}
	cout << '\n';

	for (int i = 0; i < n; i++)
	{

		score += points[v[i].ss] - decay[v[i].ss] * finish;
		finish += time[v[i].ss];
		// cout << score << " ";

	}
	cout << score << "\n";
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