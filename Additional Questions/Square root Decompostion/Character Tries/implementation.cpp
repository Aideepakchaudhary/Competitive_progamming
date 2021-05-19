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

class node
{
public:
	int pre, end;
	map<char, node*> child;
	node() : pre(0), end(0) {};
};


class trie
{
	node *root;
public:

	trie() : root(new node) {}

	void insert(const string & s)
	{
		node *cur = root;

		for (char c : s)
		{
			cur->pre++;
			if (!(cur->child).count(c))
				cur->child[c] = new node;

			cur =  cur->child[c];
		}

		cur->pre++;
		cur->end++;
	}

	int count(const string &s)   // no of times this string occur...
	{
		node * cur = root;

		for (char c : s) {

			if (cur->pre == 0)
				return 0;

			if (!cur->child.count(c))
				return 0;

			cur = cur->child[c];
		}

		return cur->end;
	}
	int erase(const string &s)
	{
		if (!count(s))
			return 0;

		node *cur = root;

		for (char ch : s)
		{
			cur->pre--;
			cur = cur->child[ch];
		}

		// for last node
		cur->pre--;
		cur->end--;

		return 1;
	}
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<string> v = {"the", "a", "there", "answer", "any", "bye", "by", "their", "any"};
	trie t;

	for (auto s : v)
		t.insert(s);

	t.erase("the");
	cout << t.count("there") << "\n";
	return 0;
}