
// https://leetcode.com/problems/n-queens/

class Solution {
    int n;
    
    bool under_attack(int r, int c, vector<string> &queen)
	{
		for (int i = 0; i < r; ++i)
			if (queen[i][c] == 'Q')
				return true;

		for (int j = 0; j < c; ++j)
			if (queen[r][j] == 'Q')
				return true;

		for (int i = r, j = c; min(i, j) >= 0; i--, j--)
			if (queen[i][j] == 'Q')
				return true;

		for (int i = r, j = c; i >= 0 and j < n; i--, j++)
			if (queen[i][j] == 'Q')
				return true;

		return false;
	}
    
    bool backtrack(vector<string> &queen, vector<vector<string>> &ans,int r= 0)
    {
        if(r == n){
            ans.push_back(queen);
            return true;
        } 
        bool done = false;
        
        for(int c = 0 ; c < n ; c++)
        {
            if(!under_attack(r,c,queen))
            {
                queen[r][c] = 'Q';
                
                done = backtrack(queen, ans, r+1) or done;
                queen[r][c] = '.';
            }
        }
        return done;
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> ans;
        vector<string> queen(n);
        
        for(int i =0; i<n;i++)
            for(int j =0; j<n;j++)
                queen[i] += '.';
        
        backtrack(queen, ans);
        return ans;
    }
};