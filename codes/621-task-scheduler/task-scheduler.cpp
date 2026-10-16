class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max-heap: task with highest frequency comes first
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        int time = 0;

        // Process tasks until all frequencies become zero
        while (!pq.empty()) {
            // Store updated frequencies temporarily
            // so the same task isn't selected twice in one cycle
            vector<int> temp;

            // Each cycle contains at most n + 1 intervals
            int cycle = n + 1;

            while (cycle > 0 && !pq.empty()) {
                // Select the task with the highest remaining frequency
                int f = pq.top();
                pq.pop();

                // Execute this task and decrease its frequency
                if (f > 1) {
                    temp.push_back(f - 1);
                }

                // One interval has been used
                time++;
                cycle--;
            }

            // Add remaining task frequencies back to the heap
            for (int f : temp) {
                pq.push(f);
            }

            // If all tasks are completed, no more idle time is needed
            if (pq.empty()) {
                break;
            }

            // Count idle intervals if tasks remain after the cycle
            time += cycle;
        }

        return time;
    }
};