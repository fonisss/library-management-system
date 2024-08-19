#include"reader.h"
#include<string>
#include"globalFile.h"
#include<fstream>
//Ĭ�Ϲ���
Reader::Reader() 
{

}
//�вι���{}
Reader::Reader(int id,string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->inVector();
}
// �˵�����
void Reader::OperMeau()
{
	cout << "----------------- ��ӭ����ͼ��ݹ���ϵͳ ------------------" << endl;
	cout << "��ӭ���ߣ�  " << this->m_Name << "��¼" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     1, ����ͼ��            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     2, �鿴�ڽ�ͼ����Ϣ    |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     3, ����                |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "����������ѡ�� " << endl;
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
//1,����ͼ��
void Reader::r_Borrow()
{
	int id;
	cout << "������������ĵ���ı��: " << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
				cout << "��ϲ��ɹ����ģ�" << endl;
				system("pause");
				system("cls");
			}
			else if(it->pwd==this->m_Id)
			{
				cout << "�Ȿ�����Ѿ����ģ�" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "�Ȿ���Ѿ������˽��ģ�" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	cout << "ͼ���Ŀǰû���Ȿ�飡" << endl;

}
// 2,�鿴�ڽ�ͼ����Ϣ
void Reader::r_Check()
{
	ifstream ifs;
	int select;
	cout << "ͼ����Ϣ����" << endl;
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		if (it->pwd == this->m_Id) {
			cout << "ͼ���ţ� " << it->m_Id << " ������ " << it->name << " ������Ϣ��0��ʾ�ڹݣ�������ʾ�����˱��): " << it->pwd << endl;
		}
	}
	system("pause");
	system("cls");
}
// 3,����
void Reader::r_Reaturn()
{
	int id;
	cout << "���������뻹����ı��: " << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
				cout << "��ϲ��ɹ����飡" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "�Ȿ������δ���Ľ��ģ�" << endl;
				system("pause");
				system("cls");
			}
		}
	}
	cout << "ͼ���Ŀǰû���Ȿ�飡" << endl;
}
//��ʼ������
void Reader::inVector()
{
	v_rea.clear();
	v_book.clear();
	ifstream ifs;
	//reader
	ifs.open(READER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
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
		cout << "�ļ���ȡʧ��" << endl;
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
