/*
 * change_money.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#include <change_money.h>

void change_money::use(std::uint16_t money) {
	std::uint8_t i = 0;
	while (money >= this->curr) {
		money = money - this->curr;
		i++;
	}
	if (i > 0 && curr != NONE) {
		std::cout << "Reszta: " << (int) i << "x" << (int) this->curr << " zł." << std::endl;
	}
	if (this->next != nullptr && money > 0) {
		this->next->use(money);
	}
}
change_money::~change_money() {
	std::cout << "delete change_money " << (int) curr << std::endl;
}

void change_money::set_change(currency curr) {
	this->curr = curr;
}
change_money::change_money(currency c) :
		chain(c) {
}
