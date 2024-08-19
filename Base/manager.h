#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"Identity.h"
#include"reader.h"
#include"book.h"
class Manager :public Identity//设置管理者类，继承身份基类
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	// 菜单界面
	virtual void OperMeau();
	int Isexist(string filename,int id);
	//录入图书
	void Addbook();
	// 查看图书信息
	void CheckBook();
	// 删除图书
	void DelBook();
	// 修改图书
	void ChangeBook();
	//录入读者
	void AddReader();
	// 删除读者
	void DelReader();
	// 修改读者
	void ChangeReader();
	//初始化容器
	void inVector();
	//添加读者,图书容器
	vector<Reader> v_rea;
	vector<Book> v_book;
	//检测重复 参数（传入Id，传入类型）返回值（true重复，false不重复）
	bool checkrepeat(int id);
};
