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

class node {
public:
	node *child[2];
	int cnt[2];    // cnt[0] means 0(left child) and cnt[1] means 1(right child); it denotes left m kitne child h and right m kitne child h
	node() {
		child[0] = child[1] = NULL;
		cnt[0] = cnt[1] = 0;
	}
};

class Trie
{
public:
	node *root =  new node;

	void insert(int num) {
		node *cur = root;
		for (int i = 29; i >= 0; --i) {    // the number should be <= 1e9;

			int b = (num >> i) & 1;

			if (cur->child[b] == NULL)  // if doen't exit then form a new child
				cur->child[b] = new node;

			cur->cnt[b]++;
			cur = cur->child[b];

		}
	}
	int count(int num) {  // How many num present

		node *cur = root;

		for (int i = 29; i >= 1; i--) {  // we run this loop at 1 not 0 because at 0 it is a leaf node and its right and left cnt is also 0;
			int b = (num >> i) & 1;

			if (cur->child[b] == NULL)   // if this is not available
				return 0;

			cur = cur->child[b];
		}

		return cur->cnt[num & 1];
	}

	void erase(int num) {

		vector<node*> del;
		node *cur = root;

		for (int i = 29; i >= 0; i--)
		{
			int b = (num >> i) & 1;

			cur->cnt[b]--;
			node *go_to = cur->child[b];

			if (cur->cnt[b] == 0) {
				cur->child[b] = NULL;
				del.pb(go_to);
			}

			cur = go_to;
		}

		for (int i = 0; i < del.size(); i++)
			delete del[i];
	}
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	Trie t;
	t.insert(1000);
	t.insert(1000);
	t.insert(1000);
	cout << t.count(1000) << "\n";

	t.erase(1000);
	cout << t.count(100) << "\n";
	return 0;
}