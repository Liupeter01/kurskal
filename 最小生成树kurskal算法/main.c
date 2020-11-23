#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"kurskal.h"                               //kurskal algorthim

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFG" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //�����б��������

          VertexType arr1[] = "AAAFFBFGFCDD";
          VertexType arr2[] = "BFGBGCCEEECE";

          int Distance[] = { 12,16,14,7,9,10,6,8,2,5,3,4 };


          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), Distance[i]);
          }

          Kurskal(Graph, 'A');

          DisplayGraph(Graph);          //ͼ�����
          DestroyGraph(&Graph);         //ͼ������
          return 0;
}