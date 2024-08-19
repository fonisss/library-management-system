#include"manager.h"
#include<fstream>
#include"globalFile.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->inVector();
}
// 菜单界面
void Manager::OperMeau()
{
	cout << "----------------- 欢迎来到图书馆管理系统 ------------------" << endl;
	cout << "欢迎管理员：  " <<this->m_Name<<"登录"<< endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     1, 录入图书            |\n";
	cout << "\t\t|     2, 删除图书            |\n";
	cout << "\t\t|     3, 查看图书信息        |\n";
	cout << "\t\t|     4, 修改图书            |\n";
	cout << "\t\t|     5, 录入读者            |\n";
	cout << "\t\t|     6, 删除读者            |\n";
	cout << "\t\t|     7, 修改读者            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "请输入您的选择： "<<endl;
}
//录入图书
void Manager::Addbook()
{
	ofstream ofs;
	int select;
	ofs.open(BOOK_FILE, ios::out | ios::app);
	int id;
	string b_name;
	int pwd;
	int num;
	cout << "请输入编号" << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	cout << "请输入图书名" << endl;
	cin >> b_name;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> b_name;
	}
	cout << "请输入图书信息（0表示在馆，其他表示借阅人编号）" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd;
	}
	ofs << id << " " << b_name <<" "<<pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

	ofs.close();
}
// 查看图书信息
void Manager::CheckBook()
{
	ifstream ifs;
	int select;
	cout << "图书信息如下" << endl;
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		cout << "图书编号： " << it->m_Id << " 书名： " << it->name << " 图书信息（0表示在馆，其他表示借阅人编号）: " << it->pwd << endl;
	}
	system("pause");
	system("cls");
	this->inVector();
}
// 删除图书
void Manager::DelBook()
{
	int select;
	cout << "请输入你想删除的图书编号" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> select;
	}
	fstream ofs;
	ofs.open(BOOK_FILE, ios::trunc | ios::out);
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if(it->m_Id!=select)
		ofs << it->m_Id << " " << it->name << " " << it->pwd << endl;
	}
	system("pause");
	system("cls");
	this->inVector();
	ofs.close();

}
// 修改图书
void Manager::ChangeBook()
{
	int select;
	string b_name;
	int pwd1;
	cout << "请输入你想修改的图书编号" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> select;
	}
	cout << "请输入修改后图书名" << endl;
	cin >> b_name;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> b_name;
	}
	cout << "请输入修改后的图书信息（0表示在馆，其他表示借阅人编号)" << endl;
	cin >> pwd1;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd1;
	}
	fstream ofs;
	ofs.open(BOOK_FILE, ios::trunc | ios::out);
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->m_Id != select)
			ofs << it->m_Id << " " << it->name << " " << it->pwd << endl;
		else
		{
			ofs << select << " " << b_name << " " << pwd1 << " " << endl;
		}
	}
	system("pause");
	system("cls");
	this->inVector();

	ofs.close();
}
//录入读者
void Manager::AddReader()
{
	string fileName;
	ofstream ofs;
	fileName = READER_FILE;
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	this->inVector();
	cout << "请输入编号" << endl;
	while (1)
	{
		cin >> id;
		while (cin.fail())
		{
			cerr << "输入错误！请重新输入:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> id;
		}
		if (checkrepeat(id))
		{
			cout << "读者已存在" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入读者姓名" << endl;
	cin >> name;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> name;
	}
	cout << "请输入读者密码" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd;
	}
	ofs << id << " " << name << " " <<pwd<<" " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	
	ofs.close();
	this->inVector();
}
// 删除读者
void Manager::DelReader()
{
	fstream ifs;
	int select;
	cout << "请输入你想删除的读者编号" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> select;
	}
	fstream ofs;
	ofs.open(READER_FILE, ios::trunc | ios::out);
	for (vector<Reader>::iterator it = v_rea.begin(); it != v_rea.end(); it++)
	{
		if (it->m_Id != select)
			ofs << it->m_Id << " " << it->m_Name << " " << it->m_Pwd << endl;
	}
	system("pause");
	system("cls");
	this->inVector();
	ofs.close();
}
// 修改读者
void Manager::ChangeReader()
{
	int id;
	string name;
	int pwd;
	cout << "请输入你想修改编号" << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	cout << "请输入修改后的读者姓名" << endl;
	cin >> name;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> name;
	}
	cout << "请输入修改后的读者密码" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd;
	}
	fstream ofs;
	ofs.open(READER_FILE, ios::trunc | ios::out);
	for (vector<Reader>::iterator it = v_rea.begin(); it != v_rea.end(); it++)
	{
		if (it->m_Id != id)
			ofs << it->m_Id << " " << it->m_Name << " " << it->m_Pwd << endl;
		else {
			ofs << id << " " << name << " " << pwd << " " << endl;
		}
	}
	system("pause");
	system("cls");
	this->inVector();
	ofs.close();
}
void Manager::inVector()
{
	v_rea.clear();
	v_book.clear();
	ifstream ifs;
	//reader
	ifs.open(READER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		ifs.close();
		return;
	}
	Reader s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		v_rea.push_back(s);
	}
	ifs.close();
	//book
	ifs.open(BOOK_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		ifs.close();
		return;
	}
	Book b;
	while (ifs >> b.m_Id && ifs >> b.name && ifs >> b.pwd)
	{
		v_book.push_back(b);
	}
	ifs.close();

}
bool Manager::checkrepeat(int id)
{
		//检测读者
		for (vector<Reader>::iterator it = v_rea.begin(); it != v_rea.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}

	return false;
}
