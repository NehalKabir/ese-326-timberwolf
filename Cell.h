#pragma once
#include <string>
using namespace std;

class Cell
{
private:
	string id;
	int weight;
	int r, c; //row and column
public:
	Cell();
	Cell(string i, int w, int x, int y);
	string getId();
	void setId(string s);
	int getWeight();
	void setWeight(int w);
	int getR();
	int getC();
	void setR(int x);
	void setC(int y);
};
