#include "shop.h"

bool Shop::attack_available() {
	if (attack.inventory <= 0)
		return false;
	return true;
}

bool Shop::defense_available() {
	if (defense.inventory <= 0)
		return false;
	return true;
}

bool Shop::exp_available() {
	if (exp.inventory <= 0)
		return false;
	return true;
}