/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        int start=intervals[0].start;
        int end=intervals[0].end;
        int n=intervals.size();

        for(int i=1;i<n;i++){
            int s=intervals[i].start;
            int e=intervals[i].end;

            if(s<end){
                return false;
            }
            else{
                start=s;
                end=e;
            }
        }
        return true;

        
    }
};
