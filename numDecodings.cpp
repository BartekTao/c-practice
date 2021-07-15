#include <iostream>
#include <vector>
using namespace std;

//dp constant space
int numDecodings(string s) {
    int n = s.size();
    if(s.empty() || s[0] == '0') return 0;
    //base case
    int nextt = 1;
    int next = s[n-1] == '0' ? 0 : 1;

    for(int i = n-2; i >=0; i--){
        int curr = 0;
        if(s[i] != '0'){
            curr += next;
        }
        if(s[i] == '1' || s[i] == '2' && s[i+1] < '7'){
            curr += nextt;
        }
        nextt = next;
        next = curr;
    }
    return next;
}

//dp解
/*
int numDecodings(string s) {
    int n = s.size();
    vector<int> dp = vector<int>(n+1, 0);
    if(s.empty() || s[0] == '0') return 0;
    //base case
    dp[n] = 1;
    dp[n-1] = s[n-1] == '0' ? 0 : 1;

    for(int i = n-2; i >=0; i--){
        if(s[i] != '0'){
            dp[i] += dp[i+1];
        }
        if(s[i] == '1' || s[i] == '2' && s[i+1] < '7'){
            dp[i] += dp[i+2];
        }
    }
    return dp[0];
}
*/



//遞迴解
/*
vector<int> numDecodingsAns;

int rnumDecodings(string s, int i) {
    if(numDecodingsAns[i] != -1){
        return numDecodingsAns[i];
    }
    int n = s.size();
    if(i >= n) {
        numDecodingsAns[i] = 1;
        return 1;
    }
    if(s[i] == '0'){
        numDecodingsAns[i] = 0;
        return 0;
    }
    int res = rnumDecodings(s, i+1);
    if(i < n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')){
        res += rnumDecodings(s, i+2);
    }
    numDecodingsAns[i] = res;
    return res;
}

int numDecodings(string s) {
    numDecodingsAns = vector<int>(s.size()+1, -1);
    int res = rnumDecodings(s, 0);
    return s.empty() ? 0 : numDecodingsAns[0];
}
*/