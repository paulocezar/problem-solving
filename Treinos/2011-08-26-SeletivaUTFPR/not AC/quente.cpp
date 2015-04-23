#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const double EPS = 1e-9, pi = acos(-1.0), INF = 1e50;

struct pt{
	double x, y;
	
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length(){
		return sqrt(x*x + y*y);
	}
	bool normalize(){
		double l = length();
		if(fabs(l) < EPS)
			return false;
			
		x /= l, y /= l;
		return true;
	}
	pt operator + (pt p){
		return pt(x + p.x, y + p.y); 
	}
	bool operator == (pt p){
		return (fabs(x - p.x) < EPS && fabs(x - p.y) < EPS);
	}
	pt operator - (pt p){
		return pt(x - p.x, y - p.y);
	}
	pt operator * (double k){
		return pt(x*k, y*k);
	}
	pt operator / (double k){
		return pt(x/k, y/k);
	}
	
	bool operator < (const pt& p) const{
		if(fabs(x - p.x) >= EPS) return x < p.x;
		return y < p.y;
	}
};

double dist(pt a, pt b){
	return (a-b).length();
}

double dot(pt a, pt b){
	return a.x*b.x + a.y*b.y;
}

double cross(pt a, pt b){
	return a.x*b.y - a.y*b.x;
}

bool inbox(pt a, pt b, pt c){
	return (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x))
		&& (c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y));
}

double signed_area(pt a, pt b, pt c){
	return cross(b-c, a-c)/2.0;
}

bool intersect(pt a, pt b, pt c, pt d, pt& inter){
	double det = cross(b-a, d-c);
	if(fabs(det) < EPS){
		return false;
	}
	double ua = (cross(d-c, a-c))/det;
	inter = a + ( (b-a)*ua );
	return true;
}

struct cond{
	pt a, b; //vetor de a ate b
	bool dir; //true esquerda, false direita
	
	cond(pt a = pt(), pt b = pt(), bool dir = false) : a(a), b(b), dir(dir){}
};

bool better(pt a, pt b, pt c){
	double sg = cross(b-c, a-c);
	
	if(fabs(sg) < EPS){
		if(dist(c, a) < dist(c, b)) return true;
		return false;
	}
	if(sg < 0) return true;
	return false;
}


void vex(vector<pt> vin, vector<pt>& vout){
	vout.clear();
	int n = vin.size();
	sort(vin.begin(), vin.end());
	
	pt stk[500];
	int pstk, i;
	
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	
	for(int i = 2; i < n; i++){
		if(dist(vin[i], vin[i-1]) < EPS) continue;
		
		while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
			pstk--;
		stk[pstk] = vin[i];
		pstk++;
	}
	
	for(i = 0; i < pstk; i++) vout.push_back(stk[i]);
	
	for(i = 0; i < n; i++){
		vin[i] = vin[i]*(-1.0);
	}
	
	sort(vin.begin(), vin.end());
	
	stk[0] = vin[0];
	stk[1] = vin[1];
	pstk = 2;
	
	for(int i = 2; i < n; i++){
		if(dist(vin[i], vin[i-1]) < EPS) continue;
		
		while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
			pstk--;
		stk[pstk] = vin[i];
		pstk++;
	}
	
	for(i = 1; i < pstk; i++){
		vout.push_back(stk[i]*(-1.0));
	}
}

double trap(pt a, pt b){
	return 0.5*(b.x - a.x)*(b.y + a.y);
}

double area(vector<pt> &vin){
	int n = vin.size();
	double ret = 0.0;
	
	for(int i = 0; i < n; i++){
		ret += trap(vin[i], vin[(i+1)%n]);
	}
	return fabs(ret);
}

int main(){
	double x, y;
	string status;
	
	pt ant(0, 0), act, dir;
	vector<cond> restr;
	vector<pt> pts, atend, hull;
	double last = 100.0;
	
	pt p1(0.0, 0.0), p2(0.0, 10.0), p3(10.0, 10.0), p4(10.0, 0.0);
	 
	pts.push_back(p1); restr.push_back(cond(p1, p2, false));
	pts.push_back(p2); restr.push_back(cond(p2, p3, false));
	pts.push_back(p3); restr.push_back(cond(p3, p4, false));
	pts.push_back(p4); restr.push_back(cond(p4, p1, false));
	
	string line;
	bool side;
	cond med;
	while(getline(cin, line)){
		stringstream ss(line);
		ss >> x >> y >> status;
		act = pt(x, y);
		
	//	cout << x << " " << y << " " << status << endl;
		if(status == "Quente"){
			side = false;
		} else if(status == "Frio"){
			side = true;
		} else{
			cout << fixed << setprecision(2) << last<< "\n"; continue;
		}
		
		dir = (act-ant);
		dir.normalize();
		dir = pt(dir.y, -dir.x);
		
		pt mid = (act+ant)/2.0;
		
		med = cond(mid, mid+dir, side);
		
	//	cout << "MED: " << med.a.x << " " << med.a.y << " " << med.b.x << " " << med.b.y << endl;
		
		for(int i = 0; i < restr.size(); i++){
			pt inter;
			if(intersect(med.a, med.b, restr[i].a, restr[i].b, inter)){
			//	cout << restr[i].a.x << ',' << restr[i].a.y << " [[ " << restr[i].b.x << ',' <<
			//		restr[i].b.y << endl;
			//	cout << inter.x << " " << inter.y << endl;
				pts.push_back(inter);
			}
		}
		restr.push_back(med);
		
		for(int i = 0; i < pts.size(); i++){
			bool flag = true;
			
			//cout << "Ponto: (" << pts[i].x << "," << pts[i].y << ")" << endl;
			
			for(int j = 0; j < restr.size(); j++){
				if(restr[j].dir){
					if(signed_area(restr[j].a, restr[j].b, pts[i]) > 0.0){
					//	cout << "nao deu 1 (" << restr[j].a.x << ',' 
					//		<< restr[j].a.y << ") (" << restr[j].b.x << ',' 
					//			<< restr[j].b.y << ")" << endl;
						flag = false;
						break;
					}
				}
				else{
					if(signed_area(restr[j].a, restr[j].b, pts[i]) < 0.0){
						flag = false;
					//	cout << signed_area(restr[j].a, restr[j].b, pts[i]) << endl;
						//cout << "nao deu 2 (" << restr[j].a.x << ',' 
						//	<< restr[j].a.y << ") (" << restr[j].b.x << ',' 
						//		<< restr[j].b.y << ")" << endl;
						break;
					}
				}
			}
			if(flag){
				atend.push_back(pts[i]);
			}
		}
		
		if(atend.size() < 3){
			cout << "0.00\n";
			continue;
		}
		//cout << atend.size() << endl;
		
		vex(atend, hull);
		cout << fixed << setprecision(2) << (last = area(hull)) << "\n";
		
		pts = atend;
		atend.clear();
		ant = act;
	}
	
	while(getline(cin, line)){
		cout << "0.00\n";
	}
}