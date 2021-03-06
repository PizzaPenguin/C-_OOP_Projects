﻿#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "QuadTree.h"
using namespace std;
/*
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BURAK KUZ 20647

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
int main()
{
	ifstream inputFile;
	int tempPoints; //to read inputFile inputs and than transfer it to vector
	vector<int> tempPos; //to store inputs in vector

	inputFile.open("rectdb.txt");
	while (inputFile >> tempPoints)
	{
		if (tempPoints == -1)
			break;
		tempPos.push_back(tempPoints);
	}

	inputFile.close();
	Rectangle mainPart(tempPos[0], tempPos[1], tempPos[2], tempPos[3]); //extent of root from first four inputs
	QuadTree theRoot(mainPart); //root is constructed

	for (int i = 4; i < tempPos.size() - 1; i += 4) //store remainin rectangles in rectangle typed vector
	{
		Rectangle temp(tempPos[i], tempPos[i + 1], tempPos[i + 2], tempPos[i + 3]);
		theRoot.insert(temp);
	}

	int numOfRec; //to store number of rectangles that has the point
	Point temp; //to store input coordinates
	cout << "Enter the point(s): \n";
	while (cin >> temp.x >> temp.y) //takes the input and stores it in temp point
	{
		if (temp.x != -1 && temp.y != -1)
		{
			numOfRec = 0;
			vector<Rectangle> tempRectangle; // temperary location to store the rectangles that has the query point
			cout << "For the point: " << temp.x << " " << temp.y << "\n";
			theRoot.find(temp, numOfRec, tempRectangle);
			cout << "Number of rectangles that store the point : " << numOfRec << "\n";
			if (numOfRec > 1)
			{
				cout << "Here are the rectangles that store the point \n";
			}
			for (int i = 0; i < tempRectangle.size(); i++) //print the rectangles that has query point - IF ANY
			{
				cout << tempRectangle[i].Top << " " << tempRectangle[i].Left << " "
					<< tempRectangle[i].Bottom << " " << tempRectangle[i].Right << "\n";
			}
		}
		else
		{
			cout << "Thank you for using the the program. \nTerminating...\n";

			return 0;
		}
		cout << "\nEnter the point(s): \n";
	}

	return 0;
}

