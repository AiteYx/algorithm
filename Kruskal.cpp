#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1000;
const int maxM = 4000;
struct Struct
{
    /* data */
    int peak1, peak2, value;
}edge[maxM], tmp;
int N, M, father[maxN];

bool camp(Struct a, Struct b) { return a.value < b.value;}

int getF(int x) {

    if (father[x] == x) return x;
    return father[x] = getF(father[x]);
}

void kruskal() {

    int cnt = 0;
    for (int i = 1; i <= N; i++)    father[i] = i;

    for (int i = 0; i < M; i++) {

        tmp = edge[i];
        int p1 = tmp.peak1, p2 = tmp.peak2;
        if (getF(p1) == getF(p2))   continue;
        father[getF(p1)] = getF(p2);
        cnt++;

        if (cnt == N - 1) {

            cout << "最小生成树成功";
        }
    }

    cout << "失败";
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {

        int a, b, c;    cin >> a >> b >> c;
        edge[i].value = c;
        edge[i].peak1 = a;
        edge[i].peak2 = b;
    }

    sort(edge, edge + M, camp);
    kruskal();

    return 0;
}