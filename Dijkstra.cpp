#include <iostream> 
#include <cstring>
#include <queue>            // 优先队列可以用 set 替换
#include <vector>
using namespace std;

int N, P, C;
int gra[850][850] = {0};    // 邻接矩阵存图
int first[850] = {0}, nex[3000], v[3000], w[3000], cnt = 0; // 邻接表存图（向前星）
int dis[850];               // 表示离源点的距离
int vis[850];               // 标记该点是否作为近点处理过

struct STRUCT{              // 结构体（优先队列时使用）
	
	int v;                  /* 表示点 */
	int point;              // 表示该点目前离源点的距离 = dis[v]
	STRUCT() {}
	STRUCT(int v, int point) {
		
		this->v = v;
		this->point = point;
	}
	friend bool operator < (STRUCT a, STRUCT b) {           // 友元函数（优先队列按照v的值，从小到大排列）
		
		return a.v > b.v;
	}
}start;

// 优先队列 + 邻接表
void dijkstra3(int x) {
	
	memset(vis,   0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	dis[x] = 0;
	priority_queue<STRUCT> Q;
	Q.push(STRUCT(0, x));
	
	while (!Q.empty()) {
		
		start = Q.top();
		Q.pop();
		
		int s = start.point;
		
		if (vis[s])	continue;
		vis[s] = 1;
		
		for (int i = first[s]; i > 0; i = nex[i]) {
			
			if (w[i] + dis[s] < dis[v[i]]) {
				
				dis[v[i]] = w[i] + dis[s];
				Q.push(STRUCT(dis[v[i]], v[i]));
			}
		}
	}
}

// 优先队列 + 邻接图
void dijkstra2(int x) {
	
	memset(vis,   0, sizeof(vis));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	dis[x] = 0;
	priority_queue<STRUCT> Q;
	Q.push(STRUCT(0, x));
	
	while (!Q.empty()) {
		
		start = Q.top();
		Q.pop();
		
		int s = start.point;
		int v = start.v;
		
		if (vis[s])	continue;
		vis[s] = 1;
		
		for (int i = 1; i <= P; i++) { 
		
			if (gra[s][i] != -1 && gra[s][i] + v < dis[i]) {
				
				dis[i] = gra[s][i] + v;
				Q.push(STRUCT(dis[i], i)); 
			}
		}
	}
}

// 邻接图 + 原始算法
void dijkstra(int x) {
	
	memset(vis,  0, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	dis[x] = 0;
	
	int start = x, min_value;
	for (int i = 1; i <= N - 1; i++) {
		
		min_value = 300;
		for (int j = 1; j <= P; j++) {
			
			if (dis[j] >= 0 && min_value > dis[j] && vis[j] == 0) {
				
				min_value = dis[j];
				start = j;
			}
		}
		vis[start] = 1;
		for (int j = 1; j <= P; j++) {
			
			if (gra[start][j] < 0)	continue;
			if (dis[j] == -1)	dis[j] = gra[start][j];
			else
				dis[j] = min(dis[j], dis[start] + gra[start][j]);
		}
	}
}

// 邻接图存边  存a点到b点，权值为c的边
void inEdge(int a, int b, int c) {
	
	nex[++cnt] = first[a];
	first[a] = cnt;
	v[cnt] = b;
	w[cnt] = c;
}

/* 算法大致思想如下

首先所有的点到源点的距离都是无穷大

枚举源点为起点的所有边，找到权值最小的边对应的终点，将终点设为近点K
以该近点为中间点，枚举以近点K为起点的所有边，边终点为Q，比较源点-近点-终点（P->K->Q）和源点-终点（P->Q）的距离哪个小，dis[Q]=小的

枚举源点为起点的所有边，找到权值第二小的边对应的终点，将终点设为近点K
以该近点为中间点，枚举以近点K为起点的所有边，边终点为Q，比较源点-近点-终点（P->K->Q）和源点-终点（P->Q）的距离哪个小，dis[Q]=小的

枚举源点为起点的所有边，找到权值第三小的边对应的终点，将终点设为近点K
以该近点为中间点，枚举以近点K为起点的所有边，边终点为Q，比较源点-近点-终点（P->K->Q）和源点-终点（P->Q）的距离哪个小，dis[Q]=小的

...

一直枚举N-1个点（每次枚举过一个近点K，就设置vis[K] = 1，下次枚举vis=0的最小的就可以了） */
int main() {
	
	cin >> N >> P >> C;     // 输入点的个数N，边的个数C，源点P
	for (int i = 0; i < C; i++) {   // 输入每个边的起点终点权值
		
		int a, b, c;
		cin >> a >> b >> c;
		inEdge(a, b, c);    // 单向边只需要存边一次，双向边则需要两次
		inEdge(b, a, c);
	}

	dijkstra3(P);           // 运行

	return 0;
}
