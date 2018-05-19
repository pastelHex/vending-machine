/*
 * state_choice.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#include <iostream>

#include "state_choice.h"
#include "define.h"

void state_choice::do_action(automat_context* ctx) {
	int platnosc = 0;
	std::uint16_t koszt = (std::rand() % 25) + 2;
	int nr_napoju = 0;
	do {
		print_cans(ctx->w_rzedzie, ctx->rzedy, ctx->removed_cans);

		int max = ctx->w_rzedzie * ctx->rzedy;
		bool aval = true;
		while (nr_napoju <= 0 || nr_napoju > max || !aval) {
			std::cout << "Wybierz napój" << std::endl;
			std::cin >> nr_napoju;
			if (!std::cin) {
				std::cout << "ble" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				nr_napoju = 0;
				continue;
			}
			aval = ctx->check_if_can_avalible(nr_napoju);
			if (!aval)
				std::cout << "Napoj niedostepny" << std::endl;
		}
		ctx->nr_napoju = nr_napoju;

		std::cout << "Koszt: " << koszt << std::endl;
		std::cout << "Ile płacisz?" << std::endl;
		std::cin >> platnosc;
		if (!std::cin) {
			std::cout << "ble" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			platnosc = 0;
		}
	} while (platnosc < koszt);
	//ctx->delete_can(nr_napoju);
	ctx->reszta = platnosc - koszt;
	std::shared_ptr<automat_state> p = std::make_shared<state_give_change>();
	ctx->set_state(p);
}

