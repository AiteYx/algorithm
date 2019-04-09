#include <bits/stdc++.h>
using namespace std;

const int maxN = 500;
int N, M, gra[maxN][maxN];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        gra[a][b] = c;  // a -> b : c
    }

    // 核心算法
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                if (gra[i][j] && gra[j][k])
                    gra[i][k] = min(gra[i][j] + gra[j][k], gra[i][k]);
    
    return ;
}