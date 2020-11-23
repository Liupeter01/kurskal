#pragma once
#include"MGraph.h"

typedef struct EDGE
{
		  VertexType v1;				//顶点1
		  VertexType v2;				//顶点2
		  unsigned int EdgeValue;				//边的权
}EDGE;

void SwapEdge(EDGE* edge_1, EDGE* edge_2);				  //交换各边
void QuickSort(int left, int right, EDGE* edge);	  //快速排序