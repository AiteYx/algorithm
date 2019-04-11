#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 10000;
const int MAXM = 10006;
struct Struct
{
    int to;
    int len;
    int nex;
    Struct(){}
    Struct(int T, int LEN, int NEX) {
        this->to = T;
        this->len = LEN;
        this->nex = NEX;
    }
}tmp, edge[MAXM];
int first[MAXN] = {0}, cnt = 1;
int dis[MAXN];
int N, M, beg;

bool spfa(int beg) {

    memset(dis, 0x3f, sizeof(dis));
    int cnt[MAXN] = {0};
    int vis[MAXN] = {0};
    queue<int> Q;   Q.push(beg);
    vis[beg] = cnt[beg] = 1;
    dis[beg] = 0;

    while (!Q.empty()) {

        int q = Q.front(); Q.pop();
        vis[q] = 0;

        for (int i = first[q]; i; i = edge[i].nex) {

            tmp = edge[i];
            if (dis[q] + tmp.len < dis[tmp.to]) {

                dis[tmp.to] = dis[q] + tmp.len;
                if (!vis[tmp.to]) {

                    if (++cnt[tmp.to] == N)
                        return false;

                    Q.push(tmp.to);
                    vis[tmp.to] = 1;

                }
            }
        }
    }

    return true;

}

int main() {

    cin >> N >> M;
    beg = 1;
    for (int i = 0; i < M; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        edge[cnt].to = b;
        edge[cnt].len = c;
        edge[cnt].nex = first[a];
        first[a] = cnt++;
    }

    if (!spfa(beg)) {

        cout << "error";
        return 0;
    }

    for (int i = 2; i <= N; i++)
        cout << dis[i] << endl;

    return 0;
}