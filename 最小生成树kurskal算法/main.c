#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEF" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          VertexType arr1[] = "ACFDE";
          VertexType arr2[] = "BEAEF";

          for (int i = 0; i < 5; ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1+i), *(arr2 + i), rand() % 30);
          }

          DisplayGraph(Graph);          //图的输出
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}