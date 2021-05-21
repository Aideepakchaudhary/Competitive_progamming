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

bool ispel(string s)
{
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	int zero = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '0')
			zero++;

        // easy version..
	if (ispel(s)) {  
		if (zero == 1) {
			cout << "BOB\n";
			return;
		}
		if (zero & 1) {
			cout << "ALICE\n";
		}
		else
			cout << "BOB\n";
	}
        // hard version..
	else
	{
		if (zero == 2 and n & 1 and s[n / 2] == '0')
			cout << "DRAW\n";
		else
			cout << "ALICE\n";
	}

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}