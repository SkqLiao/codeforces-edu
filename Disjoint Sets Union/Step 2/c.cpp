/*
 * @date:2021-05-07 11:28:13
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 5;

int N, M;
int Fa[MAXN], Anc[MAXN];
int R[MAXN];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

int findAnc(int x) {
    return Anc[x] == x ? x : Anc[x] = findAnc(Anc[x]);
}

void merge(int x, int y, int type) {
    x = findFa(x);
    y = findFa(y);
    if (x == y) return ;
    if (!type) Fa[x] = y;
    Anc[findAnc(x)] = findAnc(y);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        Fa[i] = R[i] = Anc[i] = i;
    }
    for (int i = 1, opt, l, r; i <= M; ++i) {
        scanf("%d%d%d", &opt, &l, &r);
        if (opt == 1) {
            merge(l, r, 1);
        } else if (opt == 2) {
            for (int i = R[findFa(l)]; i < r; i = R[findFa(i + 1)]) {
                merge(i, i + 1, 0);
            }
        } else {
            puts(findAnc(findFa(l)) == findAnc(findFa(r)) ? "YES" : "NO");
        }
    }
    return 0;
}