#include <vector>
using namespace std;

//[1,1]
int findMin(vector<int>& nums) {
    int begin = 0, end = nums.size()-1;

    while(begin < end){
        int mid = (begin+end)/2;
        if(nums[mid] == nums[end]){
            end--;
        }
        else if(nums[mid] < nums[end]){
            end = mid;
        }else{
            begin = mid + 1;
        }
    }
    return nums[begin];
}