#include <iostream>
#include <plank/src/test.h>

#include <lib/objectify/src/dynamic_base.h>

struct mover
: om636::dynamic_base< om636::time_slice<double> >
{
	typedef om636::dynamic_base< om636::time_slice<double> > base_type;
	using typename base_type::value_type;
	virtual ~mover() = default;
	void on_swap(const value_type &, const value_type &);
};


int main(int argc, const char * argv[])
{
    using namespace om636;
	
    mover m;

	return 0;
}