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

// Infix to postfix...

int pres(char ch) {
	if (ch == '/' or ch == '*')
		return 2;
	if (ch == '+' or ch == '-')
		return 1;
	return -1;
}


void solve() {
	string s; cin >> s;  // infix: a+b,  postfix: ab+;
	string ans;
	stack<char> operators;
	for (char ch : s)
	{
		if (isalpha(ch))
			ans += ch;

		else if (ch == '(')
			operators.push(ch);

		else if (ch == ')') {
			while (operators.top() != '(')
				ans += operators.top(), operators.pop();
			operators.pop();
		}
		else {
			while (operators.size() and pres(operators.top()) >= pres(ch))
				ans += operators.top(), operators.pop();
			operators.push(ch);
		}

	}
	while (operators.size())
		ans += operators.top(), operators.pop();

	for (char ch : ans)
		cout << ch << " ";
	cout << "\n";
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