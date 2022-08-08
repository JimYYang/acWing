// 往前看一个得到转移状态

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int a[N], dp[N];


int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i ++){
        dp[i] = 1;
        
        for(int j = 1; j < i; j ++){
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    int res = 1;
    for(int i = 1; i <= n; i ++)res = max(res, dp[i]);
    printf("%d\n", res);
    
    return 0;
}
