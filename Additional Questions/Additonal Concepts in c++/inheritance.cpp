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


class Counter {
protected:
	int count;   // Data member

public:
	Counter(): count(0) {};

	Counter(int c) : count(c) {};

	int get_count() {   // Data Function..
		return count;
	}

	Counter operator ++() {
		return Counter(++this->count);
	}
};

class CounterDn : public Counter {    // Child Class....
public:
	CounterDn() {};

	CounterDn (int c) : Counter(c) {
		cout << "Child is called\n";
	}
	Counter operator --() {
		return Counter(--this->count);
	}
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	CounterDn c(5);
	cout << c.get_count() << "\n";
	++c;

	cout << c.get_count() << "\n";
	--c;

	cout << c.get_count() << "\n";

	return 0;
}

/*  Solution :

  Child is called
5
6
5

*/