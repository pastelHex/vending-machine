/*
 * pool_change_money.h
 *
 *  Created on: 26 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_POOL_CHANGE_MONEY_H_
#define HEADERS_POOL_CHANGE_MONEY_H_

#include <list>
#include <set>
#include <memory>

#include "currency.h"
#include "change_money.h"

class pool_change_money {
private:
	std::list<change_money*> free;
	std::set<change_money*> used;
	static std::shared_ptr<pool_change_money> singleton;

	pool_change_money();

public:
	change_money* get_change_for_currency(currency);
	void return_change(change_money*);
	static std::shared_ptr<pool_change_money> create_pool_change_money();
	~pool_change_money();
};

#endif /* HEADERS_POOL_CHANGE_MONEY_H_ */
