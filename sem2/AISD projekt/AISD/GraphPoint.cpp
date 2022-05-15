#include "GraphPoint.h"

GraphPoint::GraphPoint() {};

GraphPoint::GraphPoint(string algorithm, string arrType, unsigned int n) {
	this->algorithm = algorithm;
	this->arrType = arrType;
	this->n = to_string(n);
}

string GraphPoint::formatCSV() {
	return algorithm + "," + arrType + "," + n + "," + to_string(dominantOps) + "\n";
}

void GraphPoint::incrementDominantOps(int n) {
	this->dominantOps += n;
}
