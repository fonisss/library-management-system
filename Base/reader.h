#pragma once
#include<iostream>
#include<vector>
#include"book.h"
using namespace std;
#include"Identity.h"
class Reader : public Identity//设置学生类，继承身份基类
{
public:
	//默认构造
	Reader();
	//有参构造
	Reader(int id, string name, string pwd);
	// 菜单界面
	virtual void OperMeau();
	//借阅图书
	void r_Borrow();
	// 查看在借图书信息
	void r_Check();
	// 还书
	void r_Reaturn();
	// 读者编号
	int m_Id;
	void changeid(int a, int b);
	//添加读者,图书容器
	vector<Reader> v_rea;
	vector<Book> v_book;
	//初始化容器
	void inVector();
};
