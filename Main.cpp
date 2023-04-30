#include "Cell.h"
#include "Net.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

float Cost1(vector<vector<Cell>> placement, vector<Net> paths);

int main()
{
	Cell c("test", 1001);
	Net n("1st", { "1" });
	string temp;
	string temp2;
	int temp3;
	int count = 0;
	int totalWeight = 0;
	int curWeight = 0;
	int numrows = 6;
	int rowWeight;
	vector<Cell> templst;
	vector<vector<Cell>> table;
	ifstream weights;
	ifstream nets;

	string NetTemp;
	string NetTemp2;
	string NetTemp3;
	string NetTemp4;
	vector <string> nodetemp;
	int index;
	vector<Net> templst2;
	int snt2;

	float curTemperature = 4000000;
	float finalTemperature = .1;

	weights.open("ibm01.are", ios::in);
	if (weights.fail()) {
		cerr << "This file does not exist." << endl;
	};

	while (getline(weights, temp))
	{
		//cout << temp << "\n";
		temp2 = temp.substr(0, temp.find(" "));
		temp3 = stoi(temp.substr(temp.find(" ")));// weight
		totalWeight += temp3;
		c.setId(temp2);
		c.setWeight(temp3);
		templst.push_back(c);
	}
	//cout << lst[0][12751].getId() << endl;

	rowWeight = totalWeight / numrows;

	while (!templst.empty())
	{
		table.push_back(vector<Cell>());
		while (curWeight <= rowWeight && !templst.empty())
		{
			table[count].push_back(templst.back());
			curWeight += templst.back().getWeight();
			templst.pop_back();
		}
		curWeight = 0;
		count++;
	}
	//initial placement created
	cout << "init placed" << endl;

	nets.open("ibm01.net", ios::in);
	if (nets.fail()) {
		cerr << "This file does not exist." << endl;
	};

	while (getline(nets, NetTemp))
	{

		NetTemp2 = NetTemp.substr(0, NetTemp.find(" "));
		snt2 = NetTemp2.size();
		index = snt2 + 1;
		//index = NetTemp.find(snt2+1 );
		NetTemp4 = NetTemp.substr(index, 1);
		if (NetTemp4 == "s") {
			if (!nodetemp.empty()) {
				n.setNodes(nodetemp);
				nodetemp.clear();
				templst2.push_back(n);
				n.setFirstNode(NetTemp2);
			}
			else {

				n.setFirstNode(NetTemp2);
			}
		}
		else {
			nodetemp.push_back(NetTemp2);

		}


	}
	n.setNodes(nodetemp);
	templst2.push_back(n);
	//for (int i = 0; i < templst2.size(); i++) {
	//	// Printing the element at
	//	// index 'i' of vector
	//	cout << templst2[i].getFirstNode() << endl;
	//	for (string j : templst2[i].getNodes()) {
	//		cout << j << endl;
	//	}
	//}
	
	//vector<Net> paths;
	//vector<string> ends;
	//ends.push_back("a2");
	//ends.push_back("a3");
	//Net a("a1", ends);
	//paths.push_back(a);
	cout << Cost1(table, templst2) << endl;
}

float Cost1(vector<vector<Cell>> placement, vector<Net> paths)
{
	float totalLen = 0; //return value, sum of all net lengths
	float curLen; //length of currently computed net
	string stNode; //starting Cell of current Net
	int stRow, stCol; //coords of starting Cell in placement table
	int curRow, curCol; //coords 0f current endpoint Cell in placement table
	int rowDif, colDif; // difference in coordinates between start and end
	for (Net i : paths)// for every Net object in vector
	{
		stNode = i.getFirstNode();
		for (int j = 0; j < placement.size(); j++) // finds coords of starting Cell
		{
			for (int k = 0; k < placement[j].size(); k++)
			{
				if (placement[j][k].getId() == stNode)
				{
					stRow = j;
					stCol = k;
				}
			}
		}

		for (string j : i.getNodes()) //for every Cell that starting Cell is connected to
		{
			for (int k = 0; k < placement.size(); k++) // find coords of endpoint Cell
			{
				for (int l = 0; l < placement[k].size(); l++)
				{
					if (placement[k][l].getId() == j)
					{
						curRow = k;
						curCol = l;
					}
				}
			}
			rowDif = abs(stRow - curRow) + 1; //calculate abs value of difference in coords
			colDif = abs(stCol - curCol) + 1; //+1 is used to ensure value is never 0
			curLen = rowDif * colDif; //calcualate a value to represent length of net
			totalLen += curLen; //add to summation of all net lengths
		}
	}
	return totalLen;
}
