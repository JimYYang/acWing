#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>

using namespace std;

typedef long long LL;

const int N = 110, M = 10010;

int op[N], f[M];
int k, n;

// unordered_set<int>memo;
int sg(int x){
    if(f[x] != -1)return f[x];
    
    unordered_set<int>memo;
    
    for(int i = 0; i < k; i ++){
        int cur = op[i];
        if(x >= cur)memo.insert(sg(x - cur));
    }
    
    for(int i = 0; ; i ++){
        if(!memo.count(i))
            return f[x] = i;
    }
}

int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i ++) scanf("%d", &op[i]);
    
    scanf("%d", &n);
    
    memset(f, -1, sizeof f);
    
    int x;
    int res = 0;
    while(n --){
        scanf("%d", &x);
        res ^= sg(x);
    }
    
    if(res)puts("Yes");
    else puts("No");
    
    return 0;
}
