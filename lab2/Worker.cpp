#include "Worker.h"
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
WORKER::WORKER() : surname_(nullptr), name_(nullptr), patronyc_(nullptr), post_(nullptr), year_(2024)
{
	std::cout << "\n---------- ����������� ��� ���������� WORKER! ----------\n";
}
WORKER::WORKER(const char* sur,const char* name,const char* patr,const char* post,int year) : surname_(nullptr), name_(nullptr), patronyc_(nullptr), post_(nullptr), year_(0)
{
	try
	{
		surname_ = new char[std::strlen(sur) + 1];
		name_ = new char[std::strlen(name) + 1];
		patronyc_ = new char[std::strlen(patr) + 1];
		post_ = new char[std::strlen(post) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cerr << "------- ������������ ������! ---------\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(surname_, sur);
	std::strcpy(name_, name);
	std::strcpy(patronyc_, patr);
	std::strcpy(post_, post);
	year_=year;
	std::cout << "\n---------- ����������� � ����������� ������ WORKER! ----------\n";
}
WORKER::WORKER(WORKER& copy) : surname_(nullptr), name_(nullptr), patronyc_(nullptr), post_(nullptr), year_(0)
{
	try
	{
		surname_ = new char[std::strlen(copy.surname_) + 1];
		name_ = new char[std::strlen(copy.name_) + 1];
		patronyc_ = new char[std::strlen(copy.patronyc_) + 1];
		post_ = new char[std::strlen(copy.post_) + 1];
	}
	catch (std::bad_alloc)
	{
		std::cerr << "------- ������������ ������! ---------\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(surname_, copy.surname_);
	std::strcpy(name_, copy.name_);
	std::strcpy(patronyc_, copy.patronyc_);
	std::strcpy(post_, copy.post_);
	year_ = copy.year_;
	std::cout << "\n---------- ����������� ����������� ������ WORKER! ----------\n";
}
WORKER::~WORKER()
{
	delete[] surname_;
	delete[] name_;
	delete[] patronyc_;
	delete[] post_;
	std::cout << "\n---------- ���������� ������ WORKER! ----------\n";
}
WORKER& WORKER::operator=(const WORKER& obj)
{
	if (this != &obj)
	{
		set_surname(obj.surname_);
		set_name(obj.name_);
		set_patronyc(obj.patronyc_);
		set_post(obj.post_);
		year_ = obj.year_;
	}
	return *this;
}
void WORKER::set_surname(const char* sur)
{
	unsigned int size_sur = std::strlen(sur);
	unsigned int size_surname = 0;
	if (surname_ != nullptr)
	{
		size_surname = std::strlen(surname_);
		if (size_sur == size_surname)               //������ ������������ �� ����
			std::strcpy(surname_, sur);
		else
		{
			delete[] surname_;
			try
			{
				surname_ = new char[size_sur + 1];
			}
			catch (std::bad_alloc)
			{
				std::cerr << "------- ������������ ������! ---------\n";
				exit(EXIT_FAILURE);
			}
			surname_[0] = '\0';              //���� �������� ������ ������
			std::strcpy(surname_, sur);
		}
	}
	else
	{
		try
		{
			surname_ = new char[size_sur + 1];
		}
		catch (std::bad_alloc)
		{
			std::cerr << "------- ������������ ������! ---------\n";
			exit(EXIT_FAILURE);
		}
		surname_[0] = '\0';              //���� �������� ������ ������
		std::strcpy(surname_, sur);
	}
}
void WORKER::set_name(const char* name)
{
	unsigned int size_name = std::strlen(name);
	unsigned int size_name_ = 0;
	if (name_ != nullptr)
	{
		size_name_ = std::strlen(name_);
		if (size_name == size_name_)               //������ ������������ �� ����
			std::strcpy(name_, name);
		else
		{
			delete[] name_;
			try
			{
				name_ = new char[size_name + 1];
			}
			catch (std::bad_alloc)
			{
				std::cerr << "------- ������������ ������! ---------\n";
				exit(EXIT_FAILURE);
			}
			name_[0] = '\0';              //���� �������� ������ ������
			std::strcpy(name_, name);
		}
	}
	else
	{
		try
		{
			name_ = new char[size_name + 1];
		}
		catch (std::bad_alloc)
		{
			std::cerr << "------- ������������ ������! ---------\n";
			exit(EXIT_FAILURE);
		}
		name_[0] = '\0';              //���� �������� ������ ������
		std::strcpy(name_, name);
	}
}
void WORKER::set_patronyc(const char* patr)
{
	unsigned int size_patr = std::strlen(patr);
	unsigned int size_patronyc = 0;
	if (patronyc_ != nullptr)
	{
		size_patronyc = std::strlen(patronyc_);
		if (size_patr == size_patronyc)               //������ ������������ �� ����
			std::strcpy(patronyc_, patr);
		else
		{
			delete[] patronyc_;
			try
			{
				patronyc_ = new char[size_patr + 1];
			}
			catch (std::bad_alloc)
			{
				std::cerr << "------- ������������ ������! ---------\n";
				exit(EXIT_FAILURE);
			}
			patronyc_[0] = '\0';              //���� �������� ������ ������
			std::strcpy(patronyc_, patr);
		}
	}
	else
	{
		try
		{
			patronyc_ = new char[size_patr + 1];
		}
		catch (std::bad_alloc)
		{
			std::cerr << "------- ������������ ������! ---------\n";
			exit(EXIT_FAILURE);
		}
		patronyc_[0] = '\0';              //���� �������� ������ ������
		std::strcpy(patronyc_, patr);
	}
}
void WORKER::set_post(const char* post)
{
	unsigned int size_post = std::strlen(post);
	unsigned int size_post_ = 0;
	if (post_ != nullptr)
	{
		size_post_ = std::strlen(post_);
		if (size_post == size_post_)               //������ ������������ �� ����
			std::strcpy(post_, post);
		else
		{
			delete[] post_;
			try
			{
				post_ = new char[size_post + 1];
			}
			catch (std::bad_alloc)
			{
				std::cerr << "------- ������������ ������! ---------\n";
				exit(EXIT_FAILURE);
			}
			post_[0] = '\0';              //���� �������� ������ ������
			std::strcpy(post_, post);		
		}
	}
	else
	{
		try
		{
			post_ = new char[size_post + 1];
		}
		catch (std::bad_alloc)
		{
			std::cerr << "------- ������������ ������! ---------\n";
			exit(EXIT_FAILURE);
		}
		post_[0] = '\0';              //���� �������� ������ ������
		std::strcpy(post_, post);
	}
}
std::ostream& operator<<(std::ostream& out, WORKER* obj)
{
	unsigned int width = std::strlen(obj->get_surname());
	if (width < std::strlen(obj->get_name()))
		width = std::strlen(obj->get_name());
	if (width < std::strlen(obj->get_patronyc()))
		width = std::strlen(obj->get_patronyc());
	if (width < std::strlen(obj->get_post()))
		width = std::strlen(obj->get_post());
	out << "�������: " << std::setw(width+2) << obj->get_surname() << std::endl;
	out << "���: " << std::setw(width+6) << obj->get_name() << std::endl;
	out << "��������: " << std::setw(width+1) << obj->get_patronyc() << std::endl;
	out << "���������: " << std::setw(width) << obj->get_post() << std::endl;
	out << "���: " << std::setw(width+6) << obj->get_year() << std::endl;
	out << std::setfill('-') << std::setw(width + 12) << "\n";
	out.fill(' ');
	return out;
}
std::istream& operator>>(std::istream& in, WORKER* obj)
{
	std::string str;
	std::cout << "������� �������: ";
	std::getline(in,str);
	while (str[0] == '\0')
	{
		std::cout << "--- ������� ������ ������!\n��������� ����: ";
		std::getline(in, str);
	}
	obj->set_surname(str.c_str());
	std::cout << "������� ���: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- ������� ������ ������!\n��������� ����: ";
		std::getline(in, str);
	}
	obj->set_name(str.c_str());
	std::cout << "������� ��������: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- ������� ������ ������!\n��������� ����: ";
		std::getline(in, str);
	}
	obj->set_patronyc(str.c_str());
	std::cout << "������� ���������: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- ������� ������ ������!\n��������� ����: ";
		std::getline(in, str);
	}
	obj->set_post(str.c_str());
	std::cout << "������� ��� ����������� �� ������: ";
	int year = 0;
	in >> year;
	while (in.fail())
	{
		in.clear();
		while (in.get() != '\n')
			continue;
		std::cout << "--- ������� �� �����!\n��������� ����: ";
		in >> year;
	}
	if(in.peek() == '\n' || in.peek() == ' ' || in.peek() == '\t')
		in.get();
	obj->set_year(year);
	return in;
}
int compare(const void* str1, const void* str2)
{
	return strcmp(*(char**)str1, *(char**)str2);
}
void sort_alphabet(WORKER** mas,unsigned int size)
{
	char* FIO = nullptr;
	char** massiv = new char*[size];
	for (unsigned int i = 0; i < size; i++)
	{
		FIO = new char[std::strlen(mas[i]->get_surname()) + std::strlen(mas[i]->get_name()) + std::strlen(mas[i]->get_patronyc()) + 4];
		int index = 0;
		for (int j = 0; j < std::strlen(mas[i]->get_surname()); j++,index++)
			FIO[index] = (mas[i]->get_surname())[j];
		FIO[index++] = ' ';
		for (int j = 0; j < std::strlen(mas[i]->get_name()); j++,index++)
			FIO[index] = (mas[i]->get_name())[j];
		FIO[index++] = ' ';
		for (int j = 0; j < std::strlen(mas[i]->get_patronyc()); j++, index++)
			FIO[index] = (mas[i]->get_patronyc())[j];
		FIO[index++] = ' ';
		FIO[index] = '\0';
		massiv[i] = FIO;
	}
	qsort(massiv, size, sizeof(char**), compare);
	for (unsigned int i = 0; i < size; i++)
	{
		char* vrem[3];
		vrem[0] = strtok(massiv[i], " ");
		vrem[1] = strtok(nullptr, " ");
		vrem[2] = strtok(nullptr, " ");
		for (unsigned int j = 0; j < size;j++)
		{
			if (std::strcmp(vrem[0], mas[j]->get_surname()) == 0 && std::strcmp(vrem[1], mas[j]->get_name()) == 0 && std::strcmp(vrem[2], mas[j]->get_patronyc()) == 0)
			{
				WORKER* for_change = mas[j];
				mas[j] = mas[i];
				mas[i] = for_change;
			}
		}
	}
	for (unsigned int i = 0; i < size; i++)
		delete[] massiv[i];
	delete[] massiv;
}