#pragma once
#include<iostream>
using namespace std;
class Identity//创建身份类
{
public:
	virtual void OperMeau()=0;
	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};