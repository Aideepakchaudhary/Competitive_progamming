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

// https://cses.fi/problemset/task/1646/


int arr[200000];
const int b = 450;

int sum = 0;

void add(int id) {
	sum += arr[id];
}

void remove(int id) {
	sum -= arr[id];
}


class query
{
public:
	int l, r, i;
	query(int lt = 0, int rt = 0, int id = 0)
	{
		l = lt - 1;
		r = rt - 1;
		i = id;
	}

	bool operator <(const query &q2)
	{
		return (l / b < q2.l / b) or
		       (l / b == q2.l / b and
		        ((l / b & 1) ? r < q2.r : r > q2.r));
	}
};


void solve()
{
	int n, q; cin >> n >> q;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	std::vector<query> queries(q);

	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		queries[i] = query(l, r, i);
	}
	sort(queries.begin(), queries.end());

	vi ans(q);

	int l = 0, r = -1;

	for (query &q : queries)
	{
		while (l > q.l)
			add(--l);
		while (r < q.r)
			add(++r);
		while (l < q.l)
			remove(l++);
		while (r > q.r)
			remove(r--);

		ans[q.i] = sum;
	}

	for (int i : ans)
		cout << i << "\n";
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