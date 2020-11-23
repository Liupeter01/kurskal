#include"kurskal.h"

/*初始化Kurskal算法，包括数组以及并查集数组*/
void InitKurskal(MGraph G, EDGE** arr, int** UnionArray)
{
		  int SizeCounter = EdgeCalculate(G);					  //用于计算边的数量
		  Initquicksort(arr, SizeCounter);		  //初始化排序
		  UnionInitial(G, UnionArray);				//初始化并查集
}

/*
*Kurskal算法主体部分
*包含排序数组以及并查集
*/
void Kurskal(MGraph G, EDGE* arr, int* UnionArray)
{
		  InitKurskal(G, &arr, &UnionArray);				//初始化数组，并查集
		  int counter = 0;
		  for (int i = 0; i < G.vexnum; ++i)				//将Kurskal边集中的所有边添加到数组
		  {
					for (int j = i + 1; j < G.vexnum; ++j)
					{
							  if (G.Edge[i][j] != -1)
							  {
										arr[counter].length = G.Edge[i][j];
										arr[counter].v1 = G.Vex[i];
										arr[counter++].v2 = G.Vex[j];
							  }
					}
		  }
		  int arraysize = EdgeCalculate(G);
		  QuickSort(0, arraysize, arr);						//根据边的大小对于数组进行快速排序，所有的边以增序排列
		  int v1_pos = 0, v2_pos = 0;						//存放两个顶点的下标
		  for (int i = 0; i < arraysize; ++i)				//从头开始遍历边集数组
		  {
					/*
					*寻找每一个顶点在数组中的具体位置
					*对于第1个顶点而言，位置无需考虑，可能位于某一个集合中或者根结点
					*对于第2个顶点而言，位置需要考虑!!如果要将顶点2移动到顶点1的集合中，必须从根节点移动
					*/
					v1_pos = LocateVertex(G, arr[i].v1);			  //顶点1 v1_pos 任意
					if (UnionArray[LocateVertex(G, arr[i].v2)] != -1)	//当前的顶点2不在根节点
					{
							  v2_pos = FindItem(UnionArray, LocateVertex(G, arr[i].v2));	//获取根节点
					}
					else //当前的顶点2在根节点
					{
							  v2_pos = LocateVertex(G, arr[i].v2);//自己本身就是根节点
					}
					int res_v1 = FindItem(UnionArray, v1_pos);    //对于顶点1的根节点进行判断
					int res_v2 = FindItem(UnionArray, v2_pos);	    //对于顶点2的根节点进行判断
					if (res_v1 != res_v2)			  //如果两个根节点不同，则代表当前结构不是环
					{
							  Union(UnionArray, v1_pos, v2_pos);	  //可以继续进行并查集的操作
					}
		  }
}

/*Kurskal算法销毁*/
void DestroyKurskal(EDGE* arr, int* UnionArray)
{
		  free(arr);
		  free(UnionArray);
}