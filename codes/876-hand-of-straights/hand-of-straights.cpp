class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> freq;

        // Count frequencies
        for (int card : hand) {
            freq[card]++;
        }

        // Min-heap to process the smallest card first
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& p : freq) {
            pq.push(p.first);
        }

        while (!pq.empty()) {
            int start = pq.top();

            // Form a group of consecutive cards
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                // Required card is missing or already used
                if (freq[card] == 0) {
                    return false;
                }

                freq[card]--;
                
                // Remove exhausted cards from the heap
                if (freq[card] == 0 && card == pq.top()) {
                    pq.pop();
                }
            }
        }

        return true;
    }
};