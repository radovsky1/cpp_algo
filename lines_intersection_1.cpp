#include <iostream>

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

Point intersect(const Line &n , const Line &m) {
  Point intersection_point;
  double zn = det(n.a , n.b , m.a , m.b);
  intersection_point.x = -det(n.c , n.b , m.c , m.b) / zn;
  intersection_point.y = -det(n.a , n.c , m.a , m.c) / zn;
  return intersection_point;
}

int32_t main() {
  ios_base :: sync_with_stdio(0);
  cin.tie(0) , cout.tie(0);
  Line n , m;
  cin >> n.a >> n.b >> n.c;
  cin >> m.a >> m.b >> m.c;
  Point intersection = intersect(n , m);
  cout << fixed << intersection.x << " " << intersection.y << '\n';
  return 0;
}
