/*
 * chain.cpp
 *
 *  Created on: 15 kwi 2018
 *      Author: Anna Zesławska
 */
#include <chain.h>

chain::~chain() {
	//std::cout << "delete base" << std::endl;
	if (next == nullptr)
		delete next;
}
chain* chain::set_next(chain* next) {
	chain* pom = nullptr;
	if (this->next != nullptr)
		pom = this->next;
	this->next = next;
	return pom;
	//std::cout<<"dla :"<<(int)curr<<" next:"<<(int)next->curr<<std::endl;
}

chain::chain() :
		curr(NONE), next(nullptr) {
}
chain::chain(currency c) :
		curr(c), next(nullptr) {
}
