#pragma once
#include <string>
#include <vector>

using namespace std;

class Net
{
private:
	string firstNode;
	vector<string> nodes;
public:
	Net(string f, vector<string> n);
	string getFirstNode();
	void setFirstNode(string f);
	vector<string> getNodes();
	void setNodes(vector<string> n);

};

Net::Net(string f, vector<string> n)
{
	firstNode = f;
	nodes = n;
}

string Net::getFirstNode()
{
	return firstNode;
}

void Net::setFirstNode(string f)
{
	firstNode = f;
}

vector<string> Net::getNodes()
{
	return nodes;
}

void Net::setNodes(vector<string> n)
{
	nodes = n;
}
