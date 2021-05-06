/*
 * @date:2021-05-07 00:02:54
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000 + 5;

int n;
int A[MAXN], R[MAXN], Fa[MAXN];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

int getL(int x) {
    return x == 1 ? n : x - 1;
}

int getR(int x) {
    return x == n ? 1 : x + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        R[i] = Fa[i] = i;
    }
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        x = R[findFa(x)];
        printf("%d ", x);
        A[x] = 1;
        if (A[getR(x)]) {
            Fa[x] = findFa(getR(x));
        } else {
            R[x] = getR(x);
        }
        if (A[getL(x)]) {
            Fa[findFa(getL(x))] = Fa[x];
        }
    }
    return 0;
}