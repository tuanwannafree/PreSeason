#include "TamGiac.h"
#include <cmath>
int TamGiac::Loaitg() {
	if (a == b || b == c || a == c) {
		if (a == c) {
			return 1;
		}
		else if( (  c * c == a * a + b * b)) {
			return 2;
		}
	}
}
