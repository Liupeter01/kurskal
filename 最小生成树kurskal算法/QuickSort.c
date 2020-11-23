#include"QuickSort.h"

void SwapEdge(EDGE* edge_1, EDGE* edge_2)				  //swap a and b
{
		  EDGE temp = *edge_1;
		  *edge_1 = *edge_2;
		  *edge_2 = temp;
}

void QuickSort(int left, int right, EDGE* edge)	  //øÏÀŸ≈≈–Ú
{
		  int i = left;
		  int j = right;

		  if (i < j)
		  {
					while (i < j)
					{
							  while (edge[left].EdgeValue >= edge[i].EdgeValue && i <= right)
							  {
										++i;
							  }
							  while (edge[left].EdgeValue <= edge[j].EdgeValue && j > left)
							  {
										--j;
							 }
							  if (i < j)
							  {
										SwapEdge(&edge[i], &edge[j]);
							  }
					}
					SwapEdge(&edge[left], &edge[j]);
					QuickSort(0, j - 1, edge);
					QuickSort(j + 1, right, edge);
		  }
}