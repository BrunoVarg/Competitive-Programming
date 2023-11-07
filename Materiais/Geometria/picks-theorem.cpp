#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"

typedef long double ld;

struct point {
    int x, y;
    point(int x=0, int y=0): x(x), y(y){}
 
    point operator+(const point &o) const{ return {x+o.x, y+o.y}; }
    point operator-(const point &o) const{ return {x-o.x, y-o.y}; }
    point operator*(int t) const{ return {x*t, y*t}; }
    point operator/(int t) const{ return {x/t, y/t}; }
    int operator*(const point &o) const{ return x * o.x + y * o.y; }
    int operator^(const point &o) const{ return x * o.y - y * o.x; }
};

ld area_polygon(vector<point> vp){
    ld area = 0;
    for(int i=1; i<vp.size()-1; i++){
        area += (vp[0]-vp[i]) ^ (vp[0]-vp[i+1]);
    }
    return (abs(area)/2);
}

int boundary(vector<point> &v){
    int pts = v.size();
    for(int i=0; i<v.size(); i++){
        int dx = v[i].x - v[(i+1) % v.size()].x;
        int dy = v[i].y - v[(i+1) % v.size()].y;
        pts += abs(__gcd(dx, dy)) - 1;
    }
    return pts;
}

int32_t main(){ sws;
    // area = points + bound/2 -1
    // points = area - bound/2 + 1
    int n; cin>>n;
    vector<point> v;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        v.push_back(point(x, y));
    }
    int area = area_polygon(v);
    int bound = boundary(v);

    int points = area - bound/2 + 1;
    cout<<points<<endl;
}

