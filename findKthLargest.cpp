#include <vector>
#include <cstdlib>
using namespace std;

bool rfindKthLargest(vector<int>& nums, int left, int right, int k){
    int pivot_pos = rand() % (right-left+1)+left;
    int len = right;
    int pivot = nums[pivot_pos];
    swap(nums[right], nums[pivot_pos]);
    while(left != right){
        if(nums[right] < nums[left]){
            swap(nums[right], nums[left]);
        }
        if(nums[right] == nums[left] || nums[right] != pivot) right--;
        else left++;
    }
    if(left+1 == k) return true;
    else if(left + 1 > k){      //取左
        return rfindKthLargest(nums, 0, left-1, k);
    }else{      //取右
        return rfindKthLargest(nums, left+1, len-1, k);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    rfindKthLargest(nums, 0, len-1, k);
    return nums[k-1];
}

/*
int partition(vector<int>& nums, int left, int right){
    int pivot_pos = rand() % (right-left+1)+left;
    int len = right;
    int pivot = nums[pivot_pos];
    swap(nums[right], nums[pivot_pos]);
    while(left != right){
        if(nums[right] < nums[left]){
            swap(nums[right], nums[left]);
        }
        if(nums[right] == nums[left] || nums[right] != pivot) right--;
        else left++;
    }
    return left;
}
int findKthLargest(vector<int>& nums, int k) {
    int low = 0;
    int high = nums.size()-1;
    int rank = nums.size()-k;  //turn problem to find rank-th smallest
    while(true){
        int pivot_pos = partition(nums,low,high);
        if(pivot_pos == rank){
            return nums[pivot_pos];
        }
        if(pivot_pos<rank){   // if pivot_pos smaller than the rank, update low bound
            low = pivot_pos+1;
        }
        else{
            high = pivot_pos-1;
        }
    }
}
*/