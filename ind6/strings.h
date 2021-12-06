class String {
private:
	char* _raw_string;
	size_t length;
public:
	String (); // дефолтный конструктор инициализации

	[[maybe_unused]] explicit String (const char* str); // конструктор инициализации

	[[maybe_unused]] String (const String& str); // конструктор копирования

	[[maybe_unused]] String (String&& str) noexcept; // конструктор перемещения

	~String (); // деструктор

	[[maybe_unused]] [[nodiscard]] size_t get_length () const {
		return this->length;
	}

	char operator[](size_t index); // оператор доступа по индексу
	String& operator=(const String& str); // оператор присваивания копированием
	String& operator=(String&& str) noexcept; // оператор присваивания перемещением

	int32_t compare (String& str);

	friend std::ostream& operator<< (std::ostream& out, const String& str);
};

#include "strings.cpp"