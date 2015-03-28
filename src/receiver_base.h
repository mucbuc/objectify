#ifndef RECEIVER_BASE_H_700fef
	#define RECEIVER_BASE_H_700fef

#include <utility>

// #include "context.h"
// #include "object_base.h"
// #include "observer.h"
// #include "subject.h"
// #include "number.h"

#include <lib/prima/src/primitive.h>

namespace om636
{
	namespace receiver
	{
		// constants
		enum 
		{
			id_window_init,
			id_window_close,
			id_window_resize, 
			id_key_down, 
			id_touch_down,
			id_touch_up,
			id_touch_move,
			id_terminate
		};
	}
	
	using namespace receiver; 
		
	template<class T>
	struct event_info 
	{
		// types 
		typedef primitive<unsigned, unsigned> point_type; 
		typedef primitive<unsigned, unsigned, unsigned, unsigned> rect_type; 

		// resources
		event_info() = delete;
		event_info(const event_info &) = default;
		event_info & operator=(const event_info &) = default;
		
		event_info(const point_type &, const unsigned &);	// touch events
		event_info(const unsigned &, const unsigned &);		// key events 
		void swap(event_info &);

		unsigned m_key_pressed, m_event_id;
		point_type m_position;
		bool m_touch_down;
	};
	
	template<class T>
	void swap(event_info<T> &, event_info<T> &);

} // om636
	
#include "receiver_base.hxx"

#endif // RECEIVER_BASE_H_700fef