#include <bits/stdc++.h>

#define MAXN 105

using namespace std;

int num_cases,num_rows,num_col,pr,pc,kr,kc,moves[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{-1,-2},{-1,2},{1,-2},{1,2}},dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<pair<int,int>> q;

bool valid(int x, int y){
    if(x >= 1 && y >= 1 && x <= num_rows && y <= num_col) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    scanf("%d",&num_cases);
    for(int e=0; e<num_cases; e++){
        scanf(" %d %d %d %d %d %d",&num_rows,&num_col,&pr,&pc,&kr,&kc);
        memset(dis,0,sizeof dis); memset(vis,false,sizeof vis);
        q.push({kr,kc});
        vis[kr][kc] = true;

        while(!q.empty()){
            int x = q.front().first, y = q.front().second; q.pop();
            for(int i=0; i<8; i++){
                int nx = x+moves[i][0], ny = y+moves[i][1];
                if(valid(nx,ny) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    dis[nx][ny] = dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        int win = INT_MAX, stale = INT_MAX;
        for(int i=pr+1; i<=num_rows; i++){
            if(!vis[i][pc]) continue;
            int num_moved = i-pr;
            if(dis[i][pc] <= num_moved){
                int diff = num_moved-dis[i][pc];
                if(i != num_rows && diff%2 == 0)
                    win = min(win,num_moved);
                if(dis[i][pc] < num_moved && diff%2 == 1)
                    stale = min(stale,num_moved-1);
            }
        }
        if(win == INT_MAX){
            if(stale == INT_MAX){
                printf("Loss in %d knight move(s).\n",num_rows-pr-1);
            }else{
                printf("Stalemate in %d knight move(s).\n",stale);
            }
        }else{
            printf("Win in %d knight move(s).\n",win);
        }
    }
    return 0;
}