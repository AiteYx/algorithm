#include <iostream>
#include <cstring>

using namespace std;

const int maxF = 1025;
int F, mf, cnt = 0;
int edgeNum[maxF];
int gra[maxF][maxF];
int degree[maxF];
int ans[maxF];

void eulerPath(int start) {

    for (int i = 1; i <= mf; i++) {

        if (gra[start][i]) {

            gra[start][i] --;
            gra[i][start] --;
            eulerPath(i);
        }
    }

    ans[cnt++] = start;
}

int main() {

    memset(gra, 0, sizeof(gra));
    memset(degree, 0, sizeof(degree));
    memset(ans, 0, sizeof(ans));

    cin >> F;
    for (int i = 0; i < F; i++) {

        int a, b;   cin >> a >> b;
        gra[a][b] ++;
        gra[b][a] ++;
        degree[a] ++;
        degree[b] ++;
        mf = max(mf, max(a, b));
    }

    int start = 1;
    for (int i = 1; i <= mf; i++) {

        if (degree[i] % 2) {
            start = i;
            break;
        }
    }

    eulerPath(start);

    // 倒叙输出得到欧拉路径
    for (int i = cnt - 1; i > -1; i--)  cout << ans[i] << endl;

    return 0;
}