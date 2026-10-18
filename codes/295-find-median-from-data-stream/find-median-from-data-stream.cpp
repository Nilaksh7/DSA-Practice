class MedianFinder {
    priority_queue<int, vector<int>> left; // Max-heap
    priority_queue<int, vector<int>, greater<int>> right; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // Handle the first element
        if (left.empty()) {
            left.push(num);
            return;
        }

        // Insert into the appropriate heap
        if (num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } 
        else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }

        // Ensure ordering: left.top() <= right.top()
        if (!left.empty() && !right.empty() && left.top() > right.top()) {
            int l = left.top();
            int r = right.top();

            left.pop();
            right.pop();

            left.push(r);
            right.push(l);
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return ((long long)left.top() + right.top()) / 2.0;
        }

        if (left.size() > right.size()) {
            return left.top();
        }

        return right.top();
    }
};