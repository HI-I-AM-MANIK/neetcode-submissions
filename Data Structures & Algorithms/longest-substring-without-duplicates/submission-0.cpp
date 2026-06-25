class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        for(int i=0;i<s.length();i++){
            unordered_set<char> cs;
            for(int j=i;j<s.length();j++){
                if(cs.find(s[j])!=cs.end()){
                    break;
                }
                cs.insert(s[j]);
            }
            res = max(res,(int)cs.size());
        }
        return res;
    }
};
