// Polygon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "polygon.h"
using namespace std;
int main()
{
	polygon p1;
	p1.add(*(new vertices(2,4)));
	p1.add(*(new vertices(3,1)));
	p1.add(*(new vertices(9,0)));
	p1.add(*(new vertices(3,5)));
	p1.add(*(new vertices(6,7)));
	p1.add(*(new vertices(0,6)));
	p1.add(*(new vertices(7,2)));
	p1.display();
	cout << endl << "Index :" << p1.search(1) << endl;
	p1.Delete(9);
	p1.display();
	system("pause");

};
