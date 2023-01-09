#ifndef SRC_ACCEPTED_02526_DATASTREAM_H
#define SRC_ACCEPTED_02526_DATASTREAM_H

class Datastream {
	public:
		Datastream(int value, int k) : value_(value), k_(k) {}
		bool consec(int num);

	private:
		const int value_;
		const int k_;

		int count_ = 0;
};

#endif // SRC_ACCEPTED_02526_DATASTREAM_H
