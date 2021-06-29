#include <vector>
#include <iostream>

using namespace std;

//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//len=25

bool isValidSerialization(string preorder) {
    int len = preorder.length();
    int slot = 1;
    for(int i = 0; i < len; i++){
        if(slot<=0) return false;
        if(preorder[i] == ','){
            i++;
        }
        if(preorder[i] == '#'){
            slot--;
        }else{
            slot++; //加一減二
            while (preorder[i]>='0' && preorder[i]<='9')
            {
                i++;
            }
        }
    }
    return slot == 0;
}