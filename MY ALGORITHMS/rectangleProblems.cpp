#include <bits/stdc++.h>

using namespace std;


bool flippingAround(int i, int j, vector<vector<bool>> &grid)
{
    if(grid[i][j])
    {
        for(int k = 0; k <= i; k++)
        {
            for(int l = 0; l <= j; l++)
            {
                grid[k][l] = !grid[k][l];
            }
        }
        return true;
    }

    return false;
}
int main()
{
    ifstream cin("cowtip.in");
    ofstream cout("cowtip.out");
    int N;
    cin >> N;

    vector<vector<bool>> grid(N,vector<bool>(N));

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            char c; cin >> c;
            grid[i][j] = c == '0' ? false:true;
        }
    }

    int x = N-1; int y = N-1;
    int flips = 0;
    while(x >= 0 && y>= 0)
    {
        flips+=flippingAround(x,y,grid);
        if(x != y) flips+= flippingAround(y,x,grid);

        if(x > 0) x--;
        else { y--; x = y;}
    }   
    cout << flips << "\n";
        


    return 0;
}