/*
 * define.h
 *
 *  Created on: 24 kwi 2018
 *      Author: Anna Zesławska
 */

#ifndef HEADERS_DEFINE_H_
#define HEADERS_DEFINE_H_

#include <sstream>
#include <set>
/*std::string can = R"(
 =====
 ___ 
 |"""|
 |   |
 xxxxx
 |   |
 """
 |1|
 )";*/
static void push_to_ss(std::stringstream& ss, std::string s, std::uint8_t ile_razy, std::set<std::uint8_t> removed) {
	std::uint8_t i = 0;
	while (i < ile_razy) {
		i++;
		if (removed.find(i) == removed.end())
			ss << s;
		else
			ss << "xxxxx";
	}
	ss << "\n";
}
inline void print_cans(std::uint8_t ile, std::uint8_t pietra, std::vector<std::pair<std::uint8_t, std::uint8_t>> removed) {
	std::stringstream ss;
	std::uint8_t i = 0;
	std::uint8_t j = 0;
	std::uint8_t count = 0;
	std::set<std::uint8_t> removed_i;
	push_to_ss(ss, "=====", ile, removed_i);

	while (j < pietra) {
		std::set<std::uint8_t> removed_in_row;
		for (auto& p : removed) {
			if (p.second == j)
				removed_in_row.insert(p.first);
		}
		push_to_ss(ss, " ___ ", ile, removed_in_row);
		push_to_ss(ss, R"(|"""|)", ile, removed_in_row);
		push_to_ss(ss, "|   |", ile, removed_in_row);
		push_to_ss(ss, "|   |", ile, removed_in_row);
		push_to_ss(ss, R"( """ )", ile, removed_in_row);
		while (i < ile) {
			i++;
			count++;
			if (count < 10 || i == 1)
				ss << " |" << (int) count << "| ";
			/*else if(removed_in_row.find(i)!=removed_in_row.end())
			 ss << "xxxxx";*/
			else
				ss << "|" << (int) count << "| ";
		}
		ss << "\n";
		i = 0;
		j++;
	}
	i = 0;
	while (i < ile) {
		i++;
		ss << "=====";
	}
	ss << "\n";

	std::cout << ss.str() << std::endl;
}

#endif /* HEADERS_DEFINE_H_ */
