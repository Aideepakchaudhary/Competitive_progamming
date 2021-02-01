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

// Question  Link: https://www.spoj.com/problems/SUBSUMS/

vi get_subset_sums(vi arr)
{
	int n = arr.size();

	vi ans;

	for (int mask = 0; mask < (1 << n); ++mask)
	{
		int sum_in_this_case = 0;

		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				sum_in_this_case += arr[i];

		ans.pb(sum_in_this_case);
	}

	return ans;
}



void solve() {
	int n, a, b; cin >> n >> a >> b;

	vi v(n);

	for (int &i : v)
		cin >> i;

	vi left(v.begin(), v.begin() + n / 2); //[0, n/2)
	vi right(v.begin() + n / 2, v.end()); //[n/2, n)

	vi l = get_subset_sums(left), r = get_subset_sums(right);
	sort(r.begin(), r.end());
	int ans = 0;
	for (int l_sum : l) {
		auto ub = upper_bound(r.begin(), r.end(), b - l_sum);  // a <= l+r <= b  ==>  a-l <= r <= b-l
		auto lb = lower_bound(r.begin(), r.end(), a - l_sum);
		int num_of_valid_values = ub - lb;
		ans += num_of_valid_values;
	}
	cout << ans << "\n";
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t;
	// while (t--)
	solve();
	return 0;
}