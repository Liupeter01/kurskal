#pragma once
#include"MGraph.h"

void UnionInitial(MGraph G,int** UnionArray);			//���鼯�ĳ�ʼ��
void Union(int* S, int Root1, int Root2);    //���ϵĺϲ�����Root2Ҫ���ϲ�������Root1��
int FindItem(int* S, int x);  //���ҵ�ǰ��ֵλ����һ������SΪ���鼯��xΪ������Ԫ��