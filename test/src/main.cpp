#include <iostream>
#include <plank/src/test.h>

#include <lib/context/src/interface.h>

#include <lib/objectify/src/dynamic_base.h>
#include <lib/objectify/src/visual_base.h>
#include <lib/objectify/src/receiver_base.h>

struct mover
: om636::dynamic_base< om636::time_slice<double> >
, om636::visual_base< om636::frame_swap<void> >
, om636::receiver_base< om636::event_info<void> >
{
    typedef om636::dynamic_base< om636::time_slice<double> > dynamic_base_type;
    typedef om636::visual_base< om636::frame_swap<void> > visual_base_type;
    typedef om636::receiver_base< om636::event_info<void> > receiver_base_type;
    
    template<class T>
    mover(T & c)
        : dynamic_base_type(c)
        , visual_base_type(c)
        , receiver_base_type(c)
        , m_animated()
        , m_rendered()
        , m_notified()
    {}
    
    virtual ~mover() = default;
    
    void on_swap(const dynamic_base_type::context_type &, const dynamic_base_type::context_type &)
    {
        m_animated = true;
    }

    void on_swap(const visual_base_type::context_type &, const visual_base_type::context_type &)
    {
        m_rendered = true;
    }

    void on_swap(const receiver_base_type::context_type &, const receiver_base_type::context_type &)
    {
        m_notified = true;
    }
    
    bool m_animated;
    bool m_rendered;
    bool m_notified;
};

struct Context
: mover::dynamic_base_type::context_type
, mover::visual_base_type::context_type
, mover::receiver_base_type::context_type
{
    using mover::dynamic_base_type::context_type::operator=;
    using mover::visual_base_type::context_type::operator=;
    using mover::receiver_base_type::context_type::operator=;
};

void test_dynamic_base()
{
    using namespace om636;
    Context c;
    mover m( c );
    
    c = time_slice<double>(1.9);
    c = frame_swap<void>();
    c = event_info<void>(6, receiver::id_key_down );
    ASSERT(m.m_animated && m.m_rendered && m.m_notified);
    FOOTER;
}

int main(int argc, const char * argv[])
{
    using namespace om636;
    
    test_dynamic_base();
    
    frame_swap<unsigned> p;
    event_info<void> q(0, receiver::id_key_down );
	return 0;
}