class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // Total cards must be divisible by groupSize
        if (n % groupSize != 0) {
            return false;
        }

        // Count the frequency of each card in sorted order
        map<int, int> mp;

        for (int card : hand) {
            mp[card]++;
        }

        // Start groups from the smallest available card
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 0) {
                continue;
            }

            int start = it->first;
            int count = it->second;

            // Form groups of consecutive cards
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (mp[card] < count) {
                    return false;
                }

                mp[card] -= count;
            }
        }

        return true;
    }
};