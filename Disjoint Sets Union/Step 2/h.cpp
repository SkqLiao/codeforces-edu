/*
 * @date:2021-05-10 22:25:45
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/H
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000 + 5;

int N, M;
long long K;
int Anc[MAXN];
struct Edge {
    int u, v, w, id;
    bool operator < (const Edge &x) const {
        return w > x.w;
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
    scanf("%d%d%lld", &N, &M, &K);
    for (int i = 1; i <= N; ++i) Anc[i] = i;
    E.resize(M);
    int id = 1;
    for (auto &e : E) {
        scanf("%d%d%d", &e.u, &e.v, &e.w);
        e.id = id++;
    }
    sort(E.begin(), E.end());
    int num = 0;
    for (int i = 0; i < M; ++i) {
        if (merge(E[i].u, E[i].v)) {
            E[i].id = 0;
            if (++num == N - 1) break;
        }
    }
    vector<int> ans;
    for (int i = M - 1; i >= 0; --i) {
        if (K < E[i].w) break;
        if (!E[i].id) continue;
        ans.push_back(E[i].id);
        K -= E[i].w;
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (auto x : ans) {
        printf("%d ", x);
    }
    return 0;
}