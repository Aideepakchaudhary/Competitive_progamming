typedef pair<int,pair<int,int>> node;

class Solution
{
    
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> a, int k)
    {
        //code here
        priority_queue<node, vector<node>, greater<node> >q;  // value, array_Num, index
        
        for(int i =0; i<k;i++)
            q.push({a[i][0], {i,0}});
            
        vector<int> result;
        
        while(!q.empty())
        {
            node current  = q.top();
            int value = current.first;
            int arr_num = current.second.first;
            int index = current.second.second;
            q.pop();
            
            result.push_back(value);
            
            if(index + 1 < k)
            q.push({a[arr_num][index+1], {arr_num, index +1}});
        }
        return result;
        
    }
};