#include <iostream>
#include <vector>
#include <map>

using namespace std;

extern int findRepeatNumber(vector<int>& nums);
extern int maxArea(vector<int>& nums);
extern vector<vector<int>> threeSum(vector<int>& nums);
extern int threeSumClosest(vector<int>& nums, int target);
extern int search(vector<int>& nums, int target);
extern bool checkPossibility(vector<int>& nums);
extern int fibonacci(int n);

int main(){
    //509. Fibonacci Number
    int n = 11;
    int result = fibonacci(n);
    cout << result;
    cout << endl;
    
    //665. Non-decreasing Array
    //vector<int> nums{4,2,3};
    //bool result = checkPossibility(nums);

    //33. Search in Rotated Sorted Array
    /*vector<int> nums { 4,5,6,7,0,1,2 };
    int target = 0;
    int result = search(nums, target);*/

    //16. 3Sum Closest
    /*vector<int> nums { 1,2,4,8,16,32,64,128 };
    int target = 82;
    int result = threeSumClosest(nums, target);*/

    //15. 3Sum
    //vector<int> nums { -1,0,1,2,-1,-4 };
    //vector<vector<int>> resultTrhreeSum = threeSum(nums);

    // 11.Container With Most Water
    /*vector<int> nums { 1,8,6,2,5,4,8,3,7 };
    int resultMaxArea = maxArea(nums);
    cout << resultMaxArea;
    cout << endl;*/

    // findRepeatNumber
    //vector<int> nums { 1, 2, 3, 1 };

    /*int resultFindRepeatNumber = findRepeatNumber(nums);
    cout << resultFindRepeatNumber;
    cout << endl;*/
}



