/*
 * state.h
 *
 *  Created on: 25 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_AUTOMAT_STATE_H_
#define HEADERS_AUTOMAT_STATE_H_

//#include "automat_context.h"
class automat_context;

class automat_state {
public:
	virtual void do_action(automat_context*)=0;
	~automat_state(){};
};

#endif /* HEADERS_AUTOMAT_STATE_H_ */
