#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

#define EPS 1e-10
#define equals(a, b) (fabs(a - b) < EPS)

class Point{
public:
    double x, y;

    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    Point operator + (Point p)
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator - (Point p)
    {
        return Point(x - p.x, y - p.y);
    }

    Point operator * (double d)
    {
        return Point(x * d, y * d);
    }

    Point operator / (double d)
    {
        return Point(x / d, y / d);
    }

    //大小関係未定義

    bool operator == (const Point &p) const
    {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    bool operator != (const Point &p) const
    {
        return !(*this == p);
    }

    double norm()
    {
        return x * x + y * y;
    }

    double abs()
    {
        return sqrt(this->norm());
    }
};

typedef Point Vector;

class Line {
public:
    //ax + by + c = 0
    double a, b, c;

    //使わない
    Line() : a(0.0), b(0.0), c(0.0) {}

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Line(Point p1, Point p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        a = dy;
        b = -dx;
        c = -dy + dx;
    }

    Line(double x1, double y1, double x2, double y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        a = dy;
        b = -dx;
        c = -dy + dx;
    }
};

//コンストラクタのオーバーライドに問題あり
class Segment : public Line {
public:
    Point p1, p2;

    //使わない
    Segment() : p1(0.0, 0.0), p2(0.0, 0.0) {}

    //使わない
    Segment(double a, double b, double c) : Line(a, b, c) {}

    Segment(Point p1, Point p2)
    : Line(p1, p2), p1(p1), p2(p2) {
        /*double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        a = dy;
        b = -dx;
        c = -dy + dx;*/
    }

    Segment(double x1, double y1, double x2, double y2)
    : Line(x1, y1, x2, y2), p1(x1, y1), p2(x2, y2) {
        /*double dx = x1 - x2;
        double dy = y1 - y2;
        a = dy;
        b = -dx;
        c = -dy * x1 + dx * y1;*/
    }

    double getDistanceTo(Point p)
    {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
};

double distancePP(Point p1, Point p2)
{
    return (p1 - p2).abs();
}

//内積
double dotVV(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

//外積
double crossVV(Vector v1, Vector v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

double distancePL(Point p, Line l)
{
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

//いつか書く
double distancePS(Point p, Segment s)
{
    return 0.0;
}

int main()
{
    Segment s(1, 2, 3, 4);
    Point a(2,4), b(8,16);
    Segment t(a,b);

    cout<<s.a<<s.b<<s.c;
    cout<<t.a<<t.b<<t.c;

    return 0;
}
