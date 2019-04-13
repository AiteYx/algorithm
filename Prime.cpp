#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
int n, pri[maxN], index;
int vis[maxN];


void prime1()
{
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri[index++] = i;
        else
        {
            for (int j = i * i; j < n; j += i)
            {
                vis[j] = 1;
            }
        }
        
    }
}

void prime2()
{
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            pri[index++] = i;
        
        for (int j = 0; j < index && i * pri[j] < n; j++)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)    break;
        }
    }

}

int main()
{
    memset(vis, 0, sizeof(vis));
    index = 0;

    // prime1();
    // prime2();

    return 0;
}