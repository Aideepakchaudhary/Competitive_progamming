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


class Test {
public:
	int count;
	int arr[100];

	Test(): count(0) {};

	Test(int c): count(c) {};

	void get_count() {
		cout << count << " \n";
	}

	// Overload Uniary Operators.

	// case 1: prefix ++

	Test operator ++() {
		++this->count;
		return Test(this->count);
	}

	// Case 2:  postfix ++

	// Test operator ++(int) {
	// 	return Test(this->count++);
	// }

	// Case 3: Binary Operators

	Test operator +(Test v) {
		int temp = this->count + v.count;
		return Test(temp);
	}

	// Case 4: comparison operator

	bool operator < (Test v) {
		bool b = this->count < v.count;
		return b;
	}

	// Case 5: assignment Operators..

	void operator += (Test v) {
		this->count += v.count;
	}

	// case 6: subscript operator([])

	int& operator [](int n) {
		if (n < 0 or n >= 100) exit(1);
		return this->arr[n];
	}

	// operator that cant be overloaded
	/*
		1. (.) dot operator
		2. (?:) ternary operator
		3. (::) scope resolution operator
		4. (.*) pointer to member
		5. (sizeof) size of operator
		6. (typeid)
	*/
};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Test t;
	t.get_count();

	Test x = ++t;
	x.get_count();

	Test c = x + t;
	c.get_count();

	bool b = c < t;
	c += t;
	cout << b << "\n";
	c.get_count();

	c[2] = 10;

	return 0;
}


/* Solution :

0 
1 
2 
0
3 

*/