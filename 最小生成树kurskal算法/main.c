#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"kurskal.h"                               //kurskal algorthim

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          VertexType arr1[] = "AEACCE";
          VertexType arr2[] = "BACBDC";

          int Distance[] = { 3,4,1,2 ,5,6 };


          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), Distance[i]);
          }

          DisplayGraph(Graph);          //ͼ�����

          Kurskal(Graph);
          DestroyGraph(&Graph);         //ͼ������
          return 0;
}