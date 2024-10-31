#include "Worker.h"
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
WORKER::WORKER() : surname_(nullptr), name_(nullptr), patronyc_(nullptr), post_(nullptr), year_(0)
{
	std::cout << "\n---------- КОНСТРУКТОР БЕЗ ПАРАМЕТРОВ WORKER! ----------\n";
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
		std::cout << "------- Недостаточно памяти! ---------\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(surname_, sur);
	std::strcpy(name_, name);
	std::strcpy(patronyc_, patr);
	std::strcpy(post_, post);
	year_=year;
	std::cout << "\n---------- КОНСТРУКТОР С ПАРАМЕТРАМИ КЛАССА WORKER! ----------\n";
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
		std::cout << "------- Недостаточно памяти! ---------\n";
		exit(EXIT_FAILURE);
	}
	std::strcpy(surname_, copy.surname_);
	std::strcpy(name_, copy.name_);
	std::strcpy(patronyc_, copy.patronyc_);
	std::strcpy(post_, copy.post_);
	year_ = copy.year_;
	std::cout << "\n---------- КОНСТРУКТОР КОПИРОВАНИЯ КЛАССА WORKER! ----------\n";
}
WORKER::~WORKER()
{
	delete[] surname_;
	delete[] name_;
	delete[] patronyc_;
	delete[] post_;
	std::cout << "\n---------- ДЕСТРУКТОР КЛАССА WORKER! ----------\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WORKER::set_surname(const char* sur)             //надо предусмотреть, чтобы не передавались ПУСТЫЕ строки
{
	unsigned int size_sur = std::strlen(sur);
	unsigned int size_surname = 0;
	if (surname_ != nullptr)
	{
		size_surname = std::strlen(surname_);
		if (size_sur == size_surname)               //память перевыделять для surname не надо
		{
			std::strcpy(surname_, sur);

			std::cout << "\n\n--- size_sur == size_surname\n\n";  ////////////////////////////
		}
		else
		{
			delete[] surname_;
			try
			{
				surname_ = new char[size_sur + 1];
			}
			catch (std::bad_alloc)
			{
				std::cout << "------- Недостаточно памяти! ---------\n";
				exit(EXIT_FAILURE);
			}
			std::strcpy(surname_, sur);

			std::cout << "\n\n--- size_sur != size_surname\n\n";  /////////////////////////////
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
			std::cout << "------- Недостаточно памяти! ---------\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(surname_, sur);

		std::cout << "\n\n--- nullptr\n\n";  /////////////////////////////
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WORKER::set_name(const char* name)
{
	unsigned int size_name = std::strlen(name);
	unsigned int size_name_ = 0;
	if (name_ != nullptr)
	{
		size_name_ = std::strlen(name_);
		if (size_name == size_name_)               //память перевыделять для name_ не надо
		{
			std::strcpy(name_, name);

			std::cout << "\n\n--- size_name == size_name_\n\n";  ////////////////////////////
		}
		else
		{
			delete[] name_;
			try
			{
				name_ = new char[size_name + 1];
			}
			catch (std::bad_alloc)
			{
				std::cout << "------- Недостаточно памяти! ---------\n";
				exit(EXIT_FAILURE);
			}
			std::strcpy(name_, name);

			std::cout << "\n\n--- size_name != size_name_\n\n";  /////////////////////////////
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
			std::cout << "------- Недостаточно памяти! ---------\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(name_, name);

		std::cout << "\n\n--- nullptr\n\n";  /////////////////////////////
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WORKER::set_patronyc(const char* patr)
{
	unsigned int size_patr = std::strlen(patr);
	unsigned int size_patronyc = 0;
	if (patronyc_ != nullptr)
	{
		size_patronyc = std::strlen(patronyc_);
		if (size_patr == size_patronyc)               //память перевыделять для surname не надо
		{
			std::strcpy(patronyc_, patr);

			std::cout << "\n\n--- size_patr == size_patron\n\n";  ////////////////////////////
		}
		else
		{
			delete[] patronyc_;
			try
			{
				patronyc_ = new char[size_patr + 1];
			}
			catch (std::bad_alloc)
			{
				std::cout << "------- Недостаточно памяти! ---------\n";
				exit(EXIT_FAILURE);
			}
			std::strcpy(patronyc_, patr);

			std::cout << "\n\n--- size_patr != size_patron\n\n";  /////////////////////////////
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
			std::cout << "------- Недостаточно памяти! ---------\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(patronyc_, patr);

		std::cout << "\n\n--- nullptr\n\n";  /////////////////////////////
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WORKER::set_post(const char* post)
{
	unsigned int size_post = std::strlen(post);
	unsigned int size_post_ = 0;
	if (patronyc_ != nullptr)
	{
		size_post_ = std::strlen(post_);
		if (size_post == size_post_)               //память перевыделять для post не надо
		{
			std::strcpy(post_, post);

			std::cout << "\n\n--- size_post == size_post\n\n";  ////////////////////////////
		}
		else
		{
			delete[] post_;
			try
			{
				post_ = new char[size_post + 1];
			}
			catch (std::bad_alloc)
			{
				std::cout << "------- Недостаточно памяти! ---------\n";
				exit(EXIT_FAILURE);
			}
			std::strcpy(post_, post);

			std::cout << "\n\n--- size_post != size_post\n\n";  /////////////////////////////
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
			std::cout << "------- Недостаточно памяти! ---------\n";
			exit(EXIT_FAILURE);
		}
		std::strcpy(post_, post);

		std::cout << "\n\n--- nullptr\n\n";  /////////////////////////////
	}
}

std::ostream& operator<<(std::ostream& out, WORKER* obj)
{
	int width = std::strlen(obj->get_surname());
	if (width < std::strlen(obj->get_name()))
		width = std::strlen(obj->get_name());
	if (width < std::strlen(obj->get_patronyc()))
		width = std::strlen(obj->get_patronyc());
	out << "Фамилия: " << std::setw(width+2) << obj->get_surname() << std::endl;
	out << "Имя: " << std::setw(width+6) << obj->get_name() << std::endl;
	out << "Отчество: " << std::setw(width+1) << obj->get_patronyc() << std::endl;
	out << "Должность: " << std::setw(width) << obj->get_post() << std::endl;
	out << "Год: " << std::setw(width+6) << obj->get_year() << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, WORKER* obj)
{
	std::string str;
	std::cout << "Введите фамилию: ";
	std::getline(in,str);
	while (str[0] == '\0')
	{
		std::cout << "--- Введена пустая строка!\nПовторите ввод: ";
		std::getline(in, str);
	}
	obj->set_surname(str.c_str());


	std::cout << "Введите имя: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- Введена пустая строка!\nПовторите ввод: ";
		std::getline(in, str);
	}
	obj->set_name(str.c_str());


	std::cout << "Введите отчество: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- Введена пустая строка!\nПовторите ввод: ";
		std::getline(in, str);
	}
	obj->set_patronyc(str.c_str());


	std::cout << "Введите должность: ";
	std::getline(in, str);
	while (str[0] == '\0')
	{
		std::cout << "--- Введена пустая строка!\nПовторите ввод: ";
		std::getline(in, str);
	}
	obj->set_post(str.c_str());


	std::cout << "Введите год поступления на службу: ";
	BACK:;
	int year = 0;
	while (!in >> year)
	{
		in.clear();
		while (in.get() != '\n')
			continue;
		std::cout << "--- Введено не число!\nПовторите ввод: ";
	}
	try
	{
		obj->set_year(year);
	}
	catch (WORKER::work_exception& excep)
	{
		std::cout << excep.what() << excep.get_error() << std::endl;
		std::cout << "Введите год поступления на службу ещё раз: ";
		goto BACK;
	}
	return in;
}
void sort_alphabet(WORKER** mas)
{
	int size = 0;
	while( mas[size] != nullptr)
		size += 1;
	char* FIO = nullptr;
	char** massiv = new char*[size];
	for (int i = 0; i < size; i++)
	{
		FIO = new char[std::strlen(mas[i]->get_surname()) + std::strlen(mas[i]->get_name()) + std::strlen(mas[i]->get_patronyc()) + 3];
		int index = 0;
		for (int index = 0; index < std::strlen(mas[i]->get_surname()); index++)
			FIO[index] = (mas[i]->get_surname())[index];
		FIO[index] = ' ';
		for (int j = 0; j < std::strlen(mas[i]->get_name()); j++,index++)
			FIO[index] = (mas[i]->get_surname())[j];
		FIO[index] = ' ';
		for (int j = 0; j < std::strlen(mas[i]->get_patronyc()); j++, index++)
			FIO[index] = (mas[i]->get_patronyc())[j];
		FIO[index] = '\0';
		massiv[i] = FIO;
		delete[] FIO;
	}
	qsort(massiv, size, sizeof(char**), compare);
	delete[] massiv;
}
int compare(const void* str1, const void* str2)
{
	return strcmp(*(char**)str1, *(char**)str2);
}