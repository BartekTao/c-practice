#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    //邊界 上下
    int top = 0, bottom = m-1;
    //邊界 左右
    int left = 0, right = n-1;

    vector<int> ans;
    
    while (top <= bottom && left <= right)
    {
        for(int j = left; j <= right; j++){
            ans.push_back(matrix[top][j]);
        }
        for(int i = top+1; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        if(bottom > top && right > left){
            for(int j = right-1; j>=left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            for(int i = bottom-1; i>top; i--){
                ans.push_back(matrix[i][left]);
            }
        }
        
        top++;
        right--;
        bottom--;
        left++;
    }
    return ans;
}