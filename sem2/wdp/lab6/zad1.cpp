#include <iostream>

using namespace std; 

double pi = 2 * asin(1.0);

double circleArea(double radius) {
	return pi * radius * radius; 
};

double sphereVolume(double radius) {
	return 4 / 3 * pi * radius * radius * radius;
}; 

double rectangleArea(double length, double width) {
	return length * width;
}

double rectangularPrismVolume(double height, double length, double width) {
	return height * length * width;
};

double triangleArea(double height, double base) {
	return 1 / 2 * height * base; 
};
double triangularPrismVolume(double height, double base, double length) {
	return 1 / 2 * height * base * length; 
};

double cubeArea(double edge) {
	return 6 * edge * edge;
};
double cubeVolume(double edge) {
	return edge * edge * edge;
};

double cylinderArea(double height, double radius) {
	return 2 * pi * radius * (radius + height); 
};

double cylinderVolume(double height, double radius) {
	return pi * height * radius * radius;
}; 