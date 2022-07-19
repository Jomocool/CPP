#include"Mystring.h"

Mystring::Mystring()//empty string constructor (default constructor)
	:p_Str(NULL), str_Length(0){}

Mystring::Mystring(const Mystring& str)//copy constructor
{
	this->str_Length = str.length();
	this->p_Str = new char[this->str_Length + 1];
	my_strcpy(this->p_Str, str.p_Str);
}

Mystring::Mystring(const Mystring&str, size_t pos,size_t t_Len)//substring constructor
{
	char* p1 = str.c_str() + pos;
	char* p2 = p1;
	size_t len = validLength(p1, t_Len);

	this->str_Length = len;
	this->p_Str = new char[this->str_Length + 1];
	char* p3 = this->p_Str;

	if (p2 != NULL)
	{
		while (len--)
		{
			*(p3++) = *(p2++);
		}
	}
}

Mystring::Mystring(const char* s)//from c-string
{
	this->str_Length =my_strlen(s);
	this->p_Str = new char[this->str_Length + 1];
	this->p_Str = my_strcpy(this->p_Str, s);
}

Mystring::Mystring(const char* s, size_t n)//from buffer
{
	const char* p1 = s;
	size_t len = validLength(s, n);

	this->str_Length = len;
	this->p_Str = new char[this->str_Length + 1];
	char* p2 = this->p_Str;

	while (len--)
	{
		*(p2++) = *(p1++);
	}
}

Mystring::Mystring(size_t n, char c)//fill constructor
{
	this->str_Length = n;
	this->p_Str = new char[this->str_Length + 1];
	char* p = this->p_Str;
	while (n--)
	{
		*(p++) = c;
	}
}

Mystring::~Mystring()//destructor
{
	if (this->p_Str != NULL)
	{
		delete[] this->p_Str;
		this->p_Str = NULL;
	}
	this->str_Length = 0;
}

Mystring& Mystring::operator=(const Mystring& str)// String assignment 
{
	if (this->p_Str == str.c_str())
	{
		return *this;
	}
	this->str_Length = str.length();
	this->p_Str = new char[this->str_Length + 1];
	this->p_Str=my_strcpy(this->p_Str, str.p_Str);
	return *this;

}

char& Mystring::operator[](size_t pos)//Get character of string
{
	return *(this->p_Str+pos);
}

Mystring& Mystring::operator+=(const Mystring& str)//Append to string from string
{
	my_strcat(this->p_Str, str.c_str());
	this->str_Length += str.length();
	return *this;
}

Mystring& Mystring::operator+=(const char* s)//Append to string from c-string
{
	this->p_Str=my_strcat(this->p_Str, s);
	this->str_Length += my_strlen(s);
	return *this;
}

Mystring& Mystring::operator+=(char c)//Append to string from character
{
	if (this->p_Str == NULL)
	{
		this->p_Str = new char[2];
		this->str_Length = 2;
		*this->p_Str = c;
		return *this;
	}

	else
	{
		char* p1 = this->p_Str;
		this->p_Str = new char[this->str_Length + 2];
		this->str_Length = this->str_Length;
		char* p2 = this->p_Str;

		while (*p1 != '\0')
		{
			*(p2++) = *(p1++);
		}

		*(p2++) = c;
		*p2 = '\0';

		return *this;
	}
}

Mystring& Mystring::append(const Mystring& str)//Append to string from string
{
	*this += str;
	return *this;
}

Mystring& Mystring::append(const Mystring& str, size_t pos, size_t t_len)//Append to string from substring
{
	char* p = str.c_str() + pos;
	size_t len1 = this->str_Length;
	this->p_Str=my_strncat(this->p_Str, p, t_len);
	size_t len2 = validLength(p,t_len);
	this->str_Length = len1 + len2;

	return *this;
}

Mystring& Mystring::append(const char* s)//Append to string from c-string
{
	size_t len1 = this->str_Length;
	size_t len2 = my_strlen(s);

	this->p_Str = my_strcat(this->p_Str, s);
	this->str_Length = len1 + len2;
	return *this;
}

Mystring& Mystring::append(const char* s, size_t t_len)//Append to string from buffer
{
	size_t len1 = this->str_Length;
	size_t len2 = validLength(s,t_len);
	this->str_Length = len1 + len2;
	this->p_Str = my_strncat(this->p_Str, s, t_len);
	return *this;
}

Mystring& Mystring::append(size_t n, char c)//Append to string by filling
{
	size_t len = this->str_Length;
	for (size_t i = 0; i < n; i++)
	{
		*this += c;
	}
	this->str_Length = len + n;
	return *this;
}

template<class InputIterator>
Mystring& Mystring::append(InputIterator first, InputIterator last)//Append to string from range
{
	size_t t_len = last - first;
	size_t len = this->str_Length;
	this->p_Str = my_strncat(this->p_Str, first, t_len);
	this->str_Length = len + t_len;
	return *this;
}

void Mystring::push_back(char c)//Append character to string
{
	size_t len = this->str_Length;
	*this += c;
	this->str_Length = len + 1;
}

Mystring& Mystring::assign(const Mystring& str)//Copies str
{
	this->p_Str = my_strcpy(this->p_Str, str.c_str());
	this->str_Length = str.length();
	return *this;
}

Mystring& Mystring::assign(const Mystring& str, size_t pos, size_t t_len)//Copies the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is string::npos).
{
	char* p = str.c_str() + pos;
	this->p_Str = my_strncpy(this->p_Str, p, t_len);
	size_t len = validLength(p,t_len);
	this->str_Length = len;
	return *this;
}

Mystring& Mystring::assign(const char* s)//Copies the null-terminated character sequence (C-string) pointed by s.
{
	this->p_Str = my_strcpy(this->p_Str, s);
	size_t len =my_strlen(s);
	this->str_Length = len;
	return *this;
}

Mystring& Mystring::assign(const char* s, size_t t_len)//copies the first n characters from the array of characters pointed by s.
{
	this->p_Str = my_strncpy(this->p_Str, s, t_len);
	this->str_Length = validLength(s, t_len);
	return *this;
}

Mystring& Mystring::assign(size_t n, char c)//Replaces the current value by n consecutive copies of character c.
{
	this->p_Str = new char[n + 1];
	this->str_Length = n;
	char* p = this->p_Str;
	while (n--)
	{
		*(p++) = c;
	}
	return *this;
}

template<class InputIterator>
Mystring& Mystring::assign(InputIterator first, InputIterator last)//Copies the sequence of characters in the range [first,last), in the same order.
{
	size_t len = last - first;
	this->p_Str = my_strncpy(this->p_Str, first, len);
	this->str_Length = len;
	return*this;
}

Mystring& Mystring::insert(size_t pos, const Mystring& str)//Inserts a copy of str.
{
	Mystring s(*this, 0, pos+1);
	char* p1 = this->p_Str + pos+1;
	char* p2 = my_strcat(s.c_str(), str.c_str());
	this->p_Str = my_strcat(p2, p1);
	this->str_Length += str.length();
	return *this;
}

Mystring& Mystring::insert(size_t pos1, const Mystring& str, size_t pos2, size_t t_len)//Inserts a copy of a substring of str. The substring is the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is npos).
{
	Mystring s(*this, 0, pos1 + 1);
	char* p1 = this->p_Str + pos1 + 1;
	char* p2 = str.c_str() + pos2;
	char* p3 = my_strncat(s.c_str(), p2, t_len);
	this->p_Str = my_strcat(p3, p1);
	this->str_Length += t_len;
	return *this;
}

Mystring& Mystring::insert(size_t pos, const char* s)//Inserts a copy of the string formed by the null-terminated character sequence (C-string) pointed by s.
{
	Mystring str(*this, 0, pos + 1);
	char* p1 = this->p_Str + pos + 1;
	char* p2 = my_strcat(str.c_str(), s);
	this->p_Str = my_strcat(p2, p1);
	this->str_Length += my_strlen(s);
	return *this;
}

Mystring& Mystring::insert(size_t pos, const char* s, size_t t_len)//Inserts a copy of the first n characters in the array of characters pointed by s.
{
	Mystring str(*this, 0, pos + 1);
	char* p1 = this->p_Str+pos + 1;
	char* p2 = my_strncat(str.c_str(), s, t_len);
	this->p_Str = my_strcat(p2, p1);
	this->str_Length += t_len;
	return*this;
}

Mystring& Mystring::insert(size_t pos, size_t n, char c)//Inserts n consecutive copies of character c.
{
	Mystring s1(*this, 0, pos + 1);
	Mystring s2(n, c);
	char* p1 = this->p_Str+pos + 1;
	char* p2 = my_strcat(s1.c_str(), s2.c_str());
	this->p_Str = my_strcat(p2, p1);
	this->str_Length += n;
	return *this;
}

Mystring& Mystring::insert(size_t pos, char c)//Inserts character c.
{
	*this = this->insert(pos, 1, c);
	return *this;
}


template<class InputIterator>
Mystring& Mystring::insert(size_t pos,InputIterator first, InputIterator last)//Inserts a copy of the sequence of characters in the range[first, last), in the same order.
{
	size_t len = last - first;
	*this = this->insert(pos, first, len);
	this->str_Length += len;
	return *this;
}

Mystring& Mystring:: erase(size_t pos, size_t t_len)//Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
{
	Mystring s(*this, 0, pos);
	char* p1 = this->p_Str + pos + t_len;
	this->p_Str = my_strcat(s.c_str(), p1);
	this->str_Length -= t_len;
	return *this;
}

Mystring& Mystring::erase(size_t pos)//Erases the character pointed by p.
{
	*this = this->erase(pos, 1);
	return *this;
}

Mystring& Mystring::replace(size_t pos, size_t t_len, const Mystring& str)//Copies str.
{
	*this = this->erase(pos, t_len);
	*this = this->insert(pos, str.c_str());
	return *this;
}

Mystring& Mystring::replace(size_t pos1, size_t len1, const Mystring& str, size_t pos2, size_t len2)//Copies the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is string::npos).
{
	*this = this->erase(pos1, len1);
	*this = this->insert(pos1, str.c_str()+pos2, len2);
	return *this;
}

Mystring& Mystring::replace(size_t pos, size_t t_len, const char* s)//Copies the null-terminated character sequence (C-string) pointed by s.
{
	*this = this->erase(pos, t_len);
	*this = this->insert(pos, s);
	return *this;
}

Mystring& Mystring::replace(size_t pos, size_t t_len1, const char* s, size_t t_len2)//Copies the first n characters from the array of characters pointed by s.
{
	*this = this->erase(pos, t_len1);
	*this = this->insert(pos, s, t_len2);
	return *this;
}

Mystring& Mystring::replace(size_t pos, size_t t_len1, size_t t_len2, char c)//Replaces the portion of the string by n consecutive copies of character c.
{
	*this = this->erase(pos, t_len1);
	*this = this->insert(pos, t_len2, c);
	return *this;
}

template<class InputIterator>
Mystring& Mystring::replace(size_t pos1, size_t pos2, InputIterator first, InputIterator last)//Copies the sequence of characters in the range [first,last), in the same order.
{
	size_t len1 = pos2 - pos1 + 1;
	*this = this->erase(pos1, len1);
	size_t len2 = last - first+1;
	*this = this->insert(pos1, first, len2);
	return *this;
}

void Mystring::swap(Mystring& str)//Exchanges the content of the container by the content of str, which is another string object. Lengths may differ.
{
	if (this->p_Str == str.c_str())
	{
		return;
	}
	char* temp_p = this->p_Str;
	size_t temp_len = this->str_Length;
	this->p_Str = str.c_str();
	this->str_Length = str.length();
	str.p_Str = temp_p;
	str.str_Length = temp_len;
}

void Mystring::pop_back()//Erases the last character of the string, effectively reducing its length by one.
{
	*this = this->erase(this->str_Length, 1);
}

const char* Mystring::data()const//Returns a pointer to an array that contains the same sequence of characters as the characters that make up the value of the string object.
{
	return this->p_Str;
}

size_t Mystring::copy(char* s, size_t t_len, size_t pos=0)//Copies a substring of the current value of the string object into the array pointed by s. This substring contains the len characters that start at position pos.
{
	if (this->str_Length == 0)
	{
		return 0;
	}
	char* p = this->p_Str + pos;
	size_t len = t_len;
	while (len-- && *p != '\0')
	{
		*(s++) = *(p++);
	}
	return t_len + 1;
}

size_t Mystring::find(const Mystring& str, size_t pos = 0)const//Searches the string for the first occurrence of the sequence specified by its arguments.
{
	char* p_t = this->p_Str + pos;
	char* p_Last = this->p_Str + this->str_Length;
	while (str.length() <= (size_t)(p_Last - p_t+1)&&*p_t!='\0')
	{
		char* p1 = p_t++;
		char* p_s = str.c_str();
		size_t count = str.length();
		while(*(p1++) == *(p_s++))
		{
			count--;
			if (count == 0)
			{
				return (p_t - this->p_Str);
			}
		}
	}
	return 4294967295;
}

size_t Mystring::find(const char* s, size_t pos = 0)const//Searches the string for the first occurrence of the sequence specified by its arguments.
{
	char* p_t = this->p_Str + pos;
	char* p_Last = this->p_Str + this->str_Length;
	while (my_strlen(s) <= (size_t)(p_Last - p_t+1) && *p_t != '\0')
	{
		char* p1 = p_t;
		const char* p2 = s;
		size_t count = my_strlen(s);
		while (*(p1++) == *(p2++))
		{
			count--;
			if (count == 0)
			{
				return (p_t - this->p_Str);
			}
		}
		p_t++;
	}
	return 4294967295;
}

size_t Mystring::find(const char* s, size_t pos, size_t t_len)const//Searches the string for the first occurrence of the sequence specified by its arguments.
{
	char* p_t = this->p_Str + pos;
	char* p_Last = p_t+t_len;
	while (my_strlen(s) <= (size_t)(p_Last - p_t+1) &&*p_t!='\0')
	{
		char* p1 = p_t++;
		const char* p2 = s;
		size_t count = t_len;
		while (*(p1++) == *(p2++))
		{
			count--;
			if (count == 0)
			{
				return (p1 - this->p_Str - 1);
			}
		}
	}
	return 4294967295;
}

size_t Mystring::find(char c, size_t pos = 0)const//Searches the string for the first occurrence of the sequence specified by its arguments.
{
	char* p_t = this->p_Str + pos;
	char* p_Last = this->p_Str + this->str_Length;
	while (*p_t != '\0')
	{
		if (*p_t == c)
		{
			return p_t - this->p_Str;
		}
		p_t ++ ;
	}
	return 4294967295;
}

size_t Mystring::rfind(const Mystring& str, size_t pos)const//Searches the string for the last occurrence of the sequence specified by its arguments.
{
	size_t t_pos1 = 0;
	size_t t_pos2 = 0;
	while (t_pos1 != 4294967295 && t_pos1 < pos)
	{
		t_pos1 = this->find(str,t_pos1+1);
		if (t_pos1 == 4294967295 || t_pos1 >= pos)return t_pos2;
		t_pos2 = t_pos1;
	}
	return 4294967295;
}

size_t Mystring::rfind(const char* s, size_t pos)const//Searches the string for the last occurrence of the sequence specified by its arguments.
{
	size_t t_pos1 = 0;
	size_t t_pos2 = 0;
	while (t_pos1 != 4294967295 && t_pos1 < pos)
	{
		t_pos1 = this->find(s, t_pos1 + 1);
		if (t_pos1 == 4294967295 || t_pos1 >= pos)return t_pos2;
		t_pos2 = t_pos1;
	}
	return 4294967295;
}

size_t Mystring::rfind(const char* s, size_t pos, size_t t_len)const//Searches the string for the last occurrence of the sequence specified by its arguments.
{
	size_t t_pos1 = 0;
	size_t t_pos2 = 0;
	while (t_pos1 != 4294967295 && t_pos1 < pos)
	{
		t_pos1 = this->find(s, t_pos1 + 1,t_len);
		if (t_pos1 == 4294967295 || t_pos1 >= pos)return t_pos2;
		t_pos2 = t_pos1;
	}
	return 4294967295;
}

size_t Mystring::rfind(char c, size_t pos)const//Searches the string for the last occurrence of the sequence specified by its arguments.
{
	size_t t_pos1 = 0;
	size_t t_pos2 = 0;
	while (t_pos1 != 4294967295 && t_pos1 < pos)
	{
		t_pos1 = this->find(c, t_pos1 + 1);
		if (t_pos1 == 4294967295 || t_pos1 >= pos)return t_pos2;
		t_pos2 = t_pos1;
	}
	return 4294967295;
}

size_t Mystring::find_first_of(const Mystring&str)const//Searches the string for the first character that matches any of the characters specified in its arguments.
{
	return this->find(str, 0);
}

size_t Mystring::find_first_of(const char*s)const//Searches the string for the first character that matches any of the characters specified in its arguments.
{
	return this->find(s, 0);
}

size_t Mystring::find_first_of(const char*s, size_t t_len)const//Searches the string for the first character that matches any of the characters specified in its arguments.
{
	return this->find(s, 0, t_len);
}

size_t Mystring::find_first_of(char c)const//Searches the string for the first character that matches any of the characters specified in its arguments.
{
	return this->find(c, 0);
}

size_t Mystring::find_last_of(const Mystring&str)const//Searches the string for the last character that matches any of the characters specified in its arguments.
{
	return this->rfind(str, this->str_Length);
}

size_t Mystring::find_last_of(const char*s)const//Searches the string for the last character that matches any of the characters specified in its arguments.
{
	return this->rfind(s, this->str_Length);
}

size_t Mystring::find_last_of(const char*s, size_t t_len)const//Searches the string for the last character that matches any of the characters specified in its arguments.
{
	return this->rfind(s,this->str_Length, t_len);
}

size_t Mystring::find_last_of(char c)const//Searches the string for the last character that matches any of the characters specified in its arguments.
{
	return this->rfind(c, this->str_Length);
}

size_t Mystring::find_first_not_of(const Mystring&str)const//Searches the string for the first character that does not match any of the characters specified in its arguments.
{
	char* p1 = this->p_Str;
	while (*p1 != '\0')
	{
		size_t count = str.length();
		char* p2 = str.c_str();
		while (*p1 == *p2)
		{
			count--;
			if (count == 0)
			{
				return p1 - this->p_Str;
			}
			p2++;
		}
		p1++;
	}
	return 4294967295;
}

size_t Mystring::find_first_not_of(const char* s)const//Searches the string for the first character that does not match any of the characters specified in its arguments.
{
	char* p1 = this->p_Str;
	while (*p1 != '\0')
	{
		size_t count = my_strlen(s);
		const char* p2 = s;
		while (*p1 == *p2)
		{
			count--;
			if (count == 0)
			{
				return p1 - this->p_Str;
			}
			p2++;
		}
		p1++;
	}
	return 4294967295;
}

size_t Mystring::find_first_not_of(const char* s, size_t t_len)const//Searches the string for the first character that does not match any of the characters specified in its arguments.
{
	char* p1 = this->p_Str;
	while (*p1 != '\0'&&t_len--)
	{
		size_t count = my_strlen(s);
		const char* p2 = s;
		while (*p1 == *p2)
		{
			count--;
			if (count == 0)
			{
				return p1 - this->p_Str;
			}
			p2++;
		}
		p1++;
	}
	return 4294967295;
}

size_t Mystring::find_first_not_of(char c)const//Searches the string for the first character that does not match any of the characters specified in its arguments.
{
	char*p = this->p_Str;
	while (*p != '\0')
	{
		if (*p != c)
		{
			return p - this->p_Str;
		}
		p++;
	}
	return 4294967295;
}

size_t Mystring::find_last_not_of(const Mystring& str)const//Searches the string for the last character that does not match any of the characters specified in its arguments.
{
	char* p_last = this->p_Str + this->str_Length;
	while (p_last != this->p_Str)
	{
		size_t count = str.length();
		char* p1 = p_last;
		char* p2 = str.c_str();
		while (*(p1--) != *(p2++))
		{
			count--;
			if (count == 0)
			{
				return p_last - this->p_Str;
			}
		}
		p_last--;
	}
	return 4294967295;
}

size_t Mystring::find_last_not_of(const char* s)const//Searches the string for the last character that does not match any of the characters specified in its arguments.
{
	char* p_last = this->p_Str + this->str_Length;
	while (p_last != this->p_Str)
	{
		size_t count =my_strlen(s);
		char* p1 = p_last;
		const char* p2 = s;
		while (*(p1--) != *(p2++))
		{
			count--;
			if (count == 0)
			{
				return p_last - this->p_Str;
			}
		}
		p_last--;
	}
	return 4294967295;
}

size_t Mystring::find_last_not_of(const char* s, size_t t_len)const//Searches the string for the last character that does not match any of the characters specified in its arguments.
{
	char* p_last = this->p_Str + this->str_Length;
	while (p_last != this->p_Str && t_len)
	{
		size_t count = my_strlen(s);
		char* p1 = p_last;
		const char* p2 = s;
		while (*(p1--) != *(p2++))
		{
			count--;
			if (count == 0)
			{
				return p_last - this->p_Str;
			}
		}
		p_last--;
		t_len--;
	}
	return 4294967295;
}

size_t Mystring::find_last_not_of(char c)const//Searches the string for the last character that does not match any of the characters specified in its arguments.
{
	char* p_last = this->p_Str + this->str_Length;
	while (p_last != this->p_Str)
	{
		if (*p_last != c)
		{
			return p_last - this->p_Str;
		}
		p_last--;
	}
	return 4294967295;
}

Mystring Mystring::substr(size_t pos1=0, size_t pos2= 4294967295)//4294967295
{
	Mystring s(*this, pos1, pos2 - pos1 + 1);
	return s;
}

int Mystring::compare(const Mystring& str)const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	return my_strcmp(this->p_Str, str.c_str());
}

int Mystring::compare(size_t pos, size_t t_len, const Mystring& str)const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	char* p = this->p_Str + pos;
	return -my_strncmp(str.c_str(), p, t_len);
}

int Mystring::compare(size_t pos1, size_t t_len1, const Mystring&str, size_t pos2, size_t t_len2) const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	char* p1 = this->p_Str + pos1;
	Mystring s1(p1, t_len1);
	char* p2 = str.c_str() + pos2;
	Mystring s2(p2, t_len2);
	return my_strcmp(s1.c_str(), s2.c_str());
}

int Mystring::compare(const char*s) const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	return my_strcmp(this->p_Str, s);
}

int Mystring::compare(size_t pos, size_t t_len, const char*s) const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	char* p = this->p_Str + pos;
	Mystring str(p, t_len);
	return my_strcmp(str.c_str(), s);
}

int Mystring::compare(size_t pos, size_t t_len1, const char*s, size_t t_len2) const//Compares the value of the string object (or a substring) to the sequence of characters specified by its arguments.
{
	char* p = this->p_Str + pos;
	Mystring s1(p, t_len1);
	Mystring s2(s, t_len2);
	return my_strcmp(s1.c_str(), s2.c_str());
}

char* my_strcpy(char* dst, const char* src)//Copy string
{

	if (src == NULL)
	{
		return (char*)src;
	}

	char* ret = dst;
	my_memcpy(dst, src, my_strlen(src)+1);
	return ret;
}

void* my_memcpy(void* dst, const void* src, size_t t_len)//Copy block of memory 
{
	if (dst == src||src==NULL)
	{
		return (void*)src;
	}

	char* p_dst1 = (char*)dst;
	char* p_src1 = (char*)src;
	char* p_src2 = p_src1;

	size_t len = validLength(p_src1,t_len);

	size_t sLength = my_strlen((char*)dst-1)+1;
	dst = new char[sLength + len + 1];

	char* p_dst2 = (char*)dst;

	if (p_dst1 != NULL)
	{
		while (sLength--)
		{
			*(p_dst2++) = *(p_dst1++);
		}
	}

	if (src <= dst && (char*)dst <= (char*)src + len - 1)
	{
		p_dst2 = (char*)dst + len - 1;
		p_src2 = (char*)src + len - 1;
		while (len--)
		{
			*(p_dst2--) = *(p_src2--);
		}
		*p_dst2 = '\0';
	}
	else
	{
		while (len--)
		{
			*(p_dst2++) = *(p_src2++);
		}
		*p_dst2 = '\0';
	}
	return dst;
}

void* my_memmove(void* dst, const void* src, size_t t_len)//Move block of memory
{
	if (dst == src||src==NULL)
	{
		return (void*)src;
	}

	char* p_dst1 = (char*)dst;
	char* p_src1 = (char*)src;
	char* p_src2 = p_src1;

	size_t len = validLength(p_src1,t_len);

	size_t sLength = my_strlen((char*)dst);
	dst = new char[sLength + len + 1];

	char* p_dst2 = (char*)dst;

	while (sLength--)
	{
		*(p_dst2++) = *(p_dst1++);
	}

	if (src <= dst && (char*)dst <= (char*)src + len - 1)
	{
		p_dst2 = (char*)dst + len - 1;
		p_src2 = (char*)src + len - 1;
		while (len--)
		{
			*(p_dst2--) = *(p_src2--);
		}
		*p_dst2 = '\0';
	}
	else
	{
		while (len--)
		{
			*(p_dst2++) = *(p_src2++);
		}
		*p_dst2 = '\0';
	}
	return dst;
}

char* my_strncpy(char* dst, const char* src, size_t t_len)//Copy characters from string
{
	if (dst == src || src == NULL)
	{
		return (char*)src;
	}

	char* p_dst1 = dst;
	const char* p_src1 = src;
	const char* p_src2 = p_src1;

	size_t len = validLength(p_src1,t_len);

	size_t sLength = my_strlen(src);
	dst = new char[sLength + len + 1];

	char* p_dst2 = dst;

	while (sLength--)
	{
		*(p_dst2++) = *(p_dst1++);
	}

	if (src <= dst && (char*)dst <= (char*)src + len - 1)
	{
		p_dst2 = (char*)dst + len - 1;
		p_src2 = (char*)src + len - 1;
		while (len--)
		{
			*(p_dst2--) = *(p_src2--);
		}
		*p_dst2 = '\0';
	}
	else
	{
		while (len--)
		{
			*(p_dst2++) = *(p_src2++);
		}
		*p_dst2 = '\0';
	}
	return dst;
}

char* my_strcat(char* dst, const char*src )//Concatenate strings
{
	if (src == NULL);
	{
		return dst;
	}

	char* p_dst1 = dst;
	size_t sLength = my_strlen(dst);
	dst = new char[sLength + my_strlen(src)+1];
	char* p_dst2 = dst;

	while (sLength--)
	{
		*(p_dst2++) = *(p_dst1++);
	}

	while (*src != '\0')
	{
		*(p_dst2++) = *(src++);
	}

	*p_dst2 = '\0';

	return dst;
}

char* my_strncat(char* dst, const char* src, size_t t_len)//Append characters from string
{
	if (src==NULL)
	{
		return dst;
	}

	char* p_dst1 = dst;
	const char* p_src1 = src;
	size_t len = validLength(p_src1,t_len);

	size_t sLength = my_strlen(dst);
	dst = new char[sLength + len + 1];
	char* p_dst2 = dst;

	while (sLength--)
	{
		*(p_dst2++) = *(p_dst1++);
	}

	while (len--)
	{
		*(p_dst2++) = *(src++);
	}

	*p_dst2 = '\0';

	return dst;
}

int my_memcmp(const void* dst, const void* src, size_t t_len)//Compare two blocks of memory
{
	char* p_dst = (char*)dst;
	char* p_src = (char*)src;

	while (t_len--)
	{
		if (*p_dst > *p_src||src==NULL)
		{
			return 1;
		}
		else if (*p_dst > *p_src||dst==NULL)
		{
			return -1;
		}
		p_dst++;
		p_src++;
	}

	return 0;
}

int my_strcmp(const char* dst, const char* src)//Compare two strings 
{
	if (dst == NULL && src != NULL)return -1;
	if (dst != NULL && src == NULL)return 1;
	if (dst == NULL && src == NULL)return 0;

	while (*(dst++) != '\0' && *(src++) != '\0')
	{
		if (*dst > *src)
		{
			return 1;
		}
		else if (*dst < *src)
		{
			return -1;
		}
	}

	return 0;
}

int my_strcoll(const char* dst, const char* src)//Compare two strings using locale
{
	if (dst == NULL && src != NULL)return -1;
	if (dst != NULL && src == NULL)return 1;
	if (dst == NULL && src == NULL)return 0;

	setlocale(LC_ALL, "zh-CN");
	while (*(dst++) != '\0' && *(src++) != '\0')
	{
		if (*dst > *src)
		{
			return 1;
		}
		else if (*dst < *src)
		{
			return -1;
		}
	}
	return 0;
}

int my_strncmp(const char* dst, const char* src, size_t t_len)//Compare characters of two strings

{
	if (dst == NULL && src != NULL)return -1;
	if (dst != NULL && src == NULL)return 1;
	if (dst == NULL && src == NULL)return 0;

	while (t_len--)
	{
		if (*dst < *src)
		{
			return -1;
		}
		else if (*dst > *src)
		{
			return 1;
		}
		dst++;
		src++;
	}
	return 0;
}

size_t my_strxfrm(char* dst, const char* src, size_t t_len)//Transform string using locale 
{
	const char* p_src = src;
	while (*src)
	{
		if (t_len > 1)
		{
			t_len--;
			*(dst++) = *(src++);
		}
		else
		{
			src++;
		}
	}
	*(dst++) = '\0';
	return src - p_src;
}

void* my_memchr(void* buf, int value, size_t t_len)//Locate character in block of memory
{
	while (t_len--)
	{
		if (*(char*)buf == value)
		{
			return (void*)buf;
			buf = (char*)buf + 1;
		}
	}
	return NULL;
}

char* my_strchr(char* buf, int c)//Locate first occurrence of character in string
{
	while (*(buf++))
	{
		if (*buf == c)
		{
			return buf;
		}
	}
	return NULL;
}

size_t my_strcspn(const char* dst, const char* src)//Get span until character in string
{
	char* p_dst = (char*)dst;
	char* p_src = NULL;
	while (*dst != '\0')
	{
		p_src = (char*)src;
		while (*p_src != '\0')
		{
			if (*dst == *p_src)
			{
				return p_dst - dst;
			}
			p_src++;
		}
		dst++;
	}
	return p_dst - dst;
}

char* my_strpbrk(char* dst, const char* src)//Locate characters in string 
{
	while (*dst != '\0')
	{
		char* p_src = (char*)src;
		while (*p_src != '\0')
		{
			if (*p_src == *dst)
			{
				return dst;
			}
			p_src++;
		}
		dst++;
	}
	return NULL;
}

char* my_strrchr(char* buf, int c)//Locate last occurrence of character in string
{
	char* s1 = NULL;
	char* s2 = NULL;
	s1 = my_strchr(buf, c);
	while (s1 != NULL)
	{
		s2 = my_strchr(s1 + 1, c);
		if (s2 != NULL)
		{
			s1 = s2;
		}
		else
		{
			return s1;
		}
	}
	return NULL;
}

size_t my_strspn(const char* dst, const char* src)//Get span of character set in string 
{
	const char* p_dst = NULL;
	const char* p_src = NULL;
	size_t count = 0;
	while (*dst != '\0')
	{
		p_src = src;
		while (*p_src != '\0')
		{
			if (*dst == *p_src)
			{
				count++;
				break;
			}
		}
		dst++;
	}
	return count;
}

char* my_strstr(char* dst, const char* src)//Locate substring 
{
	size_t d_Len = my_strlen(dst);
	size_t s_Len = my_strlen(src);
	if (s_Len < 1)
	{
		return dst;
	}

	for (int i = 0; i < d_Len; i++)
	{
		if (d_Len - i < s_Len)
		{
			return NULL;
		}
		size_t countD = i;
		size_t countS = 0;
		while (dst[countD++] == src[countS++])
		{
			if (countS == s_Len)
			{
				return dst + i;
			}
		}
	}
	return NULL;
}

char* my_strtok(char* dst, const char* src)//Split string into tokens
{
	static size_t sz1 = NULL;
	static size_t count = NULL;
	static char* s1 = NULL;
	static char* s2 = NULL;
	size_t sz = 0;
	if (dst != NULL)//first time
	{
		sz1 = my_strlen(dst);//calculate the number of dst
		s2 = dst;//record the initial address
		sz = my_strlen(src);
		for (*dst; *dst != '\0'; dst++)
		{
			for (size_t i = 0; i < sz; i++)
			{
				if (i == 0)
				{
					count++;
				}
				if (*dst == *(src + i))
				{
					*dst = 0;
					s1 = dst;
					return s2;
				}
			}
		}
	}
	else
	{
		s2 = s1 + 1;
		dst = s2;
		sz =my_strlen(src);
		for (*dst; *dst != '\0'; dst++)
		{
			for (size_t i = 0; i < sz; i++)
			{
				if (i == 0)
				{
					count++;
				}
				if (*dst == *(src + i))
				{
					*dst = 0;
					s1 = dst;
					return s2;
				}
			}
		}
		if (count > sz1)
		{
			return NULL;
		}
		return s2;
	}
	return NULL;
}

void* my_memset(void* ptr, int value, size_t num)//Fill block of memory 
{
	char* p = (char*)ptr;

	while (num--)
	{
		*(p++) = value;
	}
	return (void*)ptr;
}

const char* my_strerror(int errnum)//Get pointer to error message string
{
	const char* s0 = "Success";
	const char* s1 = "Operation not permitted";
	const char* s2 = "No such file or directory";
	const char* s3 = "No such process";
	const char* s4 = "Interrupted system call";
	const char* s5 = "Input/output error";
	const char* s6 = "Device not configured";
	const char* s7 = "Argument list too long";
	const char* s8 = "Exec format error";
	const char* s9 = "Bad file descripto";
	switch (errnum)
	{
	case 0:
		return s0;
	case 1:
		return s1;
	case 2:
		return s2;
	case 3:
		return s3;
	case 4:
		return s4;
	case 5:
		return s5;
	case 6:
		return s6;
	case 7:
		return s7;
	case 8:
		return s8;
	case 9:
		return s9;
	}
	return NULL;
}

void Mystring::resize(size_t n)//Resize string(substract)
{
	if (n == this->str_Length)
	{
		return;
	}

	else if (n > this->str_Length)
	{
		this->resize(n, ' ');
	}
	else
	{
		char* p1 = this->p_Str;
		char* p2 = p1;
		this->p_Str = new char[n + 1];
		this->str_Length = n;
		char* p3 = this->p_Str;
		while (n--)
		{
			*(p3++) = *(p1++);
		}
		*p3 = '\0';
	}
}

void Mystring::resize(size_t n, char c)//Resize string(append)
{
	if (n == this->str_Length)
	{
		return;
	}

	else if (n < this->str_Length)
	{
		this->resize(n);
	}

	else
	{
		char* p1 = this->p_Str;

		size_t len1 = this->str_Length;
		size_t len2 = n - len1;

		this->p_Str = new char[n + 1];
		this->str_Length = n;
		char* p3 = this->p_Str;

		while (len1--)
		{
			*(p3++) = *(p1++);
		}

		while (len2--)
		{
			*(p3++) = c;
		}

		*p3 = '\0';
	}
}

size_t Mystring::size()const//Get string size
{
	return this->str_Length;
}

size_t Mystring::length()const//Get string length
{
	return this->str_Length;
}

void Mystring::clear()//Clear string
{
	delete[]this->p_Str;
	this->p_Str = NULL;
	this->str_Length = 0;
}

bool Mystring::empty()//Test if string is empty
{
	return (this->p_Str == NULL);
}

char& Mystring::at(size_t pos)//Get character in string 
{
	return *(this->p_Str + pos);
}

char& Mystring::back()//Access last character 
{
	return*(this->p_Str + this->str_Length-1);
}

char& Mystring::front()//Access first character
{
	return *this->p_Str;
}

char* Mystring::c_str()const
{
	return this->p_Str;
}

size_t Mystring::max_size()//Return maximum size of string
{
	size_t maxSize = 4294967291;
	return maxSize;
}

size_t Mystring::capacity()//Return size of allocated storage
{
	if (!this->p_Str)
	{
		return 0;
	}

	size_t len = 0;
	char* p = this->p_Str;
	while (*(p++)!='\0')
	{
		len++;
	}
	return len;
}

void Mystring::reserve(size_t n)//Request a change in capacity 
{
	this->p_Str = new char[n + 1];
}

void Mystring::shrink_to_fit()
{
	Mystring s(this->p_Str);
	this->swap(s);
}

Mystring operator+(const Mystring& str1,const Mystring& str2)//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
{
	char* p = my_strcat(str1.c_str(), str2.c_str());
	Mystring s(p);
	return s;
}

Mystring operator+(const Mystring&str, const char*s)//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
{
	char* p = my_strcat(str.c_str(), s);
	Mystring s_temp(p);
	return s;
}

Mystring operator+(const char*s, const Mystring&str)//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
{
	char* p = my_strcat((char*)s, str.c_str());
	Mystring s_temp(p);
	return s;
}

Mystring operator+(const Mystring&str, char c)//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
{
	char* p1 = &c;
	char* p2 = my_strcat(str.c_str(), p1);
	Mystring s(p2);
	return s;
}

Mystring operator+(char c, const Mystring&str)//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
{
	char* p1 = &c;
	char* p2 = my_strcat(p1,str.c_str());
	Mystring s(p2);
	return s;
}

bool operator==(const Mystring&str1, const Mystring&str2)
{
	return my_strcmp(str1.c_str(), str2.c_str()) == 0;
}

bool operator==(const char*s, const Mystring&str)
{
	return my_strcmp(s,str.c_str()) == 0;
}

bool operator==(const Mystring&str, const char*s)
{
	return my_strcmp(str.c_str(), s) == 0;
}

bool operator!=(const Mystring&str1, const Mystring&str2)
{
	return !(my_strcmp(str1.c_str(), str2.c_str()) == 0);
}

bool operator!=(const char*s, const Mystring&str)
{
	return !(my_strcmp(s, str.c_str()) == 0);
}

bool operator!=(const Mystring&str, const char*s)
{
	return !(my_strcmp(str.c_str(), s) == 0);
}

bool operator<(const Mystring&str1, const Mystring&str2)
{
	return my_strcmp(str1.c_str(), str2.c_str()) == -1;
}

bool operator<(const char*s, const Mystring&str)
{
	return my_strcmp(s, str.c_str()) == -1;
}

bool operator<(const Mystring&str, const char*s)
{
	return my_strcmp(str.c_str(), s) == -1;
}

bool operator<=(const Mystring&str1, const Mystring&str2)
{
	return my_strcmp(str1.c_str(), str2.c_str()) == 0|| my_strcmp(str1.c_str(), str2.c_str()) == -1;
}

bool operator<=(const char*s, const Mystring&str)
{
	return my_strcmp(s, str.c_str()) == 0||my_strcmp(s, str.c_str()) == -1;
}

bool operator<=(const Mystring&str, const char*s)
{
	return my_strcmp(str.c_str(), s) == 0|| my_strcmp(str.c_str(), s) == -1;
}

bool operator>(const Mystring&str1, const Mystring&str2)
{
	return my_strcmp(str1.c_str(), str2.c_str()) == 1;
}

bool operator>(const char*s, const Mystring&str)
{
	return my_strcmp(s, str.c_str()) == 1;
}

bool operator>(const Mystring&str, const char*s)
{
	return my_strcmp(str.c_str(), s) == 1;
}

bool operator>=(const Mystring&str1, const Mystring&str2)
{
	return my_strcmp(str1.c_str(), str2.c_str()) == 0 || my_strcmp(str1.c_str(), str2.c_str()) == 1;
}

bool operator>=(const char*s, const Mystring&str)
{
	return my_strcmp(s, str.c_str()) == 0 || my_strcmp(s, str.c_str()) == 1;
}

bool operator>=(const Mystring&str, const char*s)
{
   return my_strcmp(str.c_str(), s) == 0 || my_strcmp(str.c_str(), s) == -1;
}

void swap(Mystring& str1, Mystring& str2)
{
	char* p_temp = str1.c_str();
	size_t len_temp = str1.length();
	str1.p_Str = str2.p_Str;
	str1.str_Length = str2.str_Length;
	str2.p_Str = p_temp;
	str2.str_Length = len_temp;
}

istream& operator>>(istream& cin, Mystring& str)
{
	cin >> *str.p_Str;
	return cin;
}

ostream& operator<<(ostream& cout, Mystring& str)
{
	cout << str.p_Str;
	return cout;
}

istream& getline(istream& cin, Mystring& str)
{
	cin >> *str.p_Str;
	return cin;
}

int my_stoi(const Mystring&str, size_t* idx = 0, int base = 10)//Convert string to integer
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	size_t len = p1 - p2 + 1;
	int* pc = new int[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	int num = 0;
	int ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

long my_stol(const Mystring& str, size_t* idx = 0, int base = 10)//Convert string to long int
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	size_t len = p1 - p2 + 1;
	long* pc = new long[len];
	long i = 1;
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	long num = 0;
	long ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

size_t my_stoul(const Mystring& str, size_t* idx = 0, int base = 0)//Convert string to unsigned int
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	size_t len = p1 - p2 + 1;
	size_t* pc = new size_t[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	size_t num = 0;
	size_t ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	return num;
}

long long my_stoll(const Mystring& str, size_t* idex = 0, int base = 10)//Convert string to long long
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	long long len = p1 - p2 + 1;
	long long* pc = new long long[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	long long num = 0;
	long long ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

unsigned long long my_stoull(const Mystring&str, size_t*idex=0, int base=10)//Convert string to unsigned long long
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	unsigned long long len = p1 - p2 + 1;
	unsigned long long* pc = new unsigned long long[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	unsigned long long num = 0;
	unsigned long long ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	return num;
}

float my_stof(const Mystring&str, size_t*idex=0, int base=10)//Convert string to float
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (( * p >= '0' && *p <= '9') || *p == '.')
	{
		p++;
	}
	p2 = p - 1;
	char* p_temp = p1;
	while (*p_temp != '.')
	{
		p_temp++;
	}
	size_t dot_pos = p_temp - p1;
	float num = 0;
	float ten = 1;
	size_t dot_pos2 = dot_pos;
	char* p_temp2 = p1 + dot_pos - 1;
	while (dot_pos2--)
	{
		num += *p_temp2 * ten;
		ten *= 10;
	}
	char* p_temp3 = p1 + dot_pos + 1;
	float ten2 = 0.1;
	while (p_temp3 != p2)
	{
		num += *p_temp3 * ten;
		ten2 /= 10;
	}
	float len = p1 - p2 + 1;
	float* pc = new float[len];

	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

double my_stod(const Mystring&str, size_t*idex=0, int base=10)//Convert string to double
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	size_t len = p1 - p2 + 1;
	double* pc = new double[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	double num = 0;
	double ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

long double stold(const Mystring&str, size_t*idex=0, int base=10)//Convert string to long double
{
	if (str.c_str() == NULL)
	{
		return 0;
	}
	char* p = str.c_str();
	char* p1 = NULL;
	char* p2 = NULL;
	while ((*p == ' ' || *p < '0' || *p>'9') && *p != '\0')
	{
		p++;
	}
	if (*p == '\0')
	{
		return 0;
	}
	p1 = p;
	char* star = p;
	while (*p >= '0' && *p <= '9')
	{
		p++;
	}
	p2 = p - 1;
	size_t len = p1 - p2 + 1;
	long double* pc = new long double[len];
	while (*star >= '0' && *star <= '9')
	{
		*pc = *star - 48;
		star++;
		pc++;
	}
	long double num = 0;
	long double ten = 1;
	while (len--)
	{
		pc--;
		num += *pc * ten;
		ten *= 10;
	}
	if (*(p1 - 1) == '-')
	{
		return -num;
	}
	return num;
}

Mystring to_string(int val)//Cnvert int to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	int temp1 = val;
	if (val < 0)
	{
		val = -val;
	}
	int count = 0;
	int temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2/= 10;
	}
	int* p = new int[count];
	int* p_p = p+count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
	if (temp1 < 0)
	{
		Mystring s1((char*)p);
		Mystring s2("-");
		char* ret = my_strcat(s2.c_str(), s1.c_str());
		Mystring s_ret(ret);
		return s_ret;
	}
	else
	{
		Mystring s_ret((char*)p);
		return s_ret;
	}
}

Mystring to_string(long val)//Convart long to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	long temp1 = val;
	if (val < 0)
	{
		val = -val;
	}
	long count = 0;
	long temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2 /= 10;
	}
	long* p = new long[count];
	long* p_p = p + count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
	if (temp1 < 0)
	{
		Mystring s1((char*)p);
		Mystring s2("-");
		char* ret = my_strcat(s2.c_str(), s1.c_str());
		Mystring s_ret(ret);
		return s_ret;
	}
	else
	{
		Mystring s_ret((char*)p);
		return s_ret;
	}
}

Mystring to_string(long long val)//Convert long long to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	long long temp1 = val;
	if (val < 0)
	{
		val = -val;
	}
	long long count = 0;
	long long temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2 /= 10;
	}
	long long* p = new long long[count];
	long long* p_p = p + count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
	if (temp1 < 0)
	{
		Mystring s1((char*)p);
		Mystring s2("-");
		char* ret = my_strcat(s2.c_str(), s1.c_str());
		Mystring s_ret(ret);
		return s_ret;
	}
	else
	{
		Mystring s_ret((char*)p);
		return s_ret;
	}
}

Mystring to_string(unsigned val)//Convert unsigned to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	unsigned count = 0;
	unsigned temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2 /= 10;
	}
	unsigned* p = new unsigned[count];
	unsigned* p_p = p + count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
		Mystring s_ret((char*)p);
		return s_ret;
}

Mystring to_string(unsigned long val)//Convert unsigned long to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	unsigned long count = 0;
	unsigned long temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2 /= 10;
	}
	unsigned long* p = new unsigned long[count];
	unsigned long* p_p = p + count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
	Mystring s_ret((char*)p);
	return s_ret;
}

Mystring to_string(unsigned long long val)//Convert unsigned long long to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	unsigned long long count = 0;
	unsigned long long temp2 = val;
	while (temp2 >= 1)
	{
		count++;
		temp2 /= 10;
	}
	unsigned long long* p = new unsigned long long[count];
	unsigned long long* p_p = p + count;
	while (val >= 1)
	{
		*p_p = val % 10;
		val /= 10;
		p_p--;
	}
	Mystring s_ret((char*)p);
	return s_ret;
}

Mystring to_string(float val)//Convert float to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	float temp1 = val;
	size_t count1 = 0;
	if (val < 0) val = -val;
	float temp2 = (int)val;
	while (temp2 >= 1)
	{
		count1++ ;
		temp2 /= 10;
	}
	size_t count2 = 0;
	while (temp2 - (int)temp2 != 0)
	{
		count2++;
		temp2 *= 10;
	}
	float num = 0;
	if (temp1 < 0)
	{
		float* p = new float[count1 + count2 + 2];
		char* c_p = new char[count1 + count2 + 3];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		float* p1 = p + count1-1;
		float* p2 = p + count1+count2 + 1;
		float temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		*c_p2 = '-';
		c_p2++;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
	else
	{
		float* p = new float[count1 + count2 + 1];
		char* c_p = new char[count1 + count2 + 2];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		float* p1 = p + count1 - 1;
		float* p2 = p + count1 + count2 + 1;
		float temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
}

Mystring to_string(double val)//Convert double to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	double temp1 = val;
	size_t count1 = 0;
	if (val < 0) val = -val;
	double temp2 = (int)val;
	while (temp2 >= 1)
	{
		count1++;
		temp2 /= 10;
	}
	size_t count2 = 0;
	while (temp2 - (int)temp2 != 0)
	{
		count2++;
		temp2 *= 10;
	}
	double num = 0;
	if (temp1 < 0)
	{
		double* p = new double[count1 + count2 + 2];
		char* c_p = new char[count1 + count2 + 3];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		double* p1 = p + count1 - 1;
		double* p2 = p + count1 + count2 + 1;
		double temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		*c_p2 = '-';
		c_p2++;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
	else
	{
		double* p = new double[count1 + count2 + 1];
		char* c_p = new char[count1 + count2 + 2];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		double* p1 = p + count1 - 1;
		double* p2 = p + count1 + count2 + 1;
		double temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
}

Mystring to_string(long double val)//Convert long double to string
{
	if (val == 0)
	{
		return Mystring("0");
	}
	long double temp1 = val;
	size_t count1 = 0;
	if (val < 0) val = -val;
	long double temp2 = (int)val;
	while (temp2 >= 1)
	{
		count1++;
		temp2 /= 10;
	}
	size_t count2 = 0;
	while (temp2 - (int)temp2 != 0)
	{
		count2++;
		temp2 *= 10;
	}
	long double num = 0;
	if (temp1 < 0)
	{
		long double* p = new long double[count1 + count2 + 2];
		char* c_p = new char[count1 + count2 + 3];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		long double* p1 = p + count1 - 1;
		long double* p2 = p + count1 + count2 + 1;
		long double temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		*c_p2 = '-';
		c_p2++;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
	else
	{
		long double* p = new long double[count1 + count2 + 1];
		char* c_p = new char[count1 + count2 + 2];
		size_t c_temp1 = count1;
		size_t c_temp2 = count2;
		long double* p1 = p + count1 - 1;
		long double* p2 = p + count1 + count2 + 1;
		long double temp3 = val;
		while (count1--)
		{
			*p1 = (int)temp3 % 10;
			temp3 /= 10;
			p1--;
		}
		val = val - (int)val;
		for (int i = 0; i < count2; i++)
		{
			val *= 10;
		}
		while (count2--)
		{
			*p2 = (int)val % 10;
			val /= 10;
			p2--;
		}
		char* c_p2 = c_p;
		size_t len = count1 + count2 + 2;
		while (c_temp1--)
		{
			*(c_p2++) = *(p1++);
		}
		const char* dot = ".";
		*(c_p2++) = *(char*)dot;
		while (c_temp2--)
		{
			*(c_p2++) = *(p2++);
		}
		Mystring s_ret("c_p");
		return s_ret;
	}
}



size_t my_strlen(const char* s)
{
	if (s == NULL)
	{
		return 0;
	}

	size_t len = 0;
	while (*s!='\0')
	{
		len++;
		++s;
	}
	return len;
}

size_t validLength(const char* s, size_t t_len)
{
	size_t len = min(my_strlen(s), t_len);
	return len;
}