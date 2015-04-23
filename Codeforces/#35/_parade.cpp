#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

struct Tree
{
    int begin, end;
    int high;
}tree[800000];
void build(int begin, int end, int now)
{
    tree[now].begin = begin, tree[now].end = end;
    tree[now].high = 0;
    if (end - begin > 1)
    {
        int mid  = (begin + end) >> 1;
        build (begin, mid, now << 1);
        build (mid, end , (now << 1) + 1);
    }
}

void insert(int begin, int end, int now, int high)
{
    if (begin <= tree[now].begin && tree[now].end <= end && tree[now].high < high)
    {
        tree[now].high = high;
    }
    else if (tree[now].high >= high)
    {
        return ;
    }
    else
    {
        int mid = (tree[now].begin + tree[now].end) >> 1;
        if (begin < mid) insert(begin, end, now << 1, high);
        if (mid < end) insert(begin, end, (now << 1) + 1, high);
    }
}

void query(int begin, int end, int now, int &ans)
{
    if (tree[now].high > ans) ans = tree[now].high;
    if (tree[now].end - tree[now].begin > 1)
    {
        int mid = (tree[now].begin + tree[now].end) >> 1;
        if ( begin < mid ) query(begin, end, now << 1, ans);
        if ( mid < end ) query(begin, end, (now << 1) + 1, ans);
    }
}

struct data
{
    int h, l, r;
}d[100005];
int cnt2;
int in1[200005];
int in2[200005];
int n;
int find(int u)
{
    int low = 0;
    int high = cnt2;
    int mid;
    while (low < high)
    {
        mid = (low + high) >> 1;
        if (u < in2[mid]) high = mid;
        else if (u > in2[mid]) low = mid + 1;
        else return mid;
    }
}

int out[550005][2];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf("%d", &n);
    int cnt1 = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d %d %d", &d[i].h, &d[i].l, &d[i].r);
        in1[cnt1++] = d[i].l;
        in1[cnt1++] = d[i].r;
    }
    std::sort(in1, in1 + cnt1);
    cnt2 = 0;
    for (int i = 0; i < cnt1 ; ++i)
    {
        if (i + 1 <cnt1 && in1[i] == in1[i + 1]) continue;
        in2[cnt2++] = in1[i];
    }

    build(0, cnt2, 1);
    for (int i = 0; i < n; ++i)
    {
        insert(find(d[i].l), find(d[i].r), 1, d[i].h);
    }
    int cnt3 = 0;
//    out[0][0] = in2[0];
//    out[0][1] = 0;
    int pre = 0;
    int h;
    for (int i = 0; i < cnt2; ++i)
    {
        h = 0;
        query(i, i + 1, 1, h);
        if (h != pre)
        {
            out[cnt3][0] = in2[i];
            out[cnt3++][1] = pre;
            out[cnt3][0] = in2[i];
            out[cnt3++][1] = h;
            pre = h;
        }
//        printf("%d %d %d", i, i + 1, ans);
    }
    printf("%d\n", cnt3);
    for (int i = 0; i < cnt3; ++i)
    {
        printf("%d %d\n", out[i][0], out[i][1]);
    }
//for (int i = 1; i < 10; ++i)
//printf("%d %d %d %d\n", i, tree[i].begin, tree[i].end, tree[i].high);


    return 0;
}
