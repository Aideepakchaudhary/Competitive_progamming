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

void evaluate(stack<int> &s, char ch)
{
	int b = s.top();
	s.pop();
	int a = s.top();
	s.pop();
	switch (ch)
	{
	case '+': s.push(a + b);
		break;
	}
	switch (ch)
	{
	case '-': s.push(a - b);
		break;
	}
	switch (ch)
	{
	case '*': s.push(a * b);
		break;
	}
	switch (ch)
	{
	case '/': s.push(a / b);
		break;
	}
}


void solve() {
	string s; cin >> s;
	stack<int> operands;
	for (char ch : s) {
		if (isdigit(ch)) {
			operands.push(ch - '0');
		}
		else
			evaluate(operands, ch);
	}
	cout << operands.top() << "\n";
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