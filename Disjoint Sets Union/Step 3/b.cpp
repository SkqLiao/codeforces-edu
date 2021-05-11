/*
 * @date:2021-05-11 23:52:13
 * @source:https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fir first
#define sec second
template <class T> bool chkMax(T &x, T &y) {return y > x ? x = y, 1 : 0;}
template <class T> bool chkMin(T &x, T &y) {return y < x ? x = y, 1 : 0;}

int N, M, K;
vector<pii> E;
struct Query {
    int l, r, id;
};
vector<Query> Q;
vector<int> Pos, L, R, Ans;
struct DSU {
    vector<int> Anc, Siz;
    stack<int> Stk;
    int num;
    void init(int n) {
        Anc.resize(n + 1);
        Siz.resize(n + 1);
        num = n;
        for (int i = 1; i <= n; ++i) {
            Anc[i] = -1;
            Siz[i] = 1;
        }
    }
    int findAnc(int x) {
        while (Anc[x] != -1) x = Anc[x];
        return x;
    }
    void merge(int x, int y) {
        x = findAnc(x);
        y = findAnc(y);
        if (x == y) return ;
        if (Siz[x] > Siz[y]) swap(x, y);
        Anc[x] = y;
        Siz[y] += Siz[x];
        Stk.push(x);
        --num;
    }
    void rewind(int sz) {
        while (Stk.size() > sz) {
            int x = Stk.top();
            Stk.pop();
            Siz[Anc[x]] -= Siz[x];
            Anc[x] = -1;
            ++num;
        }
    }
} t1, t2;

int query(int l, int r) {
    t2.init(N);
    for (int i = l; i <= r; ++i) {
        t2.merge(E[i].fir, E[i].sec);
    }
    return t2.num;
}

void add(int p) {
    t1.merge(E[p].fir, E[p].sec);
}

int main() {
    scanf("%d%d", &N, &M);
    E.resize(M);
    for (auto &e : E) scanf("%d%d", &e.fir, &e.sec);
    E.insert(E.begin(), {0, 0});
    scanf("%d", &K);
    Ans.resize(K);
    Q.resize(K);
    for (int i = 0; i < K; ++i) {
        scanf("%d%d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
    }
    int sz = sqrt(M), tot = M / sz + (M % sz > 0);
    L.resize(tot + 1);
    R.resize(tot + 1);
    for (int i = 1; i <= tot; ++i) {
        L[i] = sz * (i - 1) + 1;
        R[i] = sz * i;
    }
    chkMin(R[tot], M);
    Pos.resize(M + 1);
    for (int i = 1; i <= tot; ++i) {
        for (int j = L[i]; j <= R[i]; ++j) {
            Pos[j] = i;
        }
    }
    sort(Q.begin(), Q.end(), [&](const Query & x, const Query & y) {
        return Pos[x.l] == Pos[y.l] ? x.r < y.r : x.l < y.l;
    });
    t1.init(N);
    for (int i = 1, j = 0; i <= tot; ++i) {
        int l = R[i], r = R[i] - 1;
        for (; j < K && Pos[Q[j].l] == i; ++j) {
            if (Pos[Q[j].r] == i) {
                Ans[Q[j].id] = query(Q[j].l, Q[j].r);
                continue;
            }
            while (r < Q[j].r) add(++r);
            int tmp = t1.Stk.size();
            while (l > Q[j].l) add(--l);
            Ans[Q[j].id] = t1.num;
            l = R[i];
            t1.rewind(tmp);
        }
        t1.rewind(0);
    }
    for (auto x : Ans) printf("%d\n", x);
    return 0;
}