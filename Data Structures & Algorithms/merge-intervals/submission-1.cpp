class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (auto &e : intervals) {
            int s = e[0];
            int d = e[1];

            if (s <= end) {
                end = max(end, d);
            } else {
                output.push_back({start, end});
                start = s;
                end = d;
            }
        }

        output.push_back({start, end});

        return output;
    }
};