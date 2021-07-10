#include <stack>
#include <queue>

using namespace std;

class MedianFinder {
public:
    //存放大的
    priority_queue<int> minHeap;
    //存放小的
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    bool even;
    MedianFinder() {
        even = true;
    }
    
    void addNum(int num) {
        if(even){
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();

        }else{
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if(even){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }else{
            return maxHeap.top();
        }
    }
};


//過慢
/*class MedianFinder {
public:
    stack<int> in;
    stack<int> out;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(in.empty() && out.empty()){
            in.push(num);
        }
        else if(num <= in.top()){
            while(!in.empty() && num < in.top()){
                out.push(in.top());
                in.pop();
            }
            in.push(num);
        }else{
            while(!out.empty() && num > out.top()){
                in.push(out.top());
                out.pop();
            }
            out.push(num);
        }
    }
    
    double findMedian() {
        int inLen = in.size();
        int outLen = out.size();
        
        while(in.size() < out.size()){
            in.push(out.top());
            out.pop();
        }
        while(out.size()+1 != in.size() && out.size() < in.size()){
            out.push(in.top());
            in.pop();
        }

        if((inLen+outLen)&1){
            return in.top();
            
        }else{
            return (0.0 + in.top() + out.top())/2;
        }
    }
};*/