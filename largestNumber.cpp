#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static bool compare(string a, string b){
    return a+b > b+a;
}

string largestNumber(vector<int>& nums) {
    int count = 0;
    for(auto num : nums){
        if(num == 0) count++;
    }
    if(count == nums.size()) return "0";
    string ans = "";
    vector<string> stringList;
    for(auto num : nums) stringList.push_back(to_string(num));
    sort(stringList.begin(), stringList.end(), compare);
    for(auto i : stringList) ans+=i;
    return ans;
}