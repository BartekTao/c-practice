#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cstring>


using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

extern int findRepeatNumber(vector<int>& nums);
extern int maxArea(vector<int>& nums);
extern vector<vector<int>> threeSum(vector<int>& nums);
extern int threeSumClosest(vector<int>& nums, int target);
extern int search(vector<int>& nums, int target);
extern bool checkPossibility(vector<int>& nums);
extern int fibonacci(int n);
extern bool canPartitionKSubsets(vector<int>& nums, int k);
extern int minCut(string s);
extern vector<vector<string>> partition(string s);
extern bool canPartition(vector<int>& nums);
extern int findMaxForm(vector<string>& strs, int m, int n);
extern int uniquePaths(int m, int n);
extern int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
extern bool searchMatrix(vector<vector<int>>& matrix, int target);
extern bool exist(vector<vector<char>>& board, string word);
extern int movingCount(int m, int n, int k);
extern int integerBreak(int n);
extern double myPow(double x, int n);
extern bool isMatch(string s, string p);
extern int myAtoi(string s);
extern bool isSubtree(TreeNode* root, TreeNode* subRoot);
extern vector<int> spiralOrder(vector<vector<int>>& matrix);
extern vector<vector<int>> permuteUnique(vector<int>& nums);
extern int findKthLargest(vector<int>& nums, int k);
extern int maxSubArray(vector<int>& nums);
extern int numDecodings(string s);
extern int maxValue(vector<vector<int>>& grid);
extern int lengthOfLongestSubstring(string s);
extern int nthUglyNumber(int n);
extern int firstUniqChar(string s);
extern vector<int> searchRange(vector<int>& nums, int target);
extern int kthSmallest(TreeNode* root, int k);
extern string reverseWords(string s);

int answ = 0;
int sss(vector<int>& nums, int w, int i){
    int len = nums.size();
    if(i >= len) return 0;
    int c = sss(nums, w, i+1);
    if(i == len-1 || nums[i+1] == nums[i] + 1){
        if(i == 0 && 1 + c >= w){
            answ += 1 + c - w + 1;
        }
        return 1 + c;
    }else{
        if(c >= w) answ += c - w + 1;
        return 1;
    }
}

int ss(vector<int>& nums, int w){
    int len = nums.size();

    int i = 0;
    int sum = 0;
    int count = 0;
    int ans = 0;
    while(i+1 < len){
        int d = nums[i+1] - nums[i];
        sum+=d;
        if(abs(d) < w && abs(sum) < w){
            count++;
            if(count == w-1){
                ans++;
                count--;
                sum-=nums[i-w];
            }
        }else{
            sum = 0;
            count = 0;
        }
    }
    return ans;
}

void urlify(char *str, int len)
{
    int numOfSpaces = 0;
    int i = 0, j = 0;
    for ( i = 0; i < len; ++i ) {
        if (str[i] == ' ') {
            ++numOfSpaces;
        }
    }
    
    int extendedLen  = len + 2 * numOfSpaces;
    str += ' ';
    i = extendedLen - 1;
    for( j = len - 1; j >= 0; --j ) {
        if ( str[j] != ' ' ) {
           str[i--] = str[j];
        } else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}


int main(){
    bool a[3];
    char str[] = "Mr John Smith";
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
    
    /*
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1, nullptr, new TreeNode(2));
    root->right = new TreeNode(4);
    int res = kthSmallest(root, 1);
    */
    
    //vector<int> nums = {5,8,8,8,8,10};
    //vector<int> res = searchRange(nums, 8);

    //int res = firstUniqChar("aabb");
    
    //int res = nthUglyNumber(10);
    
    //int res = lengthOfLongestSubstring("abba");
    //vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};
    //int res = maxValue(nums);

    //string s = "1234";
    //numDecodings(s);

    //vector<int> nums = {4,1,2,3,5,6,7,8,10,9};
    //int res = ss(nums, 4);


    //vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    //int res = maxSubArray(nums);
    
    //int res = findKthLargest(nums, 4);

    //auto res = permuteUnique(nums);

    //vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //vector<vector<int>> nums = {{6,9,7}};
    //auto res = spiralOrder(nums);

    
    /*TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    root->right = new TreeNode(5);

    TreeNode* subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));

    bool res = isSubtree(root, subRoot);*/

    //int res = myAtoi("-91283472332");

    //bool res = isMatch("aab", "c*a*b");
    
    //double res = myPow(2, -2);
    
    //int res = integerBreak(2);

    //int res = movingCount(2, 3, 1);

    //vector<vector<char>> chars{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    //vector<vector<char>> chars{{'a'}};
    //bool res = exist(chars, "ABCCED");

    //240. Search a 2D Matrix II
    /*vector<vector<int>> nums{{48,65,70,113,133,163,170,216,298,389},{89,169,215,222,250,348,379,426,469,554},{178,202,253,294,367,392,428,434,499,651},{257,276,284,332,380,470,516,561,657,698},{275,331,391,432,500,595,602,673,758,783},{357,365,412,450,556,642,690,752,801,887},{359,451,534,609,654,662,693,766,803,964},{390,484,614,669,684,711,767,804,857,1055},{400,515,683,732,812,834,880,930,1012,1130},{480,538,695,751,864,939,966,1027,1089,1224}};

    bool res = searchMatrix(nums, 929);*/

    //vector<vector<int>> nums{ {0, 0, 0},{0, 1, 0},{0, 0, 0} };
    //int res = uniquePathsWithObstacles(nums);

    //[[0,0,0],[0,1,0],[0,0,0]]

    //int res = uniquePaths(3,7);
    //474. Ones and Zeroes
    /*vector<string> strs{ "10","0001","111001","1","0" };
    findMaxForm(strs, 5, 3);*/

    //416. Partition Equal Subset Sum
    //vector<int> nums{1,5,11,5};
    //bool res = canPartition(nums);

    //int res2 = minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    
    //auto res = partition("aab");
    
    //vector<int> nums{3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    //bool res = canPartitionKSubsets(nums, 5);
    //509. Fibonacci Number
    /*int n = 11;
    int result = fibonacci(n);
    cout << result;
    cout << endl;*/
    
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



