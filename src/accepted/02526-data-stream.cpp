#include "02526-data-stream.h"

bool Datastream::consec(int num) {
	if (num == value_) {
		return ++count_ >= k_;
	}
	count_ = 0;
	return false;
}
