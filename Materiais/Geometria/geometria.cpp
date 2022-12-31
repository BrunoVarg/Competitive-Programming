const long double EPS = 1e-9;
typedef long double ld;

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

struct line{
    point a, b;
    line(){}
    line(point a, point b) : a(a), b(b){}
};

// ponto e em relacao a linha l
// counterclockwise
int ccw(line l, point e){ 
    // -1=dir; 0=colinear; 1=esq;
    point a = l.b-l.a, b=e-l.a; 
    ld tmp = a ^ b;
    return (tmp > EPS) - (tmp < -EPS);
}

// se o ponto ta em cima da linha
bool isinseg(point p, line l){
    point a = l.a-p, b = l.b-p;
    return ccw(l, p) == 0 and (a * b) <= 0;
}

// se o seg de r intersecta o seg de s
bool interseg(line r, line s) { 
	if (isinseg(r.a, s) or isinseg(r.b, s)
		or isinseg(s.a, r) or isinseg(s.b, r)) return true;

	return (ccw(r, s.a)>0) != (ccw(r, s.b)>0) and
			(ccw(s, r.a)>0) != (ccw(s, r.b)>0);
}

// area do poligono
ld area_polygon(vector<point> vp){
    ld area = 0;
	for(int i=1; i<vp.size()-1; i++){
	    area += (vp[0]-vp[i]) ^ (vp[0]-vp[i+1]);
	}
	return (abs(area)/2);
}

// localizacao do ponto no poligono
int point_polygon(vector<point> vp, point p){
    // -1=outside; 0=boundary; 1=inside;
    int sz = vp.size();
    int inter = 0;
    for(int i=0; i<sz; i++){
        int j = (i+1)%sz;
        line l(vp[i], vp[j]);
        if(isinseg(p, l)) return 0;
        
        if(vp[i].x <= p.x and p.x < vp[j].x and ccw(l, p) == 1) inter++;
        else if(vp[j].x <= p.x and p.x < vp[i].x and ccw(l, p) == -1) inter++;
    }

    if(inter%2==0) return -1;
    else return 1;
}
