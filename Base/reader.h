#pragma once
#include<iostream>
#include<vector>
#include"book.h"
using namespace std;
#include"Identity.h"
class Reader : public Identity//����ѧ���࣬�̳���ݻ���
{
public:
	//Ĭ�Ϲ���
	Reader();
	//�вι���
	Reader(int id, string name, string pwd);
	// �˵�����
	virtual void OperMeau();
	//����ͼ��
	void r_Borrow();
	// �鿴�ڽ�ͼ����Ϣ
	void r_Check();
	// ����
	void r_Reaturn();
	// ���߱��
	int m_Id;
	void changeid(int a, int b);
	//��Ӷ���,ͼ������
	vector<Reader> v_rea;
	vector<Book> v_book;
	//��ʼ������
	void inVector();
};
