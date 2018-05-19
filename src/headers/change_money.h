/*
 * change_money.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_CHANGE_MONEY_H_
#define HEADERS_CHANGE_MONEY_H_

#include <chain.h>
#include "currency.h"

class change_money: public chain {
public:
	virtual void use(std::uint16_t);
	virtual ~change_money();
	virtual void set_change(currency curr);
	change_money(currency);
};


#endif /* HEADERS_CHANGE_MONEY_H_ */
