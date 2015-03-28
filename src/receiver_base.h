#ifndef RECEIVER_BASE_H_700fef
	#define RECEIVER_BASE_H_700fef

#include <utility>

#include <lib/context/src/default_subject.h>
#include <lib/context/src/interface.h>
#include <lib/prima/src/primitive.h>
#include <lib/sense/src/observer/same_scope.h>
#include <lib/sense/src/subject.h>

namespace om636
{
	namespace receiver
	{
		// constants
		typedef enum 
		{
			id_window_init,
			id_window_close,
			id_window_resize, 
			id_key_down, 
			id_touch_down,
			id_touch_up,
			id_touch_move,
			id_terminate
		} event_type;
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
		
		event_info(const point_type &, const event_type &);	// touch events
		event_info(const unsigned &, const event_type &);		// key events 
		void swap(event_info &);

		unsigned key_pressed() const;
		unsigned & key_pressed(); 
		
		event_type event_id() const;
		event_type & event_id(); 
		
		point_type position() const;
		point_type & position(); 
		
		bool touch_down() const;
		bool & touch_down(); 

	private:
		unsigned m_key_pressed;
		event_type m_event_id;
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