/*
 * @date:2021-05-11 11:56:02
 * @source:https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fir first
#define sec second
template<class T> bool chkMax(T &x, T &y) {return y > x ? x = y, 1 : 0;}
template<class T> bool chkMin(T &x, T &y) {return y < x ? x = y, 1 : 0;}

int N, M;
vector<int> Rt, Num;
struct Node {
    int fa, dep, l, r;
} node;
vector<Node> A;

int newNode(Node &x) {
    A.push_back(x);
    return A.size() - 1;
}

int build(int l, int r) {
    int rt = newNode(node);
    if (l == r) {
        A[rt].fa = l;
        return rt;
    }
    int m = (l + r) >> 1;
    A[rt].l = build(l, m);
    A[rt].r = build(m + 1, r);
    return rt;
}

int query(int rt, int l, int r, int p) {
    if (l == r) return rt;
    int m = (l + r) >> 1;
    if (p <= m) return query(A[rt].l, l, m, p);
    else return query(A[rt].r, m + 1, r, p);
}

int findAnc(int rt, int x) {
    int fx = query(rt, 1, N, x);
    return A[fx].fa == x ? fx : findAnc(rt, A[fx].fa);
}

int update(int pre, int l, int r, int p, int x) {
    int rt = newNode(A[pre]);
    if (l == r) {
        A[rt].fa = x;
        return rt;
    }
    int m = (l + r) >> 1;
    if (p <= m) A[rt].l = update(A[pre].l, l, m, p, x);
    else A[rt].r = update(A[pre].r, m + 1, r, p, x);
    return rt;
}

void add(int rt, int l, int r, int p) {
    if (l == r) {
        ++A[rt].dep;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) add(A[rt].l, l, m, p);
    else add(A[rt].r, m + 1, r, p);
}

bool merge(int &rt, int x, int y) {
    int fx = findAnc(rt, x);
    int fy = findAnc(rt, y);
    if (fx == fy) return 0;
    if (A[fx].dep > A[fy].dep) swap(fx, fy);
    rt = update(rt, 1, N, A[fx].fa, A[fy].fa);
    if (A[fx].dep == A[fy].dep) add(rt, 1, N, A[fy].fa);
    return 1;
}

vector<int> p;

int main() {
    scanf("%d%d", &N, &M);
    A.reserve(2 * M * (int)log2(N));
    Rt.push_back(build(1, N));
    Num.push_back(N);
    char opt[10];
    for (int i = 1, u, v; i <= M; ++i) {
        Num.push_back(Num.back());
        Rt.push_back(Rt.back());
        scanf("%s", opt);
        if (opt[0] == 'u') {
            scanf("%d%d", &u, &v);
            Num[i] -= merge(Rt[i], u, v);
            printf("%d\n", Num[i]);
        } else if (opt[0] == 'p') {
            p.push_back(i);
        } else {
            int x = p.back();
            p.pop_back();
            Rt[i] = Rt[x];
            Num[i] = Num[x];
            printf("%d\n", Num[i]);
        }
    }
    return 0;
}