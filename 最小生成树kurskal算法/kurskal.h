#pragma once
#include"QuickSort.h"					//����
#include"Union.h"						    //���鼯

void InitKurskal(MGraph G, EDGE** arr, int** UnionArray);	//��ʼ��Kurskal�㷨�����������Լ����鼯����
void DestroyKurskal(EDGE* arr, int* UnionArray);			//Kurskal�㷨����
void Kurskal(MGraph G);			  //Kurskal�㷨���岿��