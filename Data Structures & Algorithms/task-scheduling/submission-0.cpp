class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>arr(26);
        for(auto it : tasks){
            arr[it-'A']++;
        }
        priority_queue<int>pq;
        for(int cnt: arr){
            if(cnt>0){
                pq.push(cnt);
            }
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time=q.front().second;
            }
            else{
                int cnt =pq.top()-1;
                pq.pop();
                if(cnt>0){
                    q.push({cnt,time+n});
                }
            }
            if(!q.empty() and q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
