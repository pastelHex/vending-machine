/*
 * chain_impl1.h
 *
 *  Created on: 15 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include <chain.h>

class change: public chain {
public:
	virtual void use(std::uint16_t);
	virtual ~change();
	virtual void set_change(currency curr);
};

#endif /* CHANGE_H_ */
