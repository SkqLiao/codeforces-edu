/*
 * @date:2021-05-07 12:10:29
 * @source:https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/D
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

int N, M;
int Fa[MAXN], Len[MAXN], Add[MAXN];
vector<int> v[MAXN];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void merge(int x, int y) {
    x = findFa(x);
    y = findFa(y);
    if (x == y) return ;
    if (v[x].size() > v[y].size()) swap(x, y);
    for (auto u : v[x]) Len[u] += Add[x] - Add[y];
    Add[x] = 0;
    v[y].insert(v[y].end(), v[x].begin(), v[x].end());
    Fa[x] = y;
    vector<int>().swap(v[x]);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        Fa[i] = i;
        v[i].push_back(i);
    }
    for (int i = 1, opt, x, y; i <= M; ++i) {
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d%d", &x, &y);
            Add[findFa(x)] += Len[y] + Add[findFa(y)] + 1;
            merge(x, y);
        } else {
            scanf("%d", &x);
            printf("%d\n", Len[x] + Add[findFa(x)]);
        }
    }
    return 0;
}