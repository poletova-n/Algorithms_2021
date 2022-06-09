#pragma once
#include < exception >
// ������ StackOverflow � StackUnderflow ������������ ��� ��������
// �������������� ��������, ������� ����� ���������� ��� ������ �� ������
class StackOverflow : public std::exception
{
public:
	StackOverflow() : reason_("Stack Overflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : reason_("Stack Underflow") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size") {}
	const char* what() const { return reason_; }
private:
	const char* reason_; // ! const
};

