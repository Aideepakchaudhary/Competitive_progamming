
// question Link: https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
	int sz = 0, n = 0, b = 0;
	vector<int> sum, arr;
public:
	NumArray(vector<int>& nums) {
		n = nums.size(), b = sqrt(n);
		sz = (n + b - 1) / b;
		sum.assign(sz, 0);
		arr = nums;

		for (int i = 0; i < n; i++)
			sum[i / b] += arr[i];
	}

	void update(int i, int val) {
		sum[i / b] -= arr[i];
		arr[i] = val;
		sum[i / b] += arr[i];
	}

	int sumRange(int l, int r) {
		int ans = 0;

		int l_block = l / b, l_end = min(l_block * b + b - 1, n - 1);
		int r_block = r / b, r_start = r_block * b;

		if (l_block == r_block) {
			for (int i = l; i <= r; i++)
				ans += arr[i];

			return ans;
		}

		// Add elements from L_block
		for (int i = l; i <= l_end; i++)
			ans += arr[i];

		// Add elements from r_block
		for (int i = r_start; i <= r; i++)
			ans += arr[i];

		// Add sum_values of intermediate..

		for(int i = l_block+1; i < r_block; i++) 
			ans += sum[i];

		return ans;
	}
};