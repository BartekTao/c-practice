

double myPow(double x, int n) {
    if(n==0) return 1;
    double res = 1;
    //若為奇數
    if(n&1){
        res = n>0? res*x : res/x;
    }
    n/=2;
    double d = myPow(x, n);
    return d * d * res;
}