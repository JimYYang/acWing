#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;

void divide(int n){
    for(int i = 2; i <= n / i; i ++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                n /= i;
                s ++;
            }
            printf("%d %d\n", i, s);
        }
    }
    
    if(n > 1)printf("%d %d\n", n, 1);
    puts("");
}

int main(){
    scanf("%d", &n);
    
    int x;
    while(n --){
        scanf("%d", &x);
        divide(x);
    }
    
    return 0;
}
