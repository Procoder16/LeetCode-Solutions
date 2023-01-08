class cmp{
    public:
    bool operator()(vector<int>& a, vector<int>& b)
    {
        if(a[1]==b[1])
            return b[2] < a[2];

        return a[1]>b[1];
    }
};

static bool comparator(vector<int>& a, vector<int>& b)
{
    return a[0]>b[0];
}

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans(n, -1);

        vector<vector<int>> tasksWithName(n, vector<int>(3));
        for(int i=0; i<n; i++)
            tasksWithName[i] = {tasks[i][0], tasks[i][1], i};

        sort(tasksWithName.begin(), tasksWithName.end(), comparator);

        int i = 0;
        long long currTime = 0;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        currTime = tasksWithName[n-1][0];
        while(i != n)
        {
            while(tasksWithName.size() != 0 && tasksWithName.back()[0]<=currTime)
            {
                pq.push(tasksWithName.back());
                tasksWithName.pop_back();
            }
            if(pq.empty())
                currTime = tasksWithName.back()[0];
            else
            {
                const vector<int>& top = pq.top();               
                ans[i++] = top[2];
                currTime += top[1];
                pq.pop();
            } 
        }

        return ans;
    }
};
