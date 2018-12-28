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
            : Line(p1, p2), p1(p1), p2(p2) {}

    Segment(double x1, double y1, double x2, double y2)
            : Line(x1, y1, x2, y2), p1(x1, y1), p2(x2, y2) {}
};

//Point to Point
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

//Point to Line
double distancePL(Point p, Line l)
{
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

//Point to Segment
//いつか書く
double distancePS(Point p, Segment s)
{
    return 0.0;
}