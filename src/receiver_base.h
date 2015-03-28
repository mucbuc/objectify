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
		event_info() = default;
		event_info(const event_info &) = default;
		event_info & operator=(const event_info &) = default;
		
		event_info(const point_type &, const unsigned &);	// touch events
		event_info(const unsigned &, const unsigned &);		// key events 
		void swap(event_info &);

	private:
		unsigned m_key_pressed, m_event_id;
		point_type m_position;
		bool m_touch_down;
	};
	
	template<class T>
	void swap(event_info<T> &, event_info<T> &);

	// receiver_base 
	template<class T> 
	class receiver_base
		: public same_scope< context< T, visual_subject > > 
	{
		receiver_base(const receiver_base &) = delete;
		receiver_base & operator=(const receiver_base &) = delete;
	
	public:
	
		// types
		typedef T value_type;
		typedef context< value_type, visual_subject > context_type;  
		typedef same_scope< context_type > base_type; 
		
		// resources
		receiver_base(context_type &); 
		virtual ~receiver_base() = default;
	};

} // om636
	
#include "receiver_base.hxx"

#endif // RECEIVER_BASE_H_700fef