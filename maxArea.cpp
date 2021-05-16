#include <iostream>
#include <vector>
#include <map>

using namespace std;

int maxArea(vector<int>& height) {
        int firstBoundary = 0;
        int lastBoundary = height.size() - 1;
        int maxArea = 0;
        int area = 0;
        while((lastBoundary - firstBoundary) > 0){
            area = min(height[firstBoundary], height[lastBoundary]) * (lastBoundary - firstBoundary);
            maxArea = max(area, maxArea);

            if(height[firstBoundary] > height[lastBoundary]){
                lastBoundary --;
            }else{
                firstBoundary ++;
            }
        }

        return maxArea;
    }