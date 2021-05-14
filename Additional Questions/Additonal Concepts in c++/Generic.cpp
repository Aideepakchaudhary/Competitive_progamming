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


// Function templete
template<class T>
T abs_count(T n) {
	return (n < 0) ? -n : n;
};


class Person {
public:
	string name;
	int age;
	Person() {}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

template <class Type>
class Stack {
public:
	Type st[10];
	int top;
	Stack() {
		this->top = -1;
	}

	void push(Type var) {
		this->st[++this->top] = var;
	}

	Type pop() {
		return this -> st[this->top--];
	}
	Type peek();
};

template<class Type>
Type Stack<Type>::peek() {   // scope resolution
	return st[top];
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Person p1("Sanket", 23);
	Person p2("Santanu", 20);
	Person p3("Jatin", 20);
	Stack<Person> s1;
	s1.push(p1);
	s1.push(p2);
	s1.push(p3);

	cout << s1.pop().name << endl;

	cout << s1.peek().name << endl;


	return 0;
}