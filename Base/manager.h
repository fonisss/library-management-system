#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"Identity.h"
#include"reader.h"
#include"book.h"
class Manager :public Identity//���ù������࣬�̳���ݻ���
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	// �˵�����
	virtual void OperMeau();
	int Isexist(string filename,int id);
	//¼��ͼ��
	void Addbook();
	// �鿴ͼ����Ϣ
	void CheckBook();
	// ɾ��ͼ��
	void DelBook();
	// �޸�ͼ��
	void ChangeBook();
	//¼�����
	void AddReader();
	// ɾ������
	void DelReader();
	// �޸Ķ���
	void ChangeReader();
	//��ʼ������
	void inVector();
	//��Ӷ���,ͼ������
	vector<Reader> v_rea;
	vector<Book> v_book;
	//����ظ� ����������Id���������ͣ�����ֵ��true�ظ���false���ظ���
	bool checkrepeat(int id);
};
