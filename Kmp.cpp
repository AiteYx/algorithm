#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 1000005;
const int maxM = 10005;

int a[maxN], b[maxM];
int nex[maxM];
int n, m, T;

void getNext()
{
    int i = 0;  // 数组b的下标
    int j = -1;

    nex[0] = -1;
    while (i < m - 1)
    {
        if (j == -1 || b[i] == b[j])
        {
            i ++;
            j ++;
            nex[i] = j;
        }
        else
            j = nex[j];
    }
}

// nex[j] 表示数组 [ b[0] ,  b[j - 1] ] 这个序列中，最大的、相同的、真前缀和真后缀的个数，即真前缀后一个数的下标。

int main()
{
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);

        getNext();

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (j == -1 || a[i] == b[j])
            {
                i ++;
                j ++;
            }
            else
                j = nex[j];
        }
        if (j == m) cout << i - j + 1 << endl;
        else    cout << -1 << endl;
    }

    return 0;
}