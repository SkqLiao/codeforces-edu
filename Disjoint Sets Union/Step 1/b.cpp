/*
 * @date:2021-05-01 00:11:54
 * @source:https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

int N, M;
int Anc[MAXN], Mx[MAXN], Mn[MAXN], Sz[MAXN];

int findAnc(int x) {
    return Anc[x] == x ? x : Anc[x] = findAnc(Anc[x]);
}

void merge(int u, int v) {
    u = findAnc(u), v = findAnc(v);
    if (u == v) return ;
    Anc[u] = v;
    Sz[v] += Sz[u];
    Mx[v] = max(Mx[v], Mx[u]);
    Mn[v]= min(Mn[v], Mn[u]);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) Anc[i] = Mn[i] = Mx[i] = i, Sz[i] = 1;
    char s[10];
    for (int i = 1, u, v; i <= M; ++i) {
        scanf("%s%d", s, &u);
        if (s[0] == 'u') {
            scanf("%d", &v);
            merge(u, v);
        } else {
            int x = findAnc(u);
            printf("%d %d %d\n", Mn[x], Mx[x], Sz[x]);
        }
    }
    return 0;
}