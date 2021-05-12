/*
 * @date:2021-05-10 21:02:17
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/F
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 5;

int N, M;
int Anc[MAXN];
struct Edge {
    int u, v, w;
    bool operator < (const Edge &x) const {
        return w < x.w;
    }
};
vector<Edge> E;

int findAnc(int x) {
    return Anc[x] == x ? x : Anc[x] = findAnc(Anc[x]);
}

bool merge(int x, int y) {
    x = findAnc(x);
    y = findAnc(y);
    if (x == y) return 0;
    Anc[y] = x;
    return 1;
}

int main() {
    scanf("%d%d", &N, &M);
    E.resize(M);
    for (auto &e : E) scanf("%d%d%d", &e.u, &e.v, &e.w);
    sort(E.begin(), E.end());
    int ans = INT_MAX;
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j <= N; ++j) Anc[j] = j;
        int num = 0;
        for (int j = i; j < M; ++j) {
            if (merge(E[j].u, E[j].v)) ++num;
            if (num == N - 1) {
                ans = min(ans, E[j].w - E[i].w);
                break;
            }
        }
    }
    if (ans == INT_MAX) puts("NO");
    else {
        puts("YES");
        printf("%d\n", ans);
    }
    return 0;
}