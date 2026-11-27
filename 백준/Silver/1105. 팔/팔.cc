// test
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int la, lb, s = 0;//la는 a의 길이, lb는 b의 길이, s는 지금까지 앞에서 나올 수 밖에 없는 8의 개수
    char a[20];
    char b[20];
    for(int i = 0; i < 20; i++){
        a[i] = -1;
        b[i] = -1;
    }
    scanf("%s %s", a, b);
    
    
    
    int fa = 0, fb = 0;//길이 비교 코드
    for(int i = 0; i < 20; i++){
        if(a[i] == -1 && fa == 0){
            la = i;
            fa = 1;
        }
        if(b[i] == -1 && fb == 0){
            lb = i;
            fb = 1;
        }
    }
    if(la != lb){//길이가 다르면 8이 없는 숫자가 한 개는 존재
        printf("0");
        return 0;
    }

    
    for(int i = 0; i < la; i++){
        if(a[i] != b[i]){//맨 앞자리 부터 같은지 확인
            printf("%d", s);//다르면 지금까지 앞에서 나온 8의 개수 출력
            return 0;
        }else if(a[i] == '8'){//else문에 들어왔다는 것은 a[i] 가 b[i]와 같다는 것이므로 8로 같은지 확인
            s++;//8로 같다면 s 증가
        }//8이 아닌 수로 같으면 (88988 88987 : 3)처럼 앞에서 나온 8의 개수는 유지하고 뒤에 나오는 숫자 확인
    }
    printf("%d", s);
    return 0;
}