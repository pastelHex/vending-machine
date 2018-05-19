/*
 * context.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_AUTOMAT_CONTEXT_H_
#define HEADERS_AUTOMAT_CONTEXT_H_

#include <automat_state.h>
#include <vector>
#include <memory>
#include <iostream>

#include "pool_change_money.h"

class automat_context {
public:
	std::shared_ptr<automat_state> state;
	std::vector<std::pair<std::uint8_t, std::uint8_t>> removed_cans;
	std::uint8_t w_rzedzie = 3;
	std::uint8_t rzedy = 3;
	std::uint16_t reszta;
	std::uint8_t nr_napoju;
	std::shared_ptr<pool_change_money> pool;

	void set_state(std::shared_ptr<automat_state> s);
	void delete_can(std::uint8_t);
	bool check_if_can_avalible(std::uint8_t);
	void run_state();
	automat_context();
	~automat_context();
};

#endif /* HEADERS_AUTOMAT_CONTEXT_H_ */
