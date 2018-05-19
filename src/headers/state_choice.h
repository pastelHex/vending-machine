/*
 * state_choice.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_STATE_CHOICE_H_
#define HEADERS_STATE_CHOICE_H_

#include "automat_state.h"
#include "automat_context.h"
#include "state_give_change.h"

#include <memory>

class state_choice: public automat_state{
	virtual void do_action(automat_context*);
};


#endif /* HEADERS_STATE_CHOICE_H_ */
