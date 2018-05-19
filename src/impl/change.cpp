/*
 * chain_impl1.cpp
 *
 *  Created on: 15 kwi 2018
 *      Author: Anna Zesławska
 */
#include <change.h>
void change::use(std::uint16_t money) {

}
change::~change() {
	std::cout << "delete change" << std::endl;
}

void change::set_change(currency curr){
	this->curr=curr;
}
