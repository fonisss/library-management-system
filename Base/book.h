#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
class Book //�������࣬�̳���ݻ���
{
public:
	//Ĭ�Ϲ���
	Book();
	//�вι���
	Book(string name, int pwd);//���������Ƿ��ڹ�
	// �鼮���
	int m_Id;
	string name;
	int pwd;
};