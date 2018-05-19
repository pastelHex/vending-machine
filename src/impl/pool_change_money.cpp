/*
 * pool_change_money.cpp
 *
 *  Created on: 26 kwi 2018
 *      Author: Anna Zesławska
 */

#include "pool_change_money.h"

std::shared_ptr<pool_change_money> pool_change_money::singleton = nullptr;

change_money* pool_change_money::get_change_for_currency(currency curr) {
	if (free.size() == 0) {
		change_money* ch = new change_money(curr);
		used.insert(ch);
		return ch;
	} else {
		change_money* ch = free.front();
		ch->set_change(curr);
		used.insert(ch);
		free.pop_front();
		return ch;
	}
}
void pool_change_money::return_change(change_money* ch) {
	auto it = used.find(ch);
	if (it != used.end())
		used.erase(ch);
	ch->set_next(nullptr);
	free.push_back(ch);
}
std::shared_ptr<pool_change_money> pool_change_money::create_pool_change_money() {
	if (pool_change_money::singleton == nullptr) {
		pool_change_money::singleton = std::shared_ptr<pool_change_money>(new pool_change_money());
	}
	return pool_change_money::singleton;
}
pool_change_money::pool_change_money() :
		free(), used() {
}
pool_change_money::~pool_change_money() {
	for (auto& a : free) {
		delete a;
	}
	for (auto& a : used) {
		delete a;
	}
	std::cout << "~~~pool" << std::endl;
}
