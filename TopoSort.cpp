#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 2000;
int N, M;               // N个节点，M条边
int in_degree[MAX_N];   // 每个节点的入度
vector<int> V[MAX_N];   // 存从每个节点的出发边，即边的起点为数组下标
int topo[MAX_N], cnt;   // 拓扑排序数组，和数组大小cnt，要倒叙输出

int main() {

    cin >> N >> M;
    for (int i = 0; i < M; i++) {

        int a, b;   cin >> a >> b;
        in_degree[b]++;             // 更新入度
        V[a].push_back(b);          // 存边
    }

    queue<int> Q;
    for (int i = 1; i <= N; i++) {

        if (in_degree[i] == 0)      // 将所有入度为0的点放入队列，这些点可以按照任意顺序（依题目而定）
            Q.push(i);
    }

    // 每当得到一个点q，将以q点为起点的所有的边的终点z的入度减去一个，若之后点z入度为0，则可以将点z进入队列
    while (!Q.empty()) {

        int q = Q.front();  Q.pop();
        topo[cnt] = q;  cnt++;

        for (int i = 0; i < V[q].size(); i++) {

            int z = V[q][i];
            in_degree[z]--;
            if (in_degree[z] == 0)
                Q.push(z);
        }
    }

    for (int i = cnt-1; i >= 0; i--)    cout << topo[i] << endl;    // 倒叙输出

    return 0;
}