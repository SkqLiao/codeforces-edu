/*
 * @date:2021-05-01 00:03:38
 * @source:https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int N, M;
int Anc[MAXN];

int findAnc(int x) {
    return Anc[x] == x ? x : Anc[x] = findAnc(Anc[x]);
}

void merge(int u, int v) {
    u = findAnc(u);
    v = findAnc(v);
    Anc[v] = u;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) Anc[i] = i;
    char s[10];
    for (int i = 1, u, v; i <= M; ++i) {
        scanf("%s%d%d", s, &u, &v);
        if (s[0] == 'u') {
            merge(u, v);
        } else {
            puts(findAnc(u) == findAnc(v) ? "YES" : "NO");
        }
    }
    return 0;
}