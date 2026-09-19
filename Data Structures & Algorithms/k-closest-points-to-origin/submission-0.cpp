class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;

        for(auto it : points){
            int dis = abs(it[0]*it[0]+it[1]*it[1]);
            pq.push({dis,{it[0],it[1]}});
        }

        while(k--){
            auto it =pq.top().second;
            ans.push_back(it);
            pq.pop();
        }
        return ans;
        
    }
};
