template<typename T>
struct Point{
  typedef long double llf;
  static constexpr llf EPS = 1e-8;
  T x, y;
  Point(T _=0, T __=0): x(_), y(__){}
  template<typename T2>
    Point(const Point<T2>& a): x(a.x), y(a.y){}
  inline llf theta() const {
    return atan2((llf)y, (llf)x);}
  inline llf dis() const {
    return hypot((llf)x, (llf)y);}
  inline llf dis(const Point& o) const {
    return hypot((llf)(x-o.x), (llf)(y-o.y));}
  Point operator-(const Point& o) const {
    return Point(x-o.x, y-o.y);}
  Point operator+(const Point& o) const {
    return Point(x+o.x, y+o.y);}
  Point operator*(const T& k) const {
    return Point(x*k, y*k);}
  Point operator/(const T& k) const {
    return Point(x/k, y/k);}
  Point operator-() const {return Point(-x, -y);}
  Point rot90() const {return Point(-y, x);}
  template<typename T2>
  bool in(const Circle<T2>& a) const {
    /* Add struct Circle at top */
    return a.o.dis(*this)+EPS <= a.r; }
  bool equal(const Point& o, true_type) const {
    return fabs(x-o.x) < EPS and fabs(y-o.y) < EPS; }
  bool equal(const Point& o, false_type) const {
    return tie(x, y) == tie(o.x, o.y); }
  bool operator==(const Point& o) const {
    return equal(o, is_floating_point<T>()); }
  bool operator!=(const Point& o) const {
    return !(*this == o); }
  bool operator<(const Point& o) const {
    return theta() < o.theta();
    // sort like what pairs did
    // if (is_floating_point<T>())
    //   return fabs(x-o.x)<EPS?y<o.y:x<o.x;
    // else return tie(x, y) < tie(o.x, o.y);
  }
  friend inline T cross(const Point&a,const Point&b){
    return a.x*b.y - b.x*a.y; }
  friend inline T dot(const Point& a, const Point &b){
    return a.x*b.x + a.y*b.y; }
  friend ostream&operator<<(ostream&ss,const Point&o){
    ss<<"("<<o.x<<", "<<o.y<<")"; return ss; }
};
