typedef long double ld;

// point p(x, y);
struct point {
	ld x, y;
	int id;
    point(ld x=0, ld y=0): x(x), y(y){}
 
    point operator+(const point &o) const{ return {x+o.x, y+o.y}; }
    point operator-(const point &o) const{ return {x-o.x, y-o.y}; }
    point operator*(ld t) const{ return {x*t, y*t}; }
    point operator/(ld t) const{ return {x/t, y/t}; }
    ld operator*(const point &o) const{ return x * o.x + y * o.y; }
    ld operator^(const point &o) const{ return x * o.y - y * o.x; }
};

// line l(point(x1,y1), point(x2,y2));
struct line{
    point a, b;
    line(){}
    line(point a, point b) : a(a), b(b){}
};

// ponto e em relacao a linha l
int cross(line l, point e){ 
    // -1=dir; 0=colinear; 1=esq;
    
    point a = l.b-l.a, b=e-l.a; 
    ld tmp = a ^ b;
    return tmp;
}

// se o ponto ta em cima da linha
bool isinseg(point p, line l){
    point a = l.a-p, b = l.b-p;
    return cross(l, p) == 0 and (a * b) <= 0;
}

// se o seg de r intersecta o seg de s
bool interseg(line r, line s) { 
	if (isinseg(r.a, s) or isinseg(r.b, s)
		or isinseg(s.a, r) or isinseg(s.b, r)) return true;

	return (cross(r, s.a)>0) != (cross(r, s.b)>0) and
			(cross(s, r.a)>0) != (cross(s, r.b)>0);
}

// area do poligono
ld area_polygon(vector<point> vp){
    ld area = 0;
	for(int i=1; i<vp.size()-1; i++){
	    area += (vp[0]-vp[i]) ^ (vp[0]-vp[i+1]);
	}
	return (abs(area)/2);
}
