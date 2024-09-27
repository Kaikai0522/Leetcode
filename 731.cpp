class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        auto it = double_booked.upper_bound({start, end});
        if(it != double_booked.begin() && start < prev(it)->second) return false;
        if(it != double_booked.end() && end > it->first) return false;
        it = booked.begin();
        for(int s, e;it != booked.end();++it){
            if(it->first >= end) break;
            if(it != booked.end() && end > it->first){
                s = max(start, it->first);
                e = min(end, it->second);
                if(s < e) double_booked.insert({s, e});
            }
        }
        booked.insert({start, end});
        return true;
    }
    set<pair<int, int>> booked;
    set<pair<int, int>> double_booked;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
