class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        set<int> closed; //the boxes we get but do not have keys to open
        for(int i:initialBoxes)
            if(status[i])
                q.push(i);
            else
                closed.insert(i);
        int res=0;
        set<int> mkey; //unused keys
        while(!q.empty()){
            int id = q.front();
            res+=candies[id];
            q.pop();
            for(int k:keys[id])
                if(closed.find(k)==closed.end())
                    mkey.insert(k);
                else{
                    closed.erase(k);
                    q.push(k);
                }
            for(int inbox:containedBoxes[id])
                if(status[inbox])
                    q.push(inbox);
                else{
                    int k=inbox;
                    if(mkey.find(k)==mkey.end())
                    closed.insert(k);
                    else{
                        mkey.erase(k);
                        q.push(k);
                    }
                }

        }
        return res;
    }
};
