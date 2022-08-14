/*
 * x ^ y = 0 < = > x = y
 * a ^ 0 = a
 * a ^ b ^ b = a
 * a ^ a = 0
 * swap a = a ^ b
 *      b = a ^ b
 *      a = a ^ b
 * LC求只出现一次的数字  用异或来做
*/





#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;


const int N = 300010;

typedef long long LL;
int dp[N], a[N];


// [i, j] 的异或和 = [0, i - 1] ^ [0, j]

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
    
    unordered_map<int, int> s[2];
    
    s[0][0] ++; // 有时候00 的初始化需要为1  这样初始化是为了区间长度为2时  可以得到答案
    
    LL res = 0;
    
    int sum = 0;
    
    for(int i = 1; i <= n; i ++){
        sum ^= a[i];
        res += s[i & 1][sum];
        s[i & 1][sum] ++;
    }
    
    printf("%lld\n", res);
    
    return 0;
    
}
