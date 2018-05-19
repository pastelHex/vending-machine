/*
 * state_give_change.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_STATE_GIVE_CHANGE_H_
#define HEADERS_STATE_GIVE_CHANGE_H_

#include "automat_state.h"
#include "automat_context.h"
#include "state_choice.h"

#include <memory>

class state_give_change: public automat_state {
public:
	virtual void do_action(automat_context*);
	~state_give_change(){};
};

#endif /* HEADERS_STATE_GIVE_CHANGE_H_ */
