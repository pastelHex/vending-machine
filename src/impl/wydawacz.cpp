/*
 * wydawacz.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#include <wydawacz.h>

wydawacz::wydawacz(std::shared_ptr<pool_change_money> pool) :
		wydawacze(new std::vector<change_money*>), pool(pool) {
}

void wydawacz::set_chain() {
	for (currency a : this->currencies) {
		wydawacze->push_back(pool->get_change_for_currency(a));
	}
	if (wydawacze->size() > 0) {
		for (auto it = wydawacze->begin(), it2 = (++(wydawacze->begin())); it != wydawacze->end() && it2 != wydawacze->end(); it++, it2++) {
			if (it2 != wydawacze->end()) {
				(*it)->set_next((*it2));
			}

		}
	}
}

void wydawacz::wydaj_reszte(std::uint8_t reszta_do_wydania) {
	(*this->wydawacze->begin())->use(reszta_do_wydania);
}

wydawacz::~wydawacz() {
	std::cout << "~~~wydawacz" << std::endl;
	if (wydawacze != nullptr) {
		for (auto it = wydawacze->begin(); it != wydawacze->end(); it++) {
			std::cout << "wydawacz zwraca " << (int) (*it)->curr << std::endl;
			pool->return_change((*it));
		}
		delete wydawacze;
	}
}
