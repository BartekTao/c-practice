#include <vector>
using namespace std;
int lastRemaining(int n, int m) {
    int ans = 0; //長度為1時 解為0;
    for(int i = 2; i <= n; i++){
        ans = (ans + m) % i;
    }

    return ans;
}