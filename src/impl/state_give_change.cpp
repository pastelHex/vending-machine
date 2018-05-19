/*
 * state_give_change.cpp
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#include "state_give_change.h"
#include "wydawacz.h"

void state_give_change::do_action(automat_context* ctx) {
	wydawacz* wydaj = new wydawacz(ctx->pool);
	wydaj->set_chain();
	wydaj->wydaj_reszte(ctx->reszta);
	delete wydaj;

	std::uint8_t ktory = ctx->nr_napoju;
	ctx->delete_can(ktory);
	std::shared_ptr<automat_state> p = std::make_shared<state_choice>();
	ctx->set_state(p);
}

