#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, m;
int q[N],pre_sum[N];

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &q[i]);
        pre_sum[i] += pre_sum[i-1] + q[i];
    }
    
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        cout << pre_sum[r] - pre_sum[l-1] <<endl;
    }
    return 0;
}
