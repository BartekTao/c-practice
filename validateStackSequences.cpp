#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> check_stack;
    int len = pushed.size();
    int j = 0;
    for(int i = 0;i < len; i++){
        check_stack.push(pushed[i]);
        while(!check_stack.empty() && check_stack.top() == popped[j]){
            j++;
            check_stack.pop();
        }
    }
    return j == len;
}