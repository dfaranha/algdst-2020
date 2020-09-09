#ifndef _POINT_H_
#define _POINT_H_

class Point {
	private:
		float x, y;

	public:
		Point();
		~Point();
		const float X() { return x; }
		const float Y() { return y; }
		static float distance(Point a, Point b);
		friend int operator==(Point a, Point b);
		friend ostream& operator<<(ostream& t, Point p);
};

#endif
