#include <vector>
#include <algorithm>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int check = len/3;
    vector<int> ans;
    for(int i = 0; i< len; i++){
        int j = 1;
        while(i+1 < len && nums[i] == nums[i+1]){
            j++;
            i++;
        }
        if(j > check){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}