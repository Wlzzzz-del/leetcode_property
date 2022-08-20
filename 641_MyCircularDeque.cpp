#include <deque>
using namespace std;
class MyCircularDeque {
private:
    int max_size;
    deque<int>* ptr;
public:
    MyCircularDeque(int k):max_size(k){
       ptr = new deque<int>(); 
    }
    
    bool insertFront(int value) {
        if(ptr->size()<max_size){
        ptr->push_front(value);
        return true;
        }
        else{
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(ptr->size()<max_size){
            ptr->push_back(value);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteFront() {
        if(ptr->size()>0){
            ptr->pop_front();
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteLast() {
        if(ptr->size()>0){
            ptr->pop_back();
            return true;
        }
        else{
            return false;
        }
    }
    
    int getFront() {
        if(ptr->empty())return -1;
        else return *ptr->begin();
    }
    
    int getRear() {
        if(ptr->empty())return -1;
        else return ptr->back();
    }
    
    bool isEmpty() {
        return ptr->empty();
    }
    
    bool isFull() {
        if(ptr->size()==max_size)return true;
        else return false;
    }
};