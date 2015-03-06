#include <cmath>

struct point {
	double x, y;
};

class Vector
{
	double angle;
	double mag;
public:
	Vector() { angle = 0; mag = 0; }
	Vector(double an, double ma) { angle = an; mag = ma; }
	double x() { return mag*cos(angle); }
	double y() { return mag*sin(angle); }
	double getAngle() { return angle; }
	double getMag() { return mag; }
	
	Vector operator+(Vector &comp) {
		double magbuffer = sqrt(pow(x() + comp.x(), 2) + pow(y() + comp.y(), 2));
		angle = atan((y() + comp.y()) / (x() + comp.x()));
		mag = magbuffer;
		return *this;
	}
};

class PhysObj
{
	double mass;
	Vector disp;
	double x;
	double y;
public:
	PhysObj(double m, const Vector &d, double a, double b) { mass = m; disp = d; }
	PhysObj(double m, double angle, double mag, double a, double b) {
		mass = m;
		disp = Vector(angle, mag);
		x = a;
		y = b;
	}
	virtual void update(double timestep) {
		x += disp.x()*timestep;
		y += disp.y()*timestep;
	}
	double x() { return x; }
	double y() { return y; }
	void VectAdd(Vector &d) {
		disp = disp + d;
	}
};