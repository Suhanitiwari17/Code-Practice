class MyCalendar {
    vector<pair<int,int>> events;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto &e : events) {
            if(!(end <= e.first || start >= e.second)) return false;
        }
        events.push_back({start, end});
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */