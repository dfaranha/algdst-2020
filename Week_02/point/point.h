#ifndef _POINT_H_
#define _POINT_H_

class Point {
	private:
		float x, y;

	public:
		Point();
		~Point();
		float distance(Point a);
};

#endif
