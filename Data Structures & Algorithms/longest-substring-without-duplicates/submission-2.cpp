class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        set<char> s;
        int l=0;
        int res=0;
        for(int i=0;i<st.length();i++){
            while(s.find(st[i])!=s.end()){
                s.erase(st[l]);
                l++;
            }
            s.insert(st[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};
