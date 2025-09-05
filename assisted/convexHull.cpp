#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <array>

using namespace std; 

struct Point {
    double x, y;
    bool operator<(const Point& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
    bool operator==(const Point& o) const {
        return x == o.x && y == o.y;
    }
};

static inline double cross(const Point& a, const Point& b, const Point& c) {
    // cross of (b - a) x (c - a)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

static inline double dot(const Point& a, const Point& b, const Point& c) {
    // dot of (b - a) . (c - a)
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

static inline double dist2(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

// Convex hull: Andrew's monotone chain. Returns CCW hull without repeating first point.
// Set keep_collinear=true if you want collinear edge points kept on the hull.
vector<Point> convex_hull(vector<Point> pts, bool keep_collinear=false) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if (pts.size() <= 2) return pts;

    vector<Point> lower, upper;
    for (const auto& p : pts) {
        while (lower.size() >= 2) {
            double cr = cross(lower[lower.size()-2], lower.back(), p);
            if (cr < 0 || (!keep_collinear && cr == 0)) lower.pop_back();
            else break;
        }
        lower.push_back(p);
    }
    for (int i = (int)pts.size()-1; i >= 0; --i) {
        const auto& p = pts[i];
        while (upper.size() >= 2) {
            double cr = cross(upper[upper.size()-2], upper.back(), p);
            if (cr < 0 || (!keep_collinear && cr == 0)) upper.pop_back();
            else break;
        }
        upper.push_back(p);
    }
    // concatenate, removing duplicate endpoints
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

// Diameter (farthest pair) via rotating calipers. Returns squared distance.
double convex_diameter2(const vector<Point>& hull) {
    int n = (int)hull.size();
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return dist2(hull[0], hull[1]);

    auto area2 = [&](int i, int j, int k) {
        // 2*triangle area = cross(hull[i], hull[j], hull[k])
        return fabs(cross(hull[i], hull[j], hull[k]));
    };

    double best = 0.0;
    int j = 1;
    for (int i = 0; i < n; ++i) {
        int ni = (i + 1) % n;
        // advance j while area increases
        while (area2(i, ni, (j + 1) % n) >= area2(i, ni, j)) {
            j = (j + 1) % n;
        }
        // update farthest pairs for current i
        best = max(best, dist2(hull[i], hull[j]));
        best = max(best, dist2(hull[ni], hull[j]));
    }
    return best;
}

// Minimum-area bounding rectangle (simple approach).
// Returns area, angle (radians), and the 4 corners of the rectangle.
// Complexity: O(h^2) where h is hull size.
struct MinRect {
    double area;
    double angle;         // rotation from x-axis for the rectangle's X-side
    array<Point,4> corners; // in order (e.g., min-min, max-min, max-max, min-max along axes)
};

MinRect minimum_area_rectangle(const vector<Point>& hull) {
    MinRect res;
    res.area = numeric_limits<double>::infinity();
    res.angle = 0;
    if (hull.empty()) return res;
    if (hull.size() == 1) {
        res.area = 0;
        res.corners = {hull[0], hull[0], hull[0], hull[0]};
        return res;
    }

    // Helper: project point p onto unit direction u = (ux, uy)
    auto project = [](const Point& p, double ux, double uy) -> double {
        return p.x*ux + p.y*uy;
    };

    int n = (int)hull.size();
    for (int i = 0; i < n; ++i) {
        int ni = (i + 1) % n;
        // edge direction
        double ex = hull[ni].x - hull[i].x;
        double ey = hull[ni].y - hull[i].y;
        double len = hypot(ex, ey);
        if (len == 0) continue;
        double ux = ex / len;      // unit direction along edge
        double uy = ey / len;
        double vx = -uy;           // unit normal (perpendicular)
        double vy =  ux;

        double minU = numeric_limits<double>::infinity();
        double maxU = -numeric_limits<double>::infinity();
        double minV = numeric_limits<double>::infinity();
        double maxV = -numeric_limits<double>::infinity();

        // Project all hull points onto u and v
        for (const auto& p : hull) {
            double pu = project(p, ux, uy);
            double pv = project(p, vx, vy);
            minU = min(minU, pu);
            maxU = max(maxU, pu);
            minV = min(minV, pv);
            maxV = max(maxV, pv);
        }

        double width  = maxU - minU;  // along u
        double height = maxV - minV;  // along v
        double area = width * height;

        if (area < res.area) {
            res.area = area;
            res.angle = atan2(uy, ux);
            // corners in world coords: minU/minV etc
            // point = u*(U) + v*(V)
            auto toWorld = [&](double U, double V) -> Point {
                return Point{ U*ux + V*vx, U*uy + V*vy };
            };
            Point c0 = toWorld(minU, minV);
            Point c1 = toWorld(maxU, minV);
            Point c2 = toWorld(maxU, maxV);
            Point c3 = toWorld(minU, maxV);
            res.corners = {c0, c1, c2, c3};
        }
    }
    return res;
}

// Example driver
int main() {
    // Example input: scattered points
    vector<Point> pts = {
        {0,0}, {1,0}, {2,0}, {2,1}, {1.5, 2}, {0.2,1.5}, { -0.2, 0.7}, {1.0, 1.2}
    };

    // 1) Convex hull
    auto hull = convex_hull(pts);
    cout << "Hull (" << hull.size() << " points):\n";
    for (auto& p : hull) cout << fixed << setprecision(6) << p.x << " " << p.y << "\n";

    // 2) Diameter (farthest pair distance)
    double d2 = convex_diameter2(hull);
    cout << "Diameter length = " << setprecision(6) << sqrt(d2) << "\n";

    // 3) Minimum-area rectangle
    auto mr = minimum_area_rectangle(hull);
    cout << "Min rectangle area = " << setprecision(6) << mr.area << "\n";
    cout << "Angle (radians) = " << mr.angle << "\n";
    cout << "Corners:\n";
    for (auto& c : mr.corners) cout << c.x << " " << c.y << "\n";

    return 0;
}
