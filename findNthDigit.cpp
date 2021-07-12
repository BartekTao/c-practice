#include <math.h>

using namespace std;

int findNthDigit(int n) {
    if(n < 10){
        return n;
    }
    long base = 9;
    int digit = 1;
    int length = 0;
    while (base*digit + length < n)
    {
        length += base*digit;
        digit+=1;
        base*=10;
    }
    n -= length;
    int index = n%digit;
    //一定是該數的最後一個字
    if(index == 0){
        return ((n/digit) -1)%10;
    }else{
        //取得該數字的值
        int num = pow(10, digit-1) + (n/digit);
        //從個位數進位置該位數
        //EX:
        //digit = 3 => 該數為三位數
        //index = 2 => 答案為該數的第二位數(十位數)
        //for 2~3 (去除最後一位數)
        for(int i = index; i < digit; i++){
            //捨去最後一位數
            num = num / 10;
        }
        return num%10;
    }
}