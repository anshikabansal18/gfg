# define PPII pair<pair<int,int>,int>

class Cmp{
    public:
    bool operator()(PPII a, PPII b)
    {
        return a.second>b.second;
    }
};


class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int r = mat.size(), c = mat[0].size();
        priority_queue<PPII, vector<PPII>, Cmp> pq;
        for(int i=0;i<r;i++)
        pq.push({ {i,0} , mat[i][0] });
        
        int res;
        for(int i=0;i<=((r*c)/2);i++)
        {
            PPII top = pq.top();
            pq.pop();
            res = top.second;
            if(top.first.second!=c-1)
            pq.push({ {top.first.first, top.first.second+1} , mat[top.first.first][top.first.second+1] });
        }
        
        return res;
    }
};
