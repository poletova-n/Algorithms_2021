//
// Created by reenie on 06.12.2021.
//

class BankCard {
public:
	String CardholderName;
	String CardholderSurname;
	String CardNumber;
	String CardExpireDate;
	char   BankType;



public:
	BankCard (char* source_str) : CardExpireDate("default"), CardholderName("deafult2"), CardholderSurname("default3"), CardNumber("default4")
	{
		this->CardExpireDate = 0;
	}

	~BankCard () {
		std::cout << "Card destructor1.";
		std::cout << "Card destructor2.";
	}
};

#ifndef ALGORITHMS_2021_BANKCARD_H
#define ALGORITHMS_2021_BANKCARD_H

#endif //ALGORITHMS_2021_BANKCARD_H
