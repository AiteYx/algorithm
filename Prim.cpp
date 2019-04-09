#include <bits/stdc++.h>
using namespace std;

const int maxN = 306;
int n, father[maxN] = {0};
struct EDGE 
{
    int from, to, value;
    EDGE() {}
    EDGE(int a1, int a2, int a3)
    {
        this->from = a1;
        this->to = a2;
        this->value = a3;
    }
    friend bool operator < (EDGE a, EDGE b)
    {
        return a.value > b.value;
    }
}tmp;
priority_queue<EDGE> Q;

int getFather(int a)
{
    if (a == father[a]) return a;
    else    return father[a] = getFather(father[a]);
}

int Prim()
{
    int sum = 0;

    while (!Q.empty())
    {
        tmp = Q.top();
        if (getFather(tmp.from) != getFather(tmp.to))
        {
            father[father[tmp.from]] = father[tmp.to];
            sum += tmp.value;
        }
        Q.pop();
    }
    return sum;
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;  cin >> p;
            if (i == j) continue;
            Q.push(EDGE(i, j, p));
        }
    }

    cout << Prim();
    return 0;
}