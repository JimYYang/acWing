// 这是有限制的组合问题  不考虑顺序  2 1 1  1 2 1视为一种顺序
// 转化为完全背包 且 恰好装满的方案数

// f[i, j] = f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2 * i] + .. f[i - 1][j - s * i]
// f[i, j - i] =           f[i - 1][j - i] + ...
// f[i][j] = f[i - 1][j] + f[i][j - i]

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;
int dp[N];
int main(){
    int n;
    scanf("%d", &n);
    dp[0] = 1; // 容量为0都不选  所以方案数为1   没有物品选的时候方案数为0 注意即使简化为1维  含义还是二维
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <=n; j ++){
            dp[j] = (long long)(dp[j] + dp[j - i]) % MOD;
        }
    }
    printf("%d\n", dp[n]);
    
    return 0;
}
