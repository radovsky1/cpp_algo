#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>

#define real long double
#define BigReal __float128
#define EPS (real)1e-9

using namespace std;

struct Point {
  real x , y;
};

struct Circle {
  Point center;
  real R;
};

struct Line {
  real A , B , C;
};

Point getMid(Point &pt1 , Point &pt2) {
  return Point{(pt1.x + pt2.x) / 2.0 , (pt1.y + pt2.y) / 2.0};
}

bool onLine(Point &pt1 , Point &pt2 , Point &pt3) {
  return ((pt3.x - pt1.x) * (pt2.y - pt1.y) - (pt2.x - pt1.x) * (pt3.y - pt1.y) == 0);
}

bool real_equal(real a , real b) {
  if (fabs(a - b) <= EPS)
    return true;
  return false;
}

real dist(Point &a , Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

real det(real a , real b , real c , real d) {
  return a * d - b * c;
}

Point intersect(Line &m , Line &n) {
  Point result;
  real zn = det(m.A , m.B , n.A , n.B);
  result.x = -det(m.C , m.B , n.C , n.B) / zn;
  result.y = -det(m.A , m.C , n.A , n.C) / zn;
  return result;
}

Circle getCircumcircle(Point &pt1 , Point &pt2 , Point &pt3) {
  real a = dist(pt1 , pt2);
  real b = dist(pt3 , pt2);
  real c = dist(pt1 , pt3);
  real p = (a + b + c) / 2.0;
  real R = a * b * c / (4.0 * sqrt(p * (p - a) * (p - b) * (p - c)));

  Line AB , AC;
  AB.A = pt1.x - pt2.x;
  AB.B = pt1.y - pt2.y;
  AB.C = -AB.A * (pt1.x + pt2.x) / 2 - AB.B * (pt1.y + pt2.y) / 2;

  AC.A = pt1.x - pt3.x;
  AC.B = pt1.y - pt3.y;
  AC.C = -AC.A * (pt1.x + pt3.x) / 2 - AC.B * (pt1.y + pt3.y) / 2;
  Point Center = intersect(AB , AC);
  return Circle{Center , R};
}

int32_t main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0) , cout.tie(0);
  vector<Point> pt(3);
  for (int i = 0; i < 3; i++)
    cin >> pt[i].x >> pt[i].y;
  Circle answer = getCircumcircle(pt[0] , pt[1] , pt[2]);
  cout << fixed << setprecision(5) << answer.center.x << " " << answer.center.y << " " << answer.R << '\n';
  return 0;
}
