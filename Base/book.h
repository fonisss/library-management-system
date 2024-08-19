#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
class Book //设置书类，继承身份基类
{
public:
	//默认构造
	Book();
	//有参构造
	Book(string name, int pwd);//书名，和是否在馆
	// 书籍编号
	int m_Id;
	string name;
	int pwd;
};