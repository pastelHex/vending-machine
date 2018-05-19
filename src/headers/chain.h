/*
 * chain.h
 *
 *  Created on: 15 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef CHAIN_H_
#define CHAIN_H_

#include <iostream>

#include "currency.h"

class chain {

public:
	currency curr;

	chain();
	chain(currency);
	virtual void use(std::uint16_t m) = 0;
	virtual void set_change(currency curr) = 0;
	virtual chain* set_next(chain* next);
	virtual ~chain();

protected:
	chain* next;

};

#endif /* CHAIN_H_ */
