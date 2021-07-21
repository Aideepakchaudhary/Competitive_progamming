
// https://leetcode.com/problems/unique-paths-iii/submissions/
class Solution {
    
    int rec(vector<vector<int>>& grid, int x, int y, int zero)
    {
        if(x < 0 || y < 0 || y >= grid[0].size() || x >= grid.size() || grid[x][y] == -1)
            return 0;
        
        if(grid[x][y] == 2) 
            return  zero == -1 ? 1 : 0;
        
        grid[x][y] = -1;  // currently at this grid..
        zero--;
        
        int total_possibility = rec(grid,x+1,y,zero) 
                                + rec(grid,x,y+1,zero) 
                                + rec(grid,x-1,y,zero)
                                + rec(grid,x,y-1,zero);
        
        grid[x][y] = 0;  // Backtrack;
        zero++;
        
        return total_possibility;
        
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x= 0; int y = 0,  zero = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j< grid[i].size(); ++j)
                if(grid[i][j] == 0)
                    zero++;
            
                else if(grid[i][j] == 1)
                    x = i,y = j;
        }
        
        int ans = rec(grid, x, y, zero);
        return ans;
    }
};