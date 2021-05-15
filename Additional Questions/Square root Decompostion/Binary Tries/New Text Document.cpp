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

// Question Link: https://www.hackerrank.com/challenges/maximum-xor/problem

class Node {
public:
	Node *child[2];
	int cnt[2];
	Node()
	{
		child[0] = child[1] = NULL;
		cnt[0] = cnt[1] = 0;
	}
};

class trie {
public:
	Node* root = new Node;

	void insert(int num) {
		Node *cur = root;

		for (int i = 29; i >= 0; --i) {
			int b = (num >> i) & 1;
			cur->cnt[b]++;

			if (cur -> child[b] == NULL) {
				cur->child[b] = new Node;
			}

			cur = cur -> child[b];
		}
	}

	int max_xor(int num)
	{
		int result = 0;

		Node *cur = root;

		for (int i = 29; i >= 0; i--) {
			int b = (num >> i) & 1;

			if (cur->child[!b]) {
				result += (1 << i);
				cur = cur->child[!b];
			}

			else
				cur = cur->child[b];
		}
		return result;
	}
};


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	trie t;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		t.insert(tmp);
	}

	int q; cin >> q;
	while (q--)
	{
		int p; cin >> p;
		cout << t.max_xor(p) << "\n";
	}


	return 0;
}