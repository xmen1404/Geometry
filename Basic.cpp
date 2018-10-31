#include<bits/stdc++.h>
using namespace std;

struct point    {
    int x, y;
    point(int x = 0, int y = 0) :x(x), y(y) {}
    double norm() {
        return x * x + y * y;
    }
};

struct line{
    double a, b, c;
};

struct circle{
    double x, y, r;
};

namespace Geometry{
    double dist(point a, point b) {
        return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    bool areParallel(line l1, line l2)  {
        return (l1.a * l2.b == l1.b * l2.a);
    }
    bool areIntersect(line l1, line l2, point &p){
        if(areParallel(l1, l2)) return false;
        double dx = l1.b * l2.c - l1.c * l2.b;
        double dy = l1.c * l2.a - l1.a * l2.c;
        double d = l1.a * l2.b - l1.b * l2.a;
        p = point{dx/d, dy/d};
        return true;
    }
    
    line getLine(point p1, point p2)    {
        double a = p2.y - p1.y;
        double b = p1.x - p2.x;
        double c = a * p1.x + b * p1.y;
        return {a, b, c};
    }
    
    bool check1(point l, point r, point p)    {
        if(l.x == r.x) return (p.y >= min(l.y, r.y) && p.y <= max(l.y, r.y));
        if(l.y == r.y) return (p.x >= min(l.x, r.x) && p.x <= max(l.x, r.x));
        line cur = getLine(l, r);
        cur.a /= cur.b; cur.c /= cur.b;
        cur.a = -cur.a; cur.c = -cur.c;
        point p1 = {l.x + 1, l.y - cur.a};
        point p2 = {r.x + 1, r.y - cur.a};
        return (ccw(p - l, p1 - l) * ccw(p - r, p2 - r) <= 0);
    }
    
    point getCircumcircle(point a, point b, point c)    {
        double d = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
        double dx = a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y) / d;
        double dy = a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x) / d;
        return {dx, dy};
    }
    // circle
    bool circleIntersect(circle a, circle b)    {
        if(dist({a.x, a.y}, {b.x, b.y}) - a.r - b.r > 0) return false;
        if(dist({a.x, a.y}, {b.x, b.y}) + a.r - b.r < 0) return false;
        if(dist({a.x, a.y}, {b.x, b.y}) - a.r + b.r < 0) return false;
        return true;
    }

};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

}
