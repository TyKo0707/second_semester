#include "materialPoint.h"

materialPoint::materialPoint(double t) {
	this->t = t;
}

double materialPointX::findX(){
	return x0 + a1 * sin(t);
}

double materialPointX::findY() {
	return 0;
}

double materialPointXY::findX() {
	return x0 + a1 * sin(t);
}

double materialPointXY::findY() {
	return y0 + a2 * cos(t);
}

double materialPointX::getDistance(materialPoint *mp) {
	float x2 = mp->getX();
	float y2 = mp->getY();
	return sqrt(pow((this->x - x2), 2) + pow((this->y - y2), 2));
}

double materialPointXY::getDistance(materialPoint *mp) {
	float x2 = mp->getX();
	float y2 = mp->getY();
	return sqrt(pow((this->x - x2), 2) + pow((this->y - y2), 2));
}