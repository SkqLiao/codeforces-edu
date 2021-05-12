/*
 * @date:2021-05-06 00:07:09
 * @source:https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/E
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
int H[MAXN][2], A[MAXN << 1], B[MAXN << 1], C[MAXN][2];
int Fa[MAXN];
int Ans[MAXN];
vector<int> v[MAXN];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void merge(int x, int y, int t) {
    x = findFa(x);
    y = findFa(y);
    if (x == y) return ;
    if (y == findFa(1)) swap(x, y);
    if (x == findFa(1)) for (auto a : v[y]) Ans[a] = t;
    if (v[x].size() < v[y].size()) swap(x, y);
    v[x].insert(v[x].end(), v[y].begin(), v[y].end());
    vector<int>().swap(v[y]);
    Fa[y] = x;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &H[i][0], &H[i][1]);
        Fa[i] = i;
        v[i].push_back(i);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &A[i], &B[i]);
        C[A[i]][--B[i]] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (~H[i][j] && !C[i][j]) {
                merge(i, H[i][j], -1);
            }
        }
    }
    Ans[1] = -1;
    for (int i = M - 1; i >= 0; --i) {
        int x = H[A[i]][B[i]];
        if (x == -1) continue;
        merge(x, A[i], i);
    }
    for (int i = 1; i <= N; ++i) printf("%d\n", Ans[i] == M ? -1 : Ans[i]);
    return 0;
}