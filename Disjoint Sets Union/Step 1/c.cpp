/*
 * @date:2021-05-01 00:16:34
 * @source:https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
int Anc[MAXN];
long long Pts[MAXN], Add[MAXN];
vector<int> Child[MAXN];

int findAnc(int x) {
    return Anc[x] == x ? x : Anc[x] = findAnc(Anc[x]);
}

void merge(int u, int v) {
    u = findAnc(u), v = findAnc(v);
    if (u == v) return ;
    if (Child[u].size() > Child[v].size()) swap(u, v);
    for (auto x : Child[u]) {
        Pts[x] += Add[u] - Add[v];
    }
    Add[u] = 0;
    Child[v].insert(Child[v].end(), Child[u].begin(), Child[u].end());
    Anc[u] = v;
}

void add(int x, int v) {
    x = findAnc(x);
    Add[x] += v;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        Anc[i] = i;
        Child[i].push_back(i);
    }
    char s[10];
    for (int i = 1, u, v; i <= M; ++i) {
        scanf("%s%d", s, &u);
        if (s[0] == 'j') {
            scanf("%d", &v);
            merge(u, v);
        } else if (s[0] == 'a') {
            scanf("%d", &v);
            add(u, v);
        } else {
            int x = findAnc(u);
            printf("%lld\n", Pts[u] + Add[x]);
        }
    }
    return 0;
}