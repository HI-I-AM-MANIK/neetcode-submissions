class Solution {
public:

/// tasks[i] = [enqueueTimei, processingTimei]
/*If the CPU is idle and there are no available tasks to process, the CPU remains idle.

If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.

Once a task is started to process, the CPU will process the entire task without stopping.

The CPU can finish a task then start a new one instantly.

Return the order in which the CPU will process the tasks.

*/

    vector<int>res;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<>> available;

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pending;

        int n = tasks.size();
        
        for(int i=0;i<tasks.size();i++){
            pending.push({tasks[i][0],tasks[i][1],i});
        }

        int time=0;

        while(!available.empty() || !pending.empty()){
            while(!pending.empty() and time>=pending.top()[0]){
                int enque = pending.top()[0];
                int process = pending.top()[1];
                int ind = pending.top()[2];
                pending.pop();
                available.push({process,ind});
            }
            if(available.empty()){
                time=pending.top()[0];
                continue;
            }
            int process = available.top()[0];
            int ind = available.top()[1];
            time+=process;
            res.push_back(ind);
            available.pop();
        }
        return res;


        
    }
};