class MyCalendar {
public:
    MyCalendar(){

    }
    
    bool book(int start, int end) {
        const int n = this->booked.size();
        auto it = booked.upper_bound({start, end});
        if(it != booked.begin() && prev(it)->second > start) return false;
        if(it != booked.end() && it->first < end) return false;
        booked.insert({start, end});
        return true;
    }
    set<pair<int, int>> booked;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
