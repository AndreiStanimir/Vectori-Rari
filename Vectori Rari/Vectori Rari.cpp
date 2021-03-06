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
	node* next;
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
/*
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
*/
int ReadValuesAndSort(Vector &v, string fileName)
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
			if (head->next == NULL) {
				head->next = CreateNode(ind, value);
				break;
			}
			else if (head->ind < ind &&
				ind < head->next->ind)
			{
				Vector tmp = head->next;
				head->next = CreateNode(ind, value);
				head->next->next = tmp;
				break;
			}
			head = head->next;
		}
	}
	v = v->next;
	return n;
}
void WriteList(Vector v)
{
	Vector head = v;
	while (head)
	{
		cout << head->ind << " " << head->value << endl;
		head = head->next;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n";
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

void AddNodeToResult(Vector &result, Vector &v1);

Vector Sum(Vector v1, Vector v2)
{
	Vector result = CreateNode(-1, -1);
	Vector headResult = result;
	while (v1&&v2)
	{
		if (v1->ind < v2->ind)
			AddNodeToResult(headResult, v1);
		else if (v1->ind > v2->ind)
			AddNodeToResult(headResult, v2);
		else
		{
			headResult->next = CreateNode(v1->ind, v1->value + v2->value);

			headResult = headResult->next;
			v1 = v1->next;
			v2 = v2->next;
		}
	}
	while (v1)
	{
		AddNodeToResult(headResult, v1);
	}
	while (v2)
	{
		AddNodeToResult(headResult, v2);
	}
	return result->next;
}
int ProdusScalar(Vector v1, Vector v2)
{
	int result = 0;
	while (v1&&v2)
	{
		if(v1->ind==v2->ind)
		{
			result += v1->value*v2->value;
		}
		if (v1->ind <= v2->ind)
			v1 = v1->next;
		if (v1 == NULL)
			break;
		if (v1->ind >= v2->ind)
			v2 = v2->next;
	}

	return result;
}
void AddNodeToResult(Vector &result, Vector &v1)
{
	result->next = CreateNode(v1->ind, v1->value);
	v1 = v1->next;
	result = result->next;
}

int main()
{
	int m, n;
	Vector v1 = NULL;
	Vector v2 = NULL;

	m = ReadValuesAndSort(v1, "a.txt");
	n = ReadValuesAndSort(v2, "b.txt");

	WriteList(v1);
	WriteList(v2);

	Vector sum = Sum(v1, v2);
	WriteList(sum);

	cout << ProdusScalar(v1, v2);
	return 0;
}


