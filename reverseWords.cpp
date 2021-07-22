#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    reverse(s.begin(), s.end());
    //新的單字目前位置
    int idx = 0;
    for(int begin = 0; begin < n; begin++){
        if(s[begin] != ' '){
            //除了第一個單字以外，其餘單字前面都需要加一個空白
            if(idx != 0) s[idx++] = ' ';

            int end = begin;
            //取得完整單字，並將單字往前移動
            while(end < n && s[end] != ' '){
                s[idx++] = s[end++];
            }
            //單字範圍 = (begin ~ end-1) 往左移動(begin-idx)
            int len = end - begin;

            reverse(s.begin() + idx - (end - begin), s.begin() + idx);
            begin = end;
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}