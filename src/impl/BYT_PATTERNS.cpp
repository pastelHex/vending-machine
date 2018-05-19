//============================================================================
// Name        : BYT_PATTERNS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <change.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <wydawacz.h>
#include <cstdlib>
#include <ctime>

#include "define.h"
#include "automat_context.h"
#include "state_choice.h"

using namespace std;

int main() {
	srand(time( NULL));

	automat_context* context = new automat_context();
	context->set_state(std::make_shared<state_choice>());
	while (context->removed_cans.size() < (context->rzedy * context->w_rzedzie)) {
		context->run_state();
	}

	std::cout << "AUTOMAT NIECZYNNY" << std::endl;

	return 0;
}
