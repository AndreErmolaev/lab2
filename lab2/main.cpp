#include "Worker.h"
#include <clocale>
#include <string>
int main()
{
	setlocale(LC_ALL, "Ru-ru");
	system("chcp 1251");
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	using std::getline;
	string str;
	int choice_action = 0;
	WORKER** mas = nullptr;
	WORKER** for_realloc = nullptr;
	unsigned int size_mas = 0;
	while (1)
	{
		bool error = false;
		int year = 0;
		choice_action = 0;
		cout << "\n�������� ���� �� �������� ������ �����:\n";
		cout << "1 - �������� �������� � ���������\n";
		cout << "2 - ������������� �������� � ���������\n";
		cout << "3 - ������� �������� � ���������\n";
		cout << "4 - ����� �� ���������\n";
		cout << "����: ";
		cin >> choice_action;
		while (cin.fail() || (choice_action < 1 || choice_action > 4) )
		{
			if (cin.fail())
			{
				cout << "\n---- ������ �����! ������� �� �����! ----\n";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}
			else
				cout << "\n-- ����� ������������ ����� ��������! --\n";
			cout << "��������� ����: ";
			cin >> choice_action;
		}
		if(cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
			cin.get();
		switch (choice_action)
		{
		case 1:
			size_mas += 1;
			if (size_mas - 1 == 0)
			{
				mas = new WORKER * [size_mas];
				mas[size_mas - 1] = new WORKER;
			}
			else
			{
				for_realloc = new WORKER * [size_mas];
				for (unsigned int i = 0; i < size_mas - 1; i++)
					for_realloc[i] = mas[i];
				delete[] mas;
				for_realloc[size_mas - 1] = new WORKER;
				mas = for_realloc;
			}
			try
			{
				cin >> mas[size_mas - 1];
			}
			catch (WORKER::work_exception& excep)
			{
				cout << excep.what() << excep.get_error() << std::endl;
				error = true;
			}
			while (error)
			{
				error = false;
				cout << "������� ��� ����������� �� ������ ��� ���: ";
				cin >> year;
				while (cin.fail())
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "--- ������� �� �����!\n��������� ����: ";
					cin >> year;
				}
				try
				{
					mas[size_mas - 1]->set_year(year);
				}
				catch (WORKER::work_exception& excep)
				{
					cout << excep.what() << excep.get_error() << std::endl;
					error = true;
				}
				if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
					cin.get();
			}
			sort_alphabet(mas, size_mas);
			for (unsigned int i = 0; i < size_mas; i++)
				cout << mas[i];
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			goto END;
		}
	}
END:;
	for (unsigned int i = 0; i < size_mas; i++)
		delete mas[i];
	delete[] mas;
	/*
	std::string str;
	std::getline(cin, str);
	cout << str << "\n" << str[0] << "\n";
	cout << "eofbit: " << cin.eof() << "\n" << "badbit: " << cin.bad() << "\n" << "failbit: " << cin.fail() << "\n";
	*/  //������ ��� �������� ����� ������ ������ (����� ������ \0 ��� ������ ������)
	return 0;
}