/*
 * @date:2021-05-06 23:38:52
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int L[MAXN], R[MAXN], A[MAXN], Fa[MAXN];
int n, m;
char s[4];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void merge(int x, int y) {
    x = findFa(x);
    y = findFa(y);
    if (x == y) return ;
    L[x] = min(L[x], L[y]);
    R[x] = max(R[x], R[y]);
    Fa[y] = x;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        L[i] = R[i] = Fa[i] = i;
    }
    for (int i = 1, x; i <= m; ++i) {
        scanf("%s%d", s, &x);
        if (s[0] == '-') {
            if (!A[x + 1]) R[x] = x + 1;
            else merge(x + 1, x);
            if (!A[x - 1]) L[x] = x - 1;
            else merge(x - 1, x);
            A[x] = 1;
        } else {
            int y = R[findFa(x)];
            printf("%d\n", y > n ? -1 : y);
        }
    }
    return 0;
}