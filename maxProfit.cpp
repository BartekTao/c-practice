#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minV = 10001, maxV = 0;
    int n = prices.size();
    for(int i = 0; i< n; i++){
        if(prices[i] < minV) minV = prices[i];
        maxV = max(prices[i]-minV, maxV);
    }
    
    return maxV;
}