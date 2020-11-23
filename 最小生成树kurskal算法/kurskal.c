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
		  QuickSort(0, G.arcnum - 1, *arr);		  //增序快速排序
}

void DestroyKurskal(EDGE* arr, int* UnionArray)				//Kurskal算法销毁
{
		  free(arr);
		  free(UnionArray);
}

void Kurskal(MGraph G)			  //Kurskal算法主体部分
{
		  EDGE* arr = NULL;
		  int* UnionArray = NULL;
		  InitKurskal(G, &arr, &UnionArray);				//初始化数组，并查集
		  int v1_pos = 0, v2_pos = 0;						//存放两个顶点的下标
		  for (int i = 0; i < G.arcnum; ++i)				//从头开始遍历边集数组
		  {
					v1_pos = LocateVertex(G, arr[i].v1);
					//在该代码中，默认将顶点2作为后序的结点。若需要移动则需要查找顶点2的根节点
					if (UnionArray[LocateVertex(G, arr[i].v2)] != -1)	//当前的顶点2不是根节点
					{
							  v2_pos = FindItem(UnionArray, LocateVertex(G, arr[i].v2));	//获取根节点
					}
					else //当前的顶点2在根节点
					{
							  v2_pos = LocateVertex(G, arr[i].v2);//自己本身就是根节点
					}

					int v1_root = FindItem(UnionArray, v1_pos);		  //寻找顶点1的根节点
					int v2_root = FindItem(UnionArray, v2_pos);		  //寻找顶点2的根节点
					if (v1_root != v2_root)//顶点1和顶点2不可以位于同一个连通子图之中
					{
							  Union(UnionArray, v1_pos, v2_pos);	  //可以继续进行并查集的操作
					}
		  }
		  DestroyKurskal(arr, UnionArray);
}