#include <iostream>
/*
Umar Khan
014477331
CECS 275 Lab 4
*/using namespace std;

class Point {
	int x, y;
public:

	Point(int xp, int yp) {
		x = xp;
		y = yp;
	}

	Point() {}

	void Print() {
		std::cout << '(' << x << ',' << y << ')';
	}
	//function prototype
	friend ostream & operator<<(ostream & out, const Point&);
	friend istream & operator<<(istream & in, const Point&);
	Point operator + (const Point &);
	Point operator - (const Point &);
	bool operator == (const Point &);
	bool operator != (const Point &);

	//add operator
	Point operator + (const Point &point) {
		Point add;
		add.x = this->x + point.x;
		add.y = this->y + point.y;
		return add;
	}
	//subtract operator
	Point operator - (const Point &point) {
		Point sub;
		sub.x = this->x - point.x;
		sub.y = this->y - point.y;
		return sub;
	}
	//equal operator
	bool operator == (const Point &point) {
		return (this->x == point.x && this->y == point.y);
	}

	//not equal operator
	bool operator != (const Point &point) {
		return (this->x != point.x && this->y != point.y);
	}

};

ostream & operator<<(ostream & out, const Point&point) {
	return out << "(" << point.x << "," << point.y << ")";
}
istream & operator<<(istream & in, const Point&point) {
	return in >> point.x >> point.y;
}