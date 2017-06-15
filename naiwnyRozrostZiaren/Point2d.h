#pragma once
public ref class Point2d {
public:
	unsigned int color;
	double dislocationDensity;
	bool isRecrystalized;
	Point2d() {
		color = 0;
		isRecrystalized = false;
		dislocationDensity = 0;
	}
	Point2d(unsigned int color) : color(color) {
		isRecrystalized = false;
		dislocationDensity = 0;
	}
	void Clear();
	void ClearDislocations();
};
void Point2d::Clear() {
	this->color = 0;
	this->dislocationDensity = 0;
	this->isRecrystalized = false;
}
void Point2d::ClearDislocations() {
	this->dislocationDensity = 0;
	this->isRecrystalized = false;
}
public struct PointSimple {
	bool didRecrystallized;
	int x, y;
	PointSimple(int y, int x) : y(y), x(x) { didRecrystallized = true; }
	PointSimple(bool condition) : didRecrystallized(condition) { x = -5; y = -5; }
};
