#include  <iostream>
#include <vector>

class MyCalendar {
public:
    std::vector<std::vector<int>> vec;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(int i=0;i<vec.size();++i){
            if(vec[i][0]<end && start <vec[i][1])return false;
        }
        vec.push_back({start,end});
        return true;
    }

};