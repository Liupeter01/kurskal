#include"UnDirectedEdge.h"

BOOL  IsUnDirectEdgeExist(MGraph G, VertexType x, VertexType y)		   //判断在图G中是否存在无向边(x,y)
{
          int x_pos = LocateVertex(G, x);
          int y_pos = LocateVertex(G, y);
          return  ((x_pos != -1 && y_pos != -1 && G.Edge[x_pos][y_pos] != 0 && G.Edge[x_pos][y_pos] != INFINITYSIZE &&
                    G.Edge[y_pos][x_pos] != 0 && G.Edge[y_pos][x_pos] != INFINITYSIZE) ? TRUE : FALSE);
}

void DisplayUnDirectNeighbors(MGraph G, VertexType x) //输出在有向图G与结点x相邻边(x,?)
{
          int x_pos = LocateVertex(G, x);
          if (x_pos != -1)              //顶点必须存在
          {
                    for (int i = 0; i < G.MaxVertexNum; ++i)
                    {
                              if (G.Edge[x_pos][i] != 0 && G.Edge[x_pos][i] != INFINITYSIZE)
                              {
                                        printf("无向边(%c,%c)\n", x, G.Vex[i]);
                              }
                    }
          }
}

BOOL	 InsertUnDirectEdge(MGraph* G, VertexType x, VertexType y)	  //在图G中添加无向无权边(x,y)  ，权值默认为1
{
          return InsertEdge(G, x, y, 1, UNDIRECTEDGRAPH);
}

BOOL	 InsertUnDirectEdgeValue(MGraph* G, VertexType x, VertexType y, int Edge_Value)	//在图G中添加无向含权边(x,y)，支持修改权值
{
          return InsertEdge(G, x, y, Edge_Value, UNDIRECTEDGRAPH);
}

BOOL	RemoveUnDirectEdge(MGraph* G, VertexType x, VertexType y)  //在有向图G删除无向边(x,y)
{
          return RemoveEdge(G, x, y, ((G->EdgeValue == TRUE) ? INFINITYSIZE : 0), UNDIRECTEDGRAPH);
}