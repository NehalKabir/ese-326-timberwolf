#pragma once
#include <string>
using namespace std;

class Cell
{
private:
	string id;
	int weight;
public:
	Cell(string i, int w);
	string getId();
	void setId(string s);
	int getWeight();
	void setWeight(int w);
};