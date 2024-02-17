#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

int N, M;
int v[501][501];
int memo[501][501];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int dp(int x, int y)
{
    if(x==N && y==M){
        return 1;
    }
    if(memo[x][y]!=-1){
        return memo[x][y];
    }
    memo[x][y]=0;
    for(int i=0; i<4; i++){
        int nx=dx[i]+x, ny=dy[i]+y;
        if(nx<1 || ny<1 || nx>N || ny>M || v[nx][ny]>=v[x][y]){
            continue;
        }
        memo[x][y]+=dp(nx, ny);
    }
    return memo[x][y];
}


int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%d", &v[i][j]);
        }
    }
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(1, 1));
    return 0;
}
