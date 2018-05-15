#include<iostream>
#include<string>
#include "vertices.h"
using namespace std;
int i;
class polygon
{
public:
	//null constructor
	polygon()
	{
		this->Total = 0;
		this->index = 0;
		this->size = 5;
		list = new vertices[5];
	};
	//parameterized constructor
	polygon(float total, vertices *list)
	{
		this->Total = total;
		this->list = list;
	};
	//copy constructor
	polygon(polygon & clone)
	{
		this->Total = clone.Total;
		this->index = clone.index;
		this->list = clone.list;
		this->size = clone.size;
	};
	//setters
	void setTotalcost(float Total)
	{
		this->Total = Total;
	};
	void setindex(int index)
	{
		this->index = index;
	};
	void setlist(vertices *list)
	{
		this->list = list;
	};
	//getters
	float gettotal()
	{
		return this->Total;
	};
	int getindex()
	{
		return this->index;
	};
	//add function
	void add(vertices &d)
	{
		if (index < size)
		{
			list[index] = d;
			index++;
		}
		else
		{
			incsize(d);
		}
		this->Total += d.getx();
	};
	//display
	void display()
	{

		cout << "VERTICES" << endl;
		for (i = 0; i<index; i++)
		{
			cout << this->list[i] << endl;
		}
		cout << "Total Points= " << this->Total << endl;
	};
	//search function
	int search(int y)
	{
		vertices p1;
		int temp = 0;
		for (i = 1; i <= index; i++)
		{
			p1 = this->list[i - 1];
			if (y == p1.gety())
			{
				temp = i;
				break;
			}
		}
		return temp;
	};
	//delete function
	void Delete(int x)
	{
		int temp = search(x);
		if (temp > 0)
		{
			for (i = temp - 1; i < index - 1; i++)
			{
				this->list[i] = this->list[i + 1];
			}
			index--;
		}
		else
		{
			cout << "Not found" << endl;
		}
	};
	//increase function
protected:
	void incsize(vertices &d)
	{
		size = size * 2;
		vertices *newlist = new vertices[size];
		for (i = 0; i < (size / 2); i++)
		{
			newlist[i] = list[i];
		}
		delete[] list;
		list = newlist;
		list[index] = d;
		index++;
	};

private:
	float Total;
	vertices *list;
	int size;
	int index;
}; 
