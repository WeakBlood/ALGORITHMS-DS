#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1005;
int tree[MAXN*4][MAXN*4];
int grid[MAXN][MAXN];
int N,M;
    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) 
    {
        if (ly == ry) 
        {
            if (lx == rx) tree[vx][vy] = grid[lx][ly];
            else tree[vx][vy] = tree[vx*2][vy] + tree[vx*2+1][vy];
        } 
        else 
        {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            tree[vx][vy] = tree[vx][vy*2] + tree[vx][vy*2+1];
        }
    }

    void build_x(int vx, int lx, int rx) {
        if (lx != rx) 
        {
            int mx = (lx + rx) / 2;
            build_x(vx*2, lx, mx);
            build_x(vx*2+1, mx+1, rx);
        }
        build_y(vx, lx, rx, 1, 0, M-1);
    }

    ll sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) 
        {
            return 0;
        }
        if (ly == tly && try_ == ry) 
        {
            return tree[vx][vy];
        }
        int tmy = (tly + try_) / 2;
        return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy)) + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
    }

    ll sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) 
    {
        if (lx > rx) 
        {
            return 0;
        }
        if (lx == tlx && trx == rx) 
        {
            return sum_y(vx, 1, 0, M-1, ly, ry);
        }
        int tmx = (tlx + trx) / 2;
        return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry) + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
    }


int main() {
    int N,Q;
    cin >> N >> Q;
    M = N;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            if(c == '*')
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }
    build_x(1,0,N-1);
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // Adjust for 0-based indexing if necessary
        cout << sum_x(1, 0, N-1, x1-1, x2-1, y1-1, y2-1) << endl;
    }

    return 0;
}
