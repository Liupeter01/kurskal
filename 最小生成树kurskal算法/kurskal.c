#include"kurskal.h"

/*初始化Kurskal算法，包括数组以及并查集数组*/
void InitKurskal(MGraph G, EDGE** arr, int** UnionArray)
{
		  UnionInitial(G, UnionArray);				//初始化并查集
		  *arr = (EDGE*)malloc(sizeof(EDGE) * G.arcnum);
		  assert(*arr != NULL);
		  int counter = 0;
		  for (int i = 0; i < G.vexnum; ++i)				//将Kurskal边集中的所有边添加到数组
		  {
					for (int j = i + 1; j < G.vexnum; ++j)
					{
							  if (G.Edge[i][j]!=0 && G.Edge[i][j] != -1 && G.Edge[i][j] != INFINITYSIZE)
							  {
										(*arr)[counter].EdgeValue = G.Edge[i][j];		  //获取边值
										(*arr)[counter].v1 = G.Vex[i];					   //获取顶点1				
										(*arr)[counter++].v2 = G.Vex[j];				  //获取顶点2
							  }
					}
		  }
}

void DestroyKurskal(EDGE* arr, int* UnionArray)				//Kurskal算法销毁
{
		  free(arr);
		  free(UnionArray);
}

void Kurskal(MGraph G, VertexType V)			  //Kurskal算法主体部分
{
		  EDGE* arr = NULL;
		  int* UnionArray = NULL;
		  InitKurskal(G, &arr, &UnionArray);				//初始化数组，并查集

		  QuickSort(0, G.arcnum - 1, arr);		  //增序快速排序
		  int v1_pos = 0, v2_pos = 0;						//存放两个顶点的下标
		  for (int i = 0; i < G.arcnum; ++i)				//从头开始遍历边集数组
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

					int v1_root = FindItem(UnionArray, v1_pos);		  //寻找顶点1的根节点
					int v2_root = FindItem(UnionArray, v2_pos);		  //寻找顶点2的根节点
					if (v1_root != v2_root)//顶点1和顶点2不可以形成回路
					{
							  Union(UnionArray, v1_pos, v2_pos);	  //可以继续进行并查集的操作
					}
		  }
		  DestroyKurskal(arr, UnionArray);
}