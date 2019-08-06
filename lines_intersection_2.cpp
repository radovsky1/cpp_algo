#include <iostream>
#include <algorithm>

#define EPS (double)1e-9

using namespace std;

struct Line {
  double a , b , c;
};

struct Point {
  double x , y;
};

double det(double a , double b , double c , double d) {
  return a * d - b * c;
}

Line make_line(Point &a , Point &b) {
  Line result;
  result.a = a.y - b.y;
  result.b = b.x - a.x;
  result.c = -result.a * a.x - result.b * a.y;
  return result;
}

bool intersect(const Line &n , const Line &m , Point &intersection_point) {
  double zn = det(n.a , n.b , m.a , m.b);
  if (abs(zn) < EPS)
    return false;
  intersection_point.x = -det(n.c , n.b , m.c , m.b) / zn;
  intersection_point.y = -det(n.a , n.c , m.a , m.c) / zn;
  return true;
}

bool lines_equal(const Line &n , const Line &m) {
  double res1 = abs(det(n.a , n.b , m.a , m.b));
  double res2 = abs(det(n.a , n.c , m.a , m.c));
  double res3 = abs((det(n.b , n.c , m.b , m.c)));
  return (res1 < EPS && res2 < EPS && res3 < EPS);
}

int32_t main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0) , cout.tie(0);
  Point a , a1;
  cin >> a.x >> a.y >> a1.x >> a1.y;
  Point b , b1;
  cin >> b.x >> b.y >> b1.x >> b1.y;
  Line n = make_line(a , a1) , m = make_line(b , b1);
  Point intersection;
  if (intersect(n , m , intersection)) {
    cout << "1" << " "; // type (optional)
    cout << fixed << intersection.x << " " << intersection.y << '\n';
    return 0;
  }
  if (lines_equal(n , m)) {
    cout << "2" << " "; // type (optional)
    return 0;
  }
  cout << "0" << " "; // type (optional)
  return 0;
}
