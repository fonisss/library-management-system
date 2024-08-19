#include"reader.h"
#include<string>
#include"globalFile.h"
#include<fstream>
//默认构造
Reader::Reader() 
{

}
//有参构造{}
Reader::Reader(int id,string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->inVector();
}
// 菜单界面
void Reader::OperMeau()
{
	cout << "----------------- 欢迎来到图书馆管理系统 ------------------" << endl;
	cout << "欢迎读者：  " << this->m_Name << "登录" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     1, 借阅图书            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     2, 查看在借图书信息    |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     3, 还书                |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "请输入您的选择： " << endl;
}
void Reader::changeid(int id,int m_id)
{
	fstream ofs;
	ofs.open(BOOK_FILE, ios::trunc | ios::out);
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->m_Id != id)
			ofs << it->m_Id << " " << it->name << " " << it->pwd << endl;
		else
		{
			ofs << id << " " << it->name << " " << m_id << " " << endl;
		}
	}
	system("pause");
	system("cls");
	this->inVector();

	ofs.close();
}
//1,借阅图书
void Reader::r_Borrow()
{
	int id;
	cout << "请输入您想借阅的书的编号: " << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->m_Id == id)
		{
			if (it->pwd == 0)
			{
				changeid(id,this->m_Id);
				cout << "恭喜你成功借阅！" << endl;
				system("pause");
				system("cls");
			}
			else if(it->pwd==this->m_Id)
			{
				cout << "这本书您已经借阅！" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "这本书已经被他人借阅！" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	cout << "图书馆目前没有这本书！" << endl;

}
// 2,查看在借图书信息
void Reader::r_Check()
{
	ifstream ifs;
	int select;
	cout << "图书信息如下" << endl;
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->pwd == this->m_Id) {
			cout << "图书编号： " << it->m_Id << " 书名： " << it->name << " 借阅信息（0表示在馆，其他表示借阅人编号): " << it->pwd << endl;
		}
	}
	system("pause");
	system("cls");
}
// 3,还书
void Reader::r_Reaturn()
{
	int id;
	cout << "请输入您想还的书的编号: " << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "输入错误！请重新输入:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->m_Id == id)
		{
			if (it->pwd == this->m_Id)
			{
				changeid(id,0);
				cout << "恭喜你成功还书！" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "这本书您并未借阅借阅！" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	cout << "图书馆目前没有这本书！" << endl;
}
//初始化容器
void Reader::inVector()
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
