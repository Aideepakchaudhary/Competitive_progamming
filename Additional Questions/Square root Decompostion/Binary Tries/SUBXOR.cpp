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

// https://www.spoj.com/problems/SUBXOR/

class node
{
public:
	int cnt[2];
	node *child[2];
	node()
	{
		cnt[0] = cnt[1] = 0;
		child[0] = child[1] = NULL;
	}
};

class trie
{
	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int num)
	{
		node* cur = root;

		for (int i = 19; i >= 0; i--) {
			int b = (num >> i) & 1;

			if (cur->child[b] == NULL) {
				cur->child[b] = new node();
			}
			cur->cnt[b]++;

			cur = cur->child[b];
		}
	}

	int count(int num, int k)
	{
		node *cur = root;
		int ans = 0;

		for (int i = 19; i >= 0; i--)
		{
			int kb = (k >> i) & 1;
			int zero = (num >> i) & 1;

			if (kb)
				ans += cur->cnt[zero];

			if (cur -> child[zero ^ kb])
				cur  = cur->child[zero ^ kb];
			else
				break;
		}
		return ans;
	}
};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--)
	{	int n, k; cin >> n >> k;
		trie t;
		int pre = 0, ans = 0;
		t.insert(pre);

		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			pre ^= x;

			ans += t.count(pre, k);
			t.insert(pre);
		}

		cout << ans << "\n";
	}
	return 0;
}