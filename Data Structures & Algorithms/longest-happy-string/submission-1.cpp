class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans=""; 
        priority_queue<pair<int,char>>pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while(!pq.empty()){
            auto [cnt,ch] = pq.top();
            pq.pop();

            if(ans.size()>1 and ans[ans.size()-1]==ch and ans[ans.size()-2]==ch){
                if(pq.empty()) break;
                auto [cnt2,ch2] = pq.top();
                pq.pop();
                ans+=ch2;
                if(--cnt2>0) pq.push({cnt2,ch2});
                pq.push({cnt,ch});
            }
            else{
                ans+=ch;
                if(--cnt>0) pq.push({cnt,ch});
            }
        }
        return ans;
        
    }
};