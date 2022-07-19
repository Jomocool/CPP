#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
using namespace std;

class Mystring
{
public:
	friend istream& operator>>(istream&, Mystring&);
	friend ostream& operator<<(ostream&, Mystring&);
	friend istream& getline(istream&, Mystring&);
	friend void swap(Mystring&, Mystring&);

	Mystring();
	Mystring(const Mystring&);
	Mystring(const Mystring&, size_t, size_t);
	Mystring(const char*);
	Mystring(const char*, size_t);
	Mystring(size_t, char);
	~Mystring();

	Mystring& operator=(const Mystring&);
	char& operator[](size_t);
	Mystring& operator+=(const Mystring&);
	Mystring& operator+=(const char*);
	Mystring& operator+=(char c);

	Mystring& append(const Mystring&);
	Mystring& append(const Mystring&, size_t, size_t);
	Mystring& append(const char*);
	Mystring& append(const char*, size_t);
	Mystring& append(size_t, char);
	template<class InputIterator>
	Mystring& append(InputIterator, InputIterator);
	void push_back(char);
	Mystring& assign(const Mystring&);
	Mystring& assign(const Mystring&, size_t, size_t);
	Mystring& assign(const char*);
	Mystring& assign(const char*, size_t);
	Mystring& assign(size_t, char);
	template<class InputIterator>
	Mystring& assign(InputIterator, InputIterator);
	Mystring& insert(size_t, const Mystring&);
	Mystring& insert(size_t, const Mystring&, size_t, size_t);
	Mystring& insert(size_t, const char*);
	Mystring& insert(size_t, const char*, size_t);
	Mystring& insert(size_t, size_t, char);
	Mystring& insert(size_t, char);
	template<class InputIterator>
	Mystring& insert(size_t,InputIterator, InputIterator);
	Mystring& erase(size_t, size_t);
	Mystring& erase(size_t);
	Mystring& replace(size_t, size_t, const Mystring&);
	Mystring& replace(size_t, size_t, const Mystring&, size_t, size_t);
	Mystring& replace(size_t, size_t, const char*);
	Mystring& replace(size_t, size_t, const char*, size_t);
	Mystring& replace(size_t, size_t, size_t, char);
	template<class InputIterator>
	Mystring& replace(size_t,size_t,InputIterator, InputIterator);
	void swap(Mystring&);
	void pop_back();

	const char* data()const;
	size_t copy(char*, size_t, size_t);
	size_t find(const Mystring&, size_t)const;
	size_t find(const char*, size_t)const;
	size_t find(const char*, size_t, size_t)const;
	size_t find(char c, size_t)const;
	size_t rfind(const Mystring&, size_t)const;
	size_t rfind(const char* s, size_t)const;
	size_t rfind(const char*, size_t, size_t)const;
	size_t rfind(char, size_t)const;
	size_t find_first_of(const Mystring&)const;
	size_t find_first_of(const char*)const;
	size_t find_first_of(const char*, size_t)const;
	size_t find_first_of(char)const;
	size_t find_last_of(const Mystring&)const;
	size_t find_last_of(const char*)const;
	size_t find_last_of(const char*, size_t)const;
	size_t find_last_of(char)const;
	size_t find_first_not_of(const Mystring&)const;
	size_t find_first_not_of(const char*)const;
	size_t find_first_not_of(const char*, size_t)const;
	size_t find_first_not_of(char)const;
	size_t find_last_not_of(const Mystring&)const;
	size_t find_last_not_of(const char*)const;
	size_t find_last_not_of(const char*, size_t)const;
	size_t find_last_not_of(char)const;
	Mystring substr(size_t, size_t);
	int compare(const Mystring&)const;
	int compare(size_t, size_t, const Mystring&)const;
	int compare(size_t, size_t, const Mystring&, size_t, size_t)const;
	int compare(const char*)const;
	int compare(size_t, size_t, const char*)const;
	int compare(size_t, size_t, const char*, size_t)const;

	void resize(size_t);
	void resize(size_t, char);
	void clear();
	bool empty();

	char& at(size_t);
	char& back();
	char& front();

	size_t size()const;
	size_t length()const;
	size_t max_size();
	size_t capacity();
	void reserve(size_t);
	void shrink_to_fit();

	char* c_str()const;

private:
	char* p_Str;
	size_t str_Length;
};

char* my_strcpy(char* dst, const char* src);
void* my_memcpy(void*, const void*, size_t);
void* my_memmove(void*, const void*, size_t);
char* my_strncpy(char*, const char*, size_t);

char* my_strcat(char* dst, const char* src);
char* my_strncat(char* dst, const char* src, size_t t_len);

int my_memcmp(const void* dst, const void* src, size_t t_len);
int my_strcmp(const char* dst, const char* src);
int my_strcoll(const char* dst, const char* src);
int my_strncmp(const char* dst, const char* src, size_t t_len);
size_t my_strxfrm(char* dst, const char* src, size_t t_len);

void* my_memchr(void* buf, int value, size_t t_len);
char* my_strchr(char*, int);

size_t my_strcspn(const char* dst, const char* src);

char* my_strpbrk(char* dst, const char* src);
char* my_strrchr(char* buf, int c);

size_t my_strspn(const char* dst, const char* src);

char* my_strstr(char* dst, const char* src);
char* my_strtok(char* dst, const char* src);

void* my_memset(void* ptr, int value, size_t num);

const char* my_strerror(int errnum);

Mystring operator+(const Mystring&, const Mystring&);
Mystring operator+(const Mystring&, const char*);
Mystring operator+(const char*, const Mystring&);
Mystring operator+(const Mystring&, char);
Mystring operator+(char, const Mystring&);
bool operator== (const Mystring&, const Mystring&);
bool operator== (const char*, const Mystring&);
bool operator== (const Mystring&, const char*);
bool operator!= (const Mystring&, const Mystring&);
bool operator!= (const char*, const Mystring&);
bool operator!= (const Mystring&, const char*);
bool operator<  (const Mystring&, const Mystring&);
bool operator<  (const char*, const Mystring&);
bool operator<  (const Mystring&, const char*);
bool operator<= (const Mystring&, const Mystring&);
bool operator<= (const char*, const Mystring&);
bool operator<= (const Mystring&, const char*);
bool operator>  (const Mystring&, const Mystring&);
bool operator>  (const char*, const Mystring&);
bool operator>  (const Mystring&, const char*);
bool operator>= (const Mystring&, const Mystring&);
bool operator>= (const char*, const Mystring&);
bool operator>= (const Mystring&, const char*);
void swap(Mystring&, Mystring&);
istream& operator>>(istream&, Mystring&);
ostream& operator<<(ostream&, Mystring&);
istream& getline(istream&, Mystring&);

int my_stoi(const Mystring&,size_t*,int);
long my_stol(const Mystring&, size_t*, int);
size_t my_stoul(const Mystring&, size_t*, int);
long long my_stoll(const Mystring&, size_t*, int);
unsigned long long my_stoull(const Mystring&, size_t*, int);
float my_stof(const Mystring&, size_t*, int);
double my_stod(const Mystring&, size_t*, int);
long double stold(const Mystring&, size_t*, int);
Mystring to_string(int);
Mystring to_string(long);
Mystring to_string(long long);
Mystring to_string(unsigned);
Mystring to_string(unsigned long);
Mystring to_string(unsigned long long);
Mystring to_string(float);
Mystring to_string(double);
Mystring to_string(long double);

size_t my_strlen(const char*);

size_t validLength(const char*, size_t);

#endif