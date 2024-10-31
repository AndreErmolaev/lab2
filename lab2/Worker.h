#ifndef WORKER_H_
#define WORKER_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class WORKER
{
	char* surname_;
	char* name_;
	char* patronyc_;
	char* post_;
	int year_;
public:
	WORKER();
	WORKER(const char* sur,const char* name,const char* patr,const char* post,int year);
	WORKER(WORKER& copy);
	~WORKER();
	void set_surname(const char* sur);
	void set_name(const char* name);
	void set_patronyc(const char* patr);
	void set_post(const char* post);
	void set_year(int year);
	char* get_surname() const;
	char* get_name() const;
	char* get_patronyc() const;
	char* get_post() const;
	int get_year() const;
	WORKER& operator=(const WORKER& obj);
	class work_exception : public std::exception
	{
		int error_year_;
	public:
		work_exception(int error_year = 2024) { error_year_ = error_year; }
		inline int get_error() const { return error_year_; }
		const char* what() const override { return "!!! ÈÑÊËŞ×ÅÍÈÅ\nÃÎÄ ÍÅ ÌÎÆÅÒ ÁÛÒÜ ÍÅÏÎËÎÆÈÒÅËÜÍÛÌ! Ââåä¸ííîå çíà÷åíèå: "; }
	};
};
inline void WORKER::set_year(int year) { if (year <= 0) throw work_exception(year); year_ = year; }
inline char* WORKER::get_surname() const { return surname_; }
inline char* WORKER::get_name() const { return name_; }
inline char* WORKER::get_patronyc() const { return patronyc_; }
inline char* WORKER::get_post() const { return post_; }
inline int WORKER::get_year() const { return year_; }
std::ostream& operator<<(std::ostream& out, WORKER* obj);
std::istream& operator>>(std::istream& in, WORKER* obj);
void sort_alphabet(WORKER** mas);
#endif
