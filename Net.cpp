#include "Net.h"

using namespace std;

Net::Net(Cell f, vector<Cell> n)
{
	firstNode = f;
	nodes = n;
}

Cell Net::getFirstNode()
{
	return firstNode;
}

void Net::setFirstNode(Cell f)
{
	firstNode = f;
}

vector<Cell> Net::getNodes()
{
	return nodes;
}

void Net::setNodes(vector<Cell> n)
{
	nodes = n;
}
