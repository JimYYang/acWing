#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M = N * N;
PII que[M], pre[N][N];
int grid[N][N];
int n;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void bfs(int sx, int sy) {
    que[0] = {sx, sy};
    int hh = 0, tt = 0;
    pre[sx][sy] = {-1, -1};
    memset(pre, -1, sizeof pre);
    
    while (hh <= tt) {
        PII cur = que[hh ++];
        for (int i = 0; i < 4; i ++){
            int a = cur.x + dx[i], b = cur.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (pre[a][b].x != -1) continue;
            if (grid[a][b]) continue;
            que[++ tt] = {a, b};
            pre[a][b] = cur;
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    bfs(n - 1, n - 1);
    
    PII end(0, 0);
    
    while (true) {
        printf("%d %d\n", end.x, end.y);
        if (end.x == n - 1 && end.y == n - 1) break;
        end = pre[end.x][end.y];
    }
    return 0;
}
