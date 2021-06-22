#include <iostream>

using namespace std;

int myAtoi(string s) {
    int len = s.size(), i = 0;
    int64_t ans = 0;
    bool positive = true;
    while(s[i] == ' '){
        i++;
    }
    if(s[i] == '-'){
        positive = false;
        i++;
    }
    else if(s[i] == '+'){
        i++;
    }

    while(i < len && s[i]>='0' && s[i]<='9'){
        ans = ans*10 + (s[i] - '0');
        if(ans > INT32_MAX && positive){
            return INT32_MAX;
        }
        if(-ans < INT32_MIN && !positive){
            return INT32_MIN;
        }
        i++;
    }

    return positive? ans : -ans;
}