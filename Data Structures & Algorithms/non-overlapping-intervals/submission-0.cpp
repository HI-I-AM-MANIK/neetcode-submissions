class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res=0;
        int end1=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(s>=end1){
                end1=e;
            }
            else{
                res++;
                end1=min(end1,e);
            }
        }
        return res;
        
    }
};
