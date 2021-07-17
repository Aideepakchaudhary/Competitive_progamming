
// https://leetcode.com/problems/subsets/submissions/

class Solution {
	void sbs(vector<int> &nums, int i, vector<int> &cur, vector<vector<int>> &ans)
	{
		if (i == nums.size()) {
			ans.push_back(cur);
			return;
		}
		//We can make two choices either we take a ele or not...

		//1. For No condition...

		sbs(nums, i + 1, cur, ans);

		// 2. For yes we have to take the current ele

		cur.push_back(nums[i]);
		sbs(nums, i + 1, cur, ans);

		// After take the ele we have to invert the cur array..

		cur.pop_back();
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > ans;
		vector<int> cur;
		sbs(nums, 0, cur, ans);
		return ans;
	}
};