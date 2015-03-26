#include <iostream>
#include <plank/src/test.h>

#include <lib/objectify/src/dynamic_base.h>
#include <lib/objectify/src/dynamic_base.h>

void test_dynamic_base()
{
    struct mover
    : om636::dynamic_base< om636::time_slice<double> >
    {
        typedef om636::dynamic_base< om636::time_slice<double> > base_type;
        using typename base_type::value_type;
        using typename base_type::context_type;
        
        mover(context_type & c)
        : base_type(c)
        , m_swapped()
        {}
        
        virtual ~mover() = default;
        void on_swap(const context_type &, const context_type &)
        {
            m_swapped = true;
        }
        
        bool m_swapped;
    };

    using namespace om636;
    typename mover::context_type c;
    mover m( c );
    
    c = time_slice<double>(1.9);
    
    ASSERT(m.m_swapped);
    FOOTER;
}

int main(int argc, const char * argv[])
{
    test_dynamic_base();
    
	return 0;
}