class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        unordered_map<char,int>map;
        for(auto it:s){
            map[it]++;
        }
        priority_queue<pair<int,char>>pq;

        for(auto [x,y]:map){
            pq.push({y,x});
        }
        int i=0,n=s.size();
        int prec=0;
        char prech=' ';
        while(!pq.empty()){
            auto [x,y] = pq.top();
            pq.pop();
            if(prech==y){
                if(pq.empty()) return "";
                auto [x2,y2] =pq.top();
                pq.pop();
                  ans += y2; 
                x2--; 

                if(x2 > 0) 
                    pq.push({x2,y2}); 

                pq.push({x,y}); 

                prech = y2; 
                prec = x2; 
            }
            else{
                ans+=y;
                x--;
                prech=y;
                prec=x;
                if(prec>0) 
                    pq.push({x,y});
            }

        }
        return ans;
        
        
    }
};