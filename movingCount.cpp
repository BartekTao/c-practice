#include <queue>
#include <vector>

using namespace std;

int get(int x) {
    int res=0;
    for (; x; x /= 10) {
        res += x % 10;
    }
    return res;
}

int movingCount(int m, int n, int k) {
    if(!k) return 1;

    queue<pair<int, int>> queue;
    vector<vector<bool>> vis(m, vector<bool>(n, 0));
    queue.push(make_pair<int, int>(0, 0));

    // 向右和向下的方向數組
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int ans = 1;
    vis[0][0] = 1;
    while(!queue.empty()){
        int x = queue.front().first;
        int y = queue.front().second;

        //push向下向右的格子
        for(int i=0;i<2;i++){
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if(tx>=m || ty>=n || get(tx)+get(ty) > k || vis[tx][ty]){
                continue;
            }
            ans++;
            queue.push(make_pair(tx,ty));
            vis[tx][ty] = 1;
        }
        queue.pop();
    }
    return ans;
}