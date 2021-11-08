#include<deque>
using namespace std;

class SetOfStacks  {
    public:
    SetOfStacks(int capacity){
        SetOfStacks::capacity = capacity;
    }
    void push(int value){
        if(deques.empty() || deques.back().size() >= capacity){
            deque<int> temp;
            temp.push_back(value);
            deques.emplace_back(temp);
        }else{
            deques.back().push_back(value);
        }
    }

    void top(){
        deques.back().back();
    }

    void pop(){
        deques.back().pop_back();
        if(deques.back().size() == 0){
            deques.pop_back();
        }
    }

    void popAt(int index){
        int stacksSize = deques.size();
        if(index < 0 || index > stacksSize){
            return;
        }
        
        deques[index].pop_back();
        shift(index);
    }

    private:
    int capacity;
    deque<deque<int>> deques;

    void shift(int index){
        int stacksSize = deques.size();
        if(index == stacksSize-1){
            if(deques[index].empty()){
                deques.pop_back();
            }
        }else{
            deques[index].push_back(deques[index+1].front());
            deques[index+1].pop_front();
            shift(index+1);
        }
    }
};