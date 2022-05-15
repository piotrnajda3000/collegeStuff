#pragma once

#include <string>

using namespace std; 

class GraphPoint {
public:
	string algorithm, arrType, n;

	unsigned int dominantOps = 0;
	void incrementDominantOps(int n = 1);

	GraphPoint(); 
	GraphPoint(string algorithm, string arrType, unsigned int n); 

	string formatCSV(); 
};