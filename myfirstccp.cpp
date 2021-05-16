#include <iostream>
#include <vector>
#include <map>

using namespace std;

extern int findRepeatNumber(vector<int>& nums);
extern int maxArea(vector<int>& nums);

int main(){
    // maxArea
    vector<int> nums { 1, 2, 3, 1 };
    int resultMaxArea = maxArea(nums);
    cout << resultMaxArea;
    cout << endl;

    // findRepeatNumber
    //vector<int> nums { 1, 2, 3, 1 };

    int resultFindRepeatNumber = findRepeatNumber(nums);
    cout << resultFindRepeatNumber;
    cout << endl;
}



