#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //儲存nums的index
    deque<int> d;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        //d.front() + k == i(目前位置)
        //=>代表d的長度 == k => 需要將第一個值去除
        if(d.front() == i-k) d.pop_front();
        //若d的最後一個值 < 當前數字(nums[i]) => 可剔除d的最後一個值，因為它不會是最大的數字
        while(!d.empty() && nums[d.back()] < nums[i]) d.pop_back();

        d.push_back(i);

        if(i >= k-1) ans.push_back(nums[d.front()]);
    }
    return ans;
}