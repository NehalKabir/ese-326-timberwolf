#include "Cell.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	Cell c("test", 1001);
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
		temp3= stoi(temp.substr(temp.find(" ")));// weight
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

	while (curTemperature > finalTemperature)
	{

	}
}