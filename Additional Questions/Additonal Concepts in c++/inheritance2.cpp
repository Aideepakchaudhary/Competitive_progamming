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

class Stack {
protected:
	int st[10];
	int top;
public:
	Stack() {
		this->top = -1;
	}

	void push(int n) {
		this->st[++this->top] = n;
	}

	int pop() {
		return this->st[this->top--];
	}

	int peek() {
		return this->st[this->top];
	}
};

// Method Overriding.
class Stack2 : Stack {
public:
	void push(int v) {
		if (this->top >= 9) {
			cout << "Stack is full\n";
			exit(1);
		}
		this->st[++this->top] = v;
	}

	int peek() {
		return this->st[this->top];
	}

	int pop() {
		if (this->top < 0) {
			cout << "Error! Stack is empty.\n";
		}
		Stack :: peek();
		return Stack::pop();
	}
};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Stack2 s2;
	s2.push(11);
	s2.push(12);
	s2.push(13);
	cout << s2.pop() << endl;
	cout << s2.peek() << endl;

	return 0;
}