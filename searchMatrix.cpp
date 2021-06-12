#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //從左下往右上尋找
    int i = matrix.size()-1;
    int j = 0;
    int len = matrix[0].size();
    while(j<len && i>=0){
        if(matrix[i][j] == target) return true;
        if(matrix[i][j] < target){
            j++;
        }else if(matrix[i][j] > target){
            i--;
        }
    }
    return false;
}

