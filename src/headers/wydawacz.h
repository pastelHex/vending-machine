/*
 * wydawacz.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_WYDAWACZ_H_
#define HEADERS_WYDAWACZ_H_

#include <change_money.h>
#include <vector>

#include "pool_change_money.h"
#include "currency.h"

class wydawacz {
public:
	std::vector<change_money*>* wydawacze;
	std::vector<currency> currencies = { TEN, FIVE, TWO, ONE };
	std::shared_ptr<pool_change_money> pool;

	wydawacz(std::shared_ptr<pool_change_money>);
	~wydawacz();
	void set_chain() ;
	void wydaj_reszte(std::uint8_t reszta_do_wydania);
};

#endif /* HEADERS_WYDAWACZ_H_ */
