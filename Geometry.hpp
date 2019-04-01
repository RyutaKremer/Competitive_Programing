//螺旋本参考
//LineとSegmentについては厳密に定義している．
/* 各クラスについて,そのクラスの属性を求めるものに関してはメゾッドとした
 * ex) Pointクラスのnorm, absなど
 * */
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

    //外側にも同内容のもの書くかも(可読性を高めるため)
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

    Point intercept()
    {
        Point r(0, c / b);
        return r;
    }

    Vector basis()
    {
        double t = sqrt(a * a + b * b);
        Vector r(b / t, a /t);
        return r;
    }
};

//コンストラクタのオーバーライドに問題あり?
class Segment : public Line {
public:
    Point p1, p2;

    //使わない
    Segment() : p1(0.0, 0.0), p2(0.0, 0.0) {}

    //使わない
    Segment(double a, double b, double c) : Line(a, b, c) {}

    Segment(Point p1, Point p2)
            : Line(p1, p2), p1(p1), p2(p2) {}

    Segment(double x1, double y1, double x2, double y2)
            : Line(x1, y1, x2, y2), p1(x1, y1), p2(x2, y2) {}

    Vector basis()
    {
        Line t(p1, p2);
        return t.basis();
    }
};

//内積
double dot(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

//外積
double cross(Vector v1, Vector v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

//直交判定
bool isOrthogonal(Vector v1, Vector v2)
{
    return equals(dot(v1, v2), 0.0);
}

bool isOrthogonal(Point p1, Point p2, Point p3, Point p4)
{
    return isOrthogonal(p1 - p2, p3 - p4);
}

bool isOrthogonal(Line l1, Line l2)
{
    if (l1.b == 0.0) {
        return (l2.a == 0.0);
    } else if (l2.b == 0.0) {
        return (l1.a == 0.0);
    } else {
        return equals(l1.a / l1.b * l2.a / l2.b, -1.0);
    }
}

bool isOrthogonal(Segment s1, Segment s2)
{
    return equals(dot(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
//これは内積による判定であって実際に直交するわけではない
//実際の直交 -> isOrthogonal && (距離==0.0)

//平行
bool isParallel(Vector v1, Vector v2)
{
    return equals(cross(v1, v2), 0.0);
}

bool isParallel(Point p1, Point p2, Point p3, Point p4)
{
    return equals(cross(p1 - p2, p3 - p4), 0.0);
}

bool isParallel(Line l1, Line l2)
{
    if (l1.b == 0.0) {
        return (l2.b == 0.0 && l2.a != 0.0);
    } else if (l2.a == 0.0) {
        return false;
    } else {
        return equals(l1.a / l1.b, l2.a / l2.b);
    }
}
//上記はSegmentにも適用可？

bool isParallel(Segment s1, Segment s2)
{
    return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}

//射影
Point project(Segment s, Point p)
{
    Vector base = s.basis();
    //螺旋本と異なる．直接基底を使用
    double r = dot(p - s.p1, base);
    return s.p1 + base * r;
}

Point project(Line l, Point p)
{
    Point pbase = l.intercept();
    Vector vbase = l.basis();
    double r = dot(p - pbase, vbase);
    return pbase + vbase * r;
}

//反射
//多分Segmentにも適用可...
Point reflect(Line l, Point p)
{
    return p + (project(l, p) - p) * 2.0;
}

//距離
//Point to Point
double distance(Point p1, Point p2)
{
    return (p1 - p2).abs();
}

//Point to Line
double distance(Line l, Point p)
{
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

//Point to Segment
double distance(Segment s, Point p)
{
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) {
        return distance(p, s.p1);
    } else if (dot(s.p1 - s.p2, p - s.p2) < 0.0) {
        return distance(p, s.p2);
    } else {
        cout<<"segment"<<endl;
        return distance((Line)s, p);
    }
}

//線上にあるか
bool onLine(Line l, Point p)
{
    return equals(distance(l, p), 0.0);
}

bool onSegment(Segment s, Point p)
{
    return equals(distance(s, p), 0.0);
}

//まだ
double distance(Segment s1, Segment s2)
{
    return 0.0;
}


//以下完全オリジナル
class Triangle{
public:
    Point p1, p2, p3;
    //Segment <- 使うか微妙

    Triangle() : p1(), p2(), p3() {}

    Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {}

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}

    double getArea()
    {
        return fabs(cross(p2 - p1, p3 - p1)) / 2;
    }
};
