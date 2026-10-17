class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26);
        for(int i = 0 ; i < tasks.size() ; i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int,vector<int>> pq;
        for(int i = 0 ; i < freq.size() ; i++){
            if(freq[i] > 0)
                pq.push(freq[i]);
        }

        int time = 0;

        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;

            while(cycle > 0 && !pq.empty()){
                int f = pq.top();
                pq.pop();
                if(f > 1)
                    temp.push_back(f-1);
                time++;
                cycle--;
            }

            for(int i = 0 ; i < temp.size() ; i++){
                pq.push(temp[i]);
            }

            if(pq.empty())
                break;

            if(cycle > 0) 
                time += cycle;
        }

        return time;
    }
};