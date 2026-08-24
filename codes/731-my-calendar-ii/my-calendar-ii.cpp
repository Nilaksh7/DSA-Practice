class MyCalendarTwo {
public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {

        // Check whether this booking creates a triple booking
        for (auto [l, r] : overlaps) {
            int start = max(startTime, l);
            int end = min(endTime, r);

            if (start < end) {
                return false;
            }
        }

        // Find newly created double-booked intervals
        for (auto [l, r] : events) {
            int start = max(startTime, l);
            int end = min(endTime, r);

            if (start < end) {
                overlaps.push_back({start, end});
            }
        }

        // Add the new event
        events.push_back({startTime, endTime});

        return true;
    }
};
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */