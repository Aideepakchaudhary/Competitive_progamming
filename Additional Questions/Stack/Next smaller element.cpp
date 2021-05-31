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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vi nse(n);  // next smaller

	stack<int>s;

	// s.push(0);

	for (int i = 0; i < n; i++)
	{
		if (s.empty()) {
			s.push(i);
			continue;
		}

		if ( a[s.top()] > a[i]) {

			while (a[s.top()] > a[i] and s.size() > 0) {
				cout << i << " ";
				nse[s.top()] = i;
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		nse[s.top()] = -1;
		s.pop();
	}
	for (int i : nse)
		cout << i << " ";

	return 0;
}