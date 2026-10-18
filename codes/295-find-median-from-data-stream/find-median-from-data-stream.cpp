class MedianFinder {
    priority_queue<int> left; // Max-heap
    priority_queue<int, vector<int>, greater<int>> right; // Min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);

        // Move the largest element of left to right
        right.push(left.top());
        left.pop();

        // Ensure left has equal or one more element
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        return ((long long)left.top() + right.top()) / 2.0;
    }
};