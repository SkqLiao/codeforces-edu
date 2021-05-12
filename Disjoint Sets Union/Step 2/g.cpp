/*
 * @date:2021-05-10 22:06:54
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/G
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1500 + 5;

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
    for (int i = 1; i <= N; ++i) Anc[i] = i;
    E.resize(M);
    for (auto &e : E) {
        scanf("%d%d%d", &e.u, &e.v, &e.w);
    }
    sort(E.begin(), E.end());
    int num = 0;
    for (auto e : E) {
        if (merge(e.u, e.v)) ++num;
        if (num == N - 1) {
            printf("%d\n", e.w);
            break;
        }
    }
    return 0;
}