// Vectori Rari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h""
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
	int ind;
	int value;
	node* next
};

typedef node* Vector;

Vector CreateNode(int ind, int value)
{
	Vector n = new node;
	n->ind = ind;
	n->value = value;
	n->next = NULL;
	return n;
}

int ReadValues(Vector v, string fileName)
{
	int n, ind, value;
	ifstream fin(fileName);

	fin >> n;
	fin >> ind >> value;
	v = CreateNode(ind, value);

	Vector head = v;

	for (int i = 1; i < n; i++)
	{
		fin >> ind >> value;
		head->next = CreateNode(ind, value);

		head = head->next;
	}
}

int ReadValuesAndSort(Vector v, string fileName)
{
	int n, ind, value;
	ifstream fin(fileName);

	fin >> n;
	v = CreateNode(-1, -1);
	//fin >> ind >> value;
	//v = CreateNode(ind, value);

	Vector head = v;

	for (int i = 0; i < n; i++)
	{
		head = v;
		fin >> ind >> value;
		//head->next = CreateNode(ind, value);
		while (head)
		{
			if (head->next == NULL)
				;
			else if (head->ind < ind &&
				ind < head->next->ind)
			{
				Vector tmp = head->next;
				head->next = CreateNode(ind, value);
				head->next->next = tmp;
			}
		}
		head = head->next;
	}
	v = v->next;
}
/*
void SortList(Vector v)
{
	Vector head = v->next;
	node Min;
	Min.ind = head->ind;
	Min.value = head->value;

	Vector headSort =

		while (head)
		{

			if (Min.ind > head->ind)
				Min.ind = head->ind,
				Min.value = head->value;

			head = head->next;
		}
}
*/
int main()
{
	int m, n;
	Vector v1;
	Vector v2;

	m = ReadValues(v1, "a.txt");
	n = ReadValues(v2, "b.txt");

	return 0;
}


