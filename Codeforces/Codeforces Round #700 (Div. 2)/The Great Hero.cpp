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

void solve() {
	int A, B, n;
	cin >> A >> B >> n;
	// vector< pair <int, int> > m;
	int m_power[n], m_health[n];
	for (int i = 0; i < n; i++) {
		cin >> m_power[i];
	}
	for (int i = 0; i < n; i++)
		cin >> m_health[i];
	vector< pair <int, int> > m;
	for (int i = 0; i < n; i++)
		m.pb(make_pair(m_power[i], m_health[i]));
	sort(m.begin(), m.end());
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		int val1 = B / m[i].ff , val2 = m[i].ss / A;
		if (B % m[i].ff != 0 )
			val1++;
		if (m[i].ss % A != 0 )
			val2++;
		if (val2 > val1) {
			flag = true;
			break;
		}

		B -= val2 * m[i].ff;
		if (B <= 0 and i != n - 1) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
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