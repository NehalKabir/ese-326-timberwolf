#pragma once
#include <string>
#include <vector>
#include "Cell.h"

using namespace std;

class Net
{
private:
	Cell firstNode;
	vector<Cell> nodes;
public:
	Net(Cell f, vector<Cell> n);
	Cell getFirstNode();
	void setFirstNode(Cell f);
	vector<Cell> getNodes();
	void setNodes(vector<Cell> n);

};
