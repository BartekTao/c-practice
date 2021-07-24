
int add(int a, int b) {
    while(b != 0){
        //有進位的相加值
        int c = (a&b) << 1;
        //沒有進位的相加值
        a ^= b;
        b = c;
    }
    return a;
}