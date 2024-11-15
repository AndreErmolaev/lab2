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
		int number = 0;
		int choice_edit = 0;
		choice_action = 0;
		cout << "\n�������� ���� �� �������� ������ �����:\n";
		cout << "1 - �������� �������� � ���������\n";
		cout << "2 - ������������� �������� � ���������\n";
		cout << "3 - ������� �������� � ���������\n";
		cout << "4 - ����������� ������ ���� ����������\n";
		cout << "5 - ����� ����������, ��� ���� ��������� �������� ��������\n";
		cout << "6 - ����� �� ���������\n";
		cout << "����: ";
		cin >> choice_action;
		while (cin.fail() || (choice_action < 1 || choice_action > 6) )
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
			cout << "\n\n�������� � ��������� ���������!\n";
			break;
		case 2:
			if (size_mas == 0)
				cout << "���������� ���!\n";
			else
			{
				for (unsigned int i = 0; i < size_mas; i++)
					cout << '�' << i << ":\n" << mas[i];
				cout << "	�������� ����� ����������: ";
				int number = -1;
				choice_edit;
				cin >> number;
				while (cin.fail() || (number < 0 || number > size_mas - 1))
				{
					if (cin.fail())
					{
						cout << "\n---- ������ �����! ������� �� �����! ----\n";
						cin.clear();
						while (cin.get() != '\n')
							continue;
					}
					else
						cout << "\n-- ����� ������������ ����� ���������! --\n";
					cout << "��������� ����: ";
					cin >> number;
				}
				if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
					cin.get();
				cout << "��������, ��� ����� ��������:\n";
				cout << "1 - �������� ���\n";
				cout << "2 - �������� �������\n";
				cout << "3 - �������� ��������\n";
				cout << "4 - �������� ���������\n";
				cout << "5 - �������� ���� ����������� �� ������\n";
				cout << "6 - �������� ������� ���������\n";
				cout << "����: ";
				cin >> choice_edit;
				while (cin.fail() || (choice_edit < 1 || choice_edit > 6))
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
					cin >> choice_edit;
				}
				if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
					cin.get();
				if (choice_edit == 1)
				{
					cout << "������� ����� ���: ";
					getline(cin, str);
					while (str[0] == '\0')
					{
						cout << "--- ������� ������ ������!\n��������� ����: ";
						getline(cin, str);
					}
					mas[number]->set_name(str.c_str());
				}
				else if (choice_edit == 2)
				{
					cout << "������� ����� �������: ";
					getline(cin, str);
					while (str[0] == '\0')
					{
						cout << "--- ������� ������ ������!\n��������� ����: ";
						getline(cin, str);
					}
					mas[number]->set_surname(str.c_str());
				}
				else if (choice_edit == 3)
				{
					cout << "������� ����� ��������: ";
					getline(cin, str);
					while (str[0] == '\0')
					{
						cout << "--- ������� ������ ������!\n��������� ����: ";
						getline(cin, str);
					}
					mas[number]->set_patronyc(str.c_str());
				}
				else if (choice_edit == 4)
				{
					cout << "������� ����� ���������: ";
					getline(cin, str);
					while (str[0] == '\0')
					{
						cout << "--- ������� ������ ������!\n��������� ����: ";
						getline(cin, str);
					}
					mas[number]->set_post(str.c_str());
				}
				else if (choice_edit == 5)
				{
					cout << "������� ��� ����������� �� ������: ";
					cin >> year;
					while (cin.fail())
					{
						cin.clear();
						while (cin.get() != '\n')
							continue;
						cout << "--- ������� �� �����!\n��������� ����: ";
						cin >> year;
					}
					if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
						cin.get();
					try
					{
						mas[number]->set_year(year);
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
							mas[number]->set_year(year);
						}
						catch (WORKER::work_exception& excep)
						{
							cout << excep.what() << excep.get_error() << std::endl;
							error = true;
						}
						if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
							cin.get();
					}
				}
			}
			break;
		case 3:
			if (size_mas == 0)
				cout << "���������� ���!\n";
			else
			{
				for (unsigned int i = 0; i < size_mas; i++)
					cout << '�' << i << ":\n" << mas[i];
				cout << "	�������� ����� ����������: ";
				int number = -1;
				choice_edit;
				cin >> number;
				while (cin.fail() || (number < 0 || number > size_mas - 1))
				{
					if (cin.fail())
					{
						cout << "\n---- ������ �����! ������� �� �����! ----\n";
						cin.clear();
						while (cin.get() != '\n')
							continue;
					}
					else
						cout << "\n-- ����� ������������ ����� ���������! --\n";
					cout << "��������� ����: ";
					cin >> number;
				}
				if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
					cin.get();
				delete mas[number];
				for_realloc = new WORKER * [size_mas - 1];
				for (unsigned int i = 0; i < number; i++)
					for_realloc[i] = mas[i];
				for (unsigned int i = number + 1; i < size_mas; i++)
					for_realloc[i - 1] = mas[i];
				delete[] mas;
				mas = for_realloc;
				size_mas -= 1;
				cout << "\n\n�������� � ��������� �������!\n";
			}
			break;
		case 4:
			if (size_mas == 0)
				cout << "���������� ���!\n";
			else
			{
				for (unsigned int i = 0; i < size_mas; i++)
					cout << '�' << i << ":\n" << mas[i];
			}
			break;
		case 5:
			if (size_mas == 0)
				cout << "���������� ���!\n";
			else
			{
				cout << "������� ��� ����������� �� ������: ";
				cin >> year;
				while (cin.fail() || year < 1)
				{
					if (cin.fail())
					{
						cout << "\n---- ������ �����! ������� �� �����! ----\n";
						cin.clear();
						while (cin.get() != '\n')
							continue;
					}
					else
						cout << "\n-- ����� ��������������� ���! --\n";
					cout << "��������� ����: ";
					cin >> year;
				}
				if (cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == '\t')
					cin.get();
				for (unsigned int i = 0; i < size_mas; i++)
				{
					if (mas[i]->get_year() > year)
						cout << i << ": " << mas[i]->get_surname() << " " << mas[i]->get_year() << endl;
				}
			}
			break;
		case 6:
			goto END;
		}
	}
END:;
	for (unsigned int i = 0; i < size_mas; i++)
		delete mas[i];
	delete[] mas;
	return 0;
}