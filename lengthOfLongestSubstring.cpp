#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


int lengthOfLongestSubstring(string s) {
    //c : index
    unordered_map<char, int> map;
    int point = 0;
    int ans = 0;
    for(int i = 0; i< s.size(); i++){
        if(map.count(s[i]) && map[s[i]] >= point){
            point = map[s[i]] + 1;
        }
        map[s[i]] = i;
        ans = max(ans, i - point + 1);
    }
    return ans;
}

/*
int lengthOfLongestSubstring(string s) {
    set<char> set;
    int front = 0;
    int end = 0;
    int ans = 0;
    while(end < s.size()){
        if(set.count(s[end]) == 0){
            set.insert(s[end]);
            end++;
        }else{
            while(set.count(s[end]) != 0){
                set.erase(s[front]);
                front++;
            }
        }
        ans = max(ans, (int)set.size());
    }
    return ans;
}
*/