#ifndef VISUAL_BASE_H_433900700
	#define VISUAL_BASE_H_433900700

#include <lib/context/src/interface.h>
#include <lib/context/src/default_subject.h>
#include <lib/sense/src/subject.h>
#include <lib/sense/src/observer/same_scope.h>


#include <tuple>

#include <lib/prima/src/primitive.h>

namespace om636
{
	template<class T>
	struct frame_swap
	{	
		typedef primitive<unsigned, unsigned> point_type;

		frame_swap() = default;
		frame_swap(const frame_swap &) = default;
		frame_swap & operator=(const frame_swap &) = default;

		void swap(frame_swap &);
	
		point_type & size(); 
		const point_type & size() const; 
		
	private:
		
		point_type m_size;
	};

	template<class T>
	void swap( frame_swap<T> &, frame_swap<T> & );

	template<class T>
	using visual_subject = basic_subject<T, const_observer>;

	// visual_base 
	template<class T> 
	class visual_base
		: public same_scope< context< T, visual_subject > > 
	{
		visual_base(const visual_base &) = delete;
		visual_base & operator=(visual_base) = delete;
	
	public:
	
		// types
		typedef T value_type;
		typedef context< value_type, visual_subject > context_type;  
		typedef same_scope< context_type > base_type; 
		
		// resources
		visual_base(context_type &); 
		virtual ~visual_base() = default;
		
		virtual void on_swap(const context_type &, const context_type &);
		
		const value_type & frame_count() const;
	
	private:	
		unsigned m_frame_count;
	};
   
} // om636

#include "visual_base.hxx"

#endif // VISUAL_BASE_H_433900700