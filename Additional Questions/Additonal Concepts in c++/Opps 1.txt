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


class Product {
public:

	string name;     // Data members..
	int cost, discount;

	Product() {}     // default constructor...

	Product(string name, int c, int d) {
		this->name = name;
		this->cost = c;
		this->discount = d;
	}

	Product(string name, int c) {
		this->name = name;
		this->cost = c;
	}

	void display() {
		cout << name << " " << cost << "\n";
	}

	void setter(int c) {   // Setter
		if (c < 0 )
			return;
		cost = c;
	}

	int getter() {   // Getter
		return cost;
	}

	Product * get_this() {   // returning this pointer...
		return this;
	}

};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Product iphone("iphone 11", 25000, 26);
	Product shirt("Bufello", 2500);
	iphone.display();

	cout << iphone.getter() << "\n";

	// This Pointer....

	Product *p = iphone.get_this();

	p->name = "12 pro";
	p->display();

	return 0;
}