#include "money.h"
#include <algorithm>
#include <iostream>   
#include <iomanip>

namespace vsite::oop::v7 {

	void money::calc() {
		if (ct >= 100) {
			eur += ct / 100;
			ct %= 100;
		}
		else if (ct < 0) {
			int x = (abs(ct) + 99) / 100;
			eur -= x;
			ct += x * 100;
		}
	}


	money::money(int eur, int ct) : eur(eur), ct(ct) {
		calc();
	}

	money& money::operator+=(const money& other) {
		eur += other.eur;
		ct += other.ct;
		calc();
		return *this;
	}

	money& money::operator-=(const money& other) {
		eur -= other.eur;
		ct -= other.ct;
		calc();
		return *this;
	}

	int money::get_eur() const {
		return eur;
	}

	int money::get_ct() const {
		return ct;
	}

	std::istream& operator>>(std::istream& is, money& m) {
		is >> m.eur >> m.ct;
		m.calc();
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const money& m) {
		os << m.eur << " eur, " << std::setw(2) << std::setfill('0') << m.ct << " ct";
		return os;
	}

}