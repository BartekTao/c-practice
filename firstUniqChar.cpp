#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;
int firstUniqChar(string s) {
    vector<int> cList(26, 0);
    for(int i = 0; i < s.size(); i++){
        cList[s[i]-'a']++;
    }
    for(int i = 0; i < s.size(); i++){
        if(cList[s[i]-'a'] == 1) return i;
    }
    return -1;
}
/*
int firstUniqChar(string s) {
    //aabb
    set<char> set;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(set.count(s[i]) != 0) continue;
        if(i == n-1) return i;
        for(int j = i+1; j < n; j++){
            if(s[i] == s[j]){
                set.insert(s[i]);
                break;
            }
            if(j == n-1){
                return i;
            }
        }
    }
    return -1;
}
*/