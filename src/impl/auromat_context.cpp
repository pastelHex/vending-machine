/*
 * auromat_context.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */
#include "automat_context.h"

void automat_context::set_state(std::shared_ptr<automat_state> s) {
	this->state = s;
}
void automat_context::run_state() {
	this->state->do_action(this);
}
automat_context::automat_context() :
		removed_cans(), reszta(0), nr_napoju(0),pool(pool_change_money::create_pool_change_money()) {
}
automat_context::~automat_context() {
}
void automat_context::delete_can(std::uint8_t) {
	std::uint8_t q = 0;
	std::uint8_t ktory = this->nr_napoju;
	while (ktory > this->w_rzedzie) {
		q++;
		ktory = ktory - this->w_rzedzie;
	}
	this->removed_cans.push_back(std::make_pair(ktory, q));
}
bool automat_context::check_if_can_avalible(std::uint8_t n) {
	std::uint8_t q = 0;
	std::uint8_t ktory = n;
	while (ktory > this->w_rzedzie) {
		q++;
		ktory = ktory - this->w_rzedzie;
	}
	//std::cout << (int) ktory << "::" << (int) q << std::endl;
	for (auto para : this->removed_cans) {
		if (para.first == ktory && para.second == q){
			return false;
		}
	}
	return true;
}
