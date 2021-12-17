#ifndef CLASS_PERSON
#define CLASS_PERSON

template <class T>
class Person
{
public:
	Person();

	Person(const Person& other) = default;
	Person(Person&& other) = default;

	Person& operator=(const Person& other) = default;
	Person& operator=(Person&& other) = default;

	void setSurname(const T& surname);
	void setName(const T& name);
	void setBirthYear(const T& birthYear);

	T& getName();
	T& getSurname();
	T& getBirthYear();

	bool operator>(const Person<T>& other);
	bool operator<(const Person<T>& other);
	bool operator==(const Person<T>& other);

	template <class T>
	friend std::ostream& operator<< (std::ostream& out, const Person<T>& forOutput);
private:
	T surname_;
	T name_;
	T birthYear_;
};

template <class T>
Person<T>::Person() :
	surname_(""),
	name_(""),
	birthYear_("")
{}

template<class T>
void Person<T>::setSurname(const T& surname)
{
	if (!(surname.size() >= 3 && surname.size() <= 20)) 
	{
		throw std::invalid_argument("Surname has to consist from 3 to 20 symbols\n");
		return;
	}
	if (!(surname[0] >= 'A' && surname[0] <= 'Z')) 
	{
		throw std::invalid_argument("Surname has to start by capital letter\n");
		return;
	} 
	if (surname[surname.size() - 1] == '-')
	{
		throw std::invalid_argument("Surname has to end by a latin letter\n");
	}
	int hyphenCount = 0;
	for (size_t i = 1; i < surname.size(); ++i) 
	{
		if (surname[i] == '-') 
		{
			++hyphenCount;
		}
		if (hyphenCount > 1) 
		{
			throw std::invalid_argument("Surname can't have more than 1 hyphen\n");
			return;
		}
		if ( !( (surname[i] >= 'a' && surname[i] <= 'z') || (surname[i] >= 'A' && surname[i] <= 'Z') || (surname[i] == '-') ) )
		{
			throw std::invalid_argument("Surname has to consist only latin letters and 1 hyphen\n");
			return;
		}
	}

	surname_ = surname;
}

template<class T>
void Person<T>::setName(const T& name)
{
	if (!(name.size() >= 2 && name.size() <= 10)) 
	{
		throw std::invalid_argument("Name has to consist from 2 to 10 symbols\n");
		return;
	}
	if (!(name[0] >= 'A' && name[0] <= 'Z')) 
	{
		throw std::invalid_argument("Name has to start by capital letter\n");
		return;
	}
	for (size_t i = 1; i < name.size(); ++i) 
	{
		if ( !( (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') ) ) 
		{
			throw std::invalid_argument("Name has to consist only latin letters\n");
			return;
		}
	}

	name_ = name;
}

template<class T>
void Person<T>::setBirthYear(const T& birthYear)
{
	if (birthYear.size() != 4) 
	{
		throw std::invalid_argument("Birth year has to consist 4 digits\n");
	}
	for (size_t i = 0; i < birthYear.size(); ++i) 
	{
		if (!(birthYear[i] >= '0' && birthYear[i] <= '9'))
		{
			throw std::invalid_argument("Birth year has to consist only digits\n");
		}
	}

	birthYear_ = birthYear;
}

template<class T>
T& Person<T>::getName()
{
	return name_;
}

template<class T>
T& Person<T>::getSurname()
{
	return surname_;
}

template<class T>
T& Person<T>::getBirthYear()
{
	return birthYear_;
}

template <class T>
bool Person<T>::operator>(const Person<T>& other)
{
	switch (surname_.compare(other.surname_)) 
	{
	case -1:
		return false;
	case 1:
		return true;
	case 0:
		switch (name_.compare(other.name_)) 
		{
		case -1:
			return false;
		case 1:
			return true;
		case 0:
			return birthYear_.compare(other.birthYear_) == 1;
		}
	default:
		return false;
	}
}
template <class T>
bool Person<T>::operator<(const Person<T>& other)
{
	switch (surname_.compare(other.surname_)) 
	{
	case -1:
		return true;
	case 1:
		return false;
	case 0:
		switch (name_.compare(other.name_)) 
		{
		case -1:
			return true;
		case 1:
			return false;
		case 0:
			return birthYear_.compare(other.birthYear_) == -1;
		}
	default:
		return false;
	}
}

template <class T>
bool Person<T>::operator==(const Person<T>& other)
{
	return surname_.compare(other.surname_) == 0
		&& name_.compare(other.name_) == 0
		&& birthYear_.compare(other.birthYear_) == 0;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const Person<T>& forOutput)
{
	out << forOutput.surname_ << ' ' << forOutput.name_ << ' ' << forOutput.birthYear_;
	return out;
}

#endif