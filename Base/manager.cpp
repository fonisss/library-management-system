#include"manager.h"
#include<fstream>
#include"globalFile.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->inVector();
}
// �˵�����
void Manager::OperMeau()
{
	cout << "----------------- ��ӭ����ͼ��ݹ���ϵͳ ------------------" << endl;
	cout << "��ӭ����Ա��  " <<this->m_Name<<"��¼"<< endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|     1, ¼��ͼ��            |\n";
	cout << "\t\t|     2, ɾ��ͼ��            |\n";
	cout << "\t\t|     3, �鿴ͼ����Ϣ        |\n";
	cout << "\t\t|     4, �޸�ͼ��            |\n";
	cout << "\t\t|     5, ¼�����            |\n";
	cout << "\t\t|     6, ɾ������            |\n";
	cout << "\t\t|     7, �޸Ķ���            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "����������ѡ�� "<<endl;
}
//¼��ͼ��
void Manager::Addbook()
{
	ofstream ofs;
	int select;
	ofs.open(BOOK_FILE, ios::out | ios::app);
	int id;
	string b_name;
	int pwd;
	int num;
	cout << "��������" << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	cout << "������ͼ����" << endl;
	cin >> b_name;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> b_name;
	}
	cout << "������ͼ����Ϣ��0��ʾ�ڹݣ�������ʾ�����˱�ţ�" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd;
	}
	ofs << id << " " << b_name <<" "<<pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();
}
// �鿴ͼ����Ϣ
void Manager::CheckBook()
{
	ifstream ifs;
	int select;
	cout << "ͼ����Ϣ����" << endl;
	for (vector<Book>::iterator it = v_book.begin(); it != v_book.end(); it++)
	{
		cout << "ͼ���ţ� " << it->m_Id << " ������ " << it->name << " ͼ����Ϣ��0��ʾ�ڹݣ�������ʾ�����˱�ţ�: " << it->pwd << endl;
	}
	system("pause");
	system("cls");
	this->inVector();
}
// ɾ��ͼ��
void Manager::DelBook()
{
	int select;
	cout << "����������ɾ����ͼ����" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
// �޸�ͼ��
void Manager::ChangeBook()
{
	int select;
	string b_name;
	int pwd1;
	cout << "�����������޸ĵ�ͼ����" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> select;
	}
	cout << "�������޸ĺ�ͼ����" << endl;
	cin >> b_name;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> b_name;
	}
	cout << "�������޸ĺ��ͼ����Ϣ��0��ʾ�ڹݣ�������ʾ�����˱��)" << endl;
	cin >> pwd1;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
//¼�����
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
	cout << "��������" << endl;
	while (1)
	{
		cin >> id;
		while (cin.fail())
		{
			cerr << "�����������������:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> id;
		}
		if (checkrepeat(id))
		{
			cout << "�����Ѵ���" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "�������������" << endl;
	cin >> name;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> name;
	}
	cout << "�������������" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> pwd;
	}
	ofs << id << " " << name << " " <<pwd<<" " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	
	ofs.close();
	this->inVector();
}
// ɾ������
void Manager::DelReader()
{
	fstream ifs;
	int select;
	cout << "����������ɾ���Ķ��߱��" << endl;
	cin >> select;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
// �޸Ķ���
void Manager::ChangeReader()
{
	int id;
	string name;
	int pwd;
	cout << "�����������޸ı��" << endl;
	cin >> id;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	cout << "�������޸ĺ�Ķ�������" << endl;
	cin >> name;
	while (cin.fail())
	{
		cerr << "�����������������:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> name;
	}
	cout << "�������޸ĺ�Ķ�������" << endl;
	cin >> pwd;
	while (cin.fail())
	{
		cerr << "�����������������:";
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
bool Manager::checkrepeat(int id)
{
		//������
		for (vector<Reader>::iterator it = v_rea.begin(); it != v_rea.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}

	return false;
}
