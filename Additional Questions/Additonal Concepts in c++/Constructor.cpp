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


class ComplexNumber {
public:
	int real, img;
	int *ptr;

	// Constructor Overloading.
	/*****************/

	ComplexNumber(): real(0), img(0) {};   // Constructor Overloading..assign 0 to real and img

	ComplexNumber(int real) {     // if we pass only argument then this constructor is called.
		this->real = real;
	}

	ComplexNumber(int real, int img) {
		//real = real;   // this is also correct..
		this->real = real;
		this->img = img;
	}

	/****************************/

	int get() {
		return this->real;
	}

	// Funcition overloading.
	/*********************************/
	void set_real() {
		this->img = 20;
	}

	void set_real(int x) {
		this->real = x;
	}
	/*********************************/

	void display() {
		cout << this->real << endl;
		cout << this->img << endl;
	}

	int show_real();

	ComplexNumber(ComplexNumber& s) {  // Custom Copy Constructor
		this->real = s.real;
		this->img = s.img;
		this->ptr = new int;
		*ptr = *(s.ptr);
	}
};

int ComplexNumber :: show_real() {   // :: scope resolution opereator
	real = 10;
	return real;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ComplexNumber c(1);
	c.display();
	cout << c.show_real() << endl;

	// Copy Constructors.

	// 1.  Shallow Copy.
	ComplexNumber r;
	r = c;
	r.display();
	cout << r.show_real() << endl;

	// 2. Deep Copy
	int x = 45;
	c.ptr = &x;

	ComplexNumber d = c;

	d.real = 50;
	cout << d.real << " " << d.img << endl;
	cout << c.real << " " << c.img << endl;
	cout << c.ptr << " " << d.ptr << endl;
	cout << *c.ptr << " " << *d.ptr << endl;

	return 0;
}

/* outputs:

1
18045530405564205
10
10
18045530405564205
10
50 18045530405564205
10 18045530405564205
0x61fed8 0x1037aa0
45 45

*/