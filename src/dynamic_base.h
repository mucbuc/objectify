#ifndef DYNAMIC_BASE_H_JAKBOOWH667346
	#define DYNAMIC_BASE_H_JAKBOOWH667346

#include <lib/sense/src/observer.h>
// #include <vector>
// #include "singleton.h"

namespace om636
{
	// time_slice
	template<class T> 
	struct time_slice
	{	
		// types 
		typedef T value_type; 
		//typedef context< time_slice, subject< basic_subject< std::vector< abstract_observer< time_slice > * > > > > context_type;	
		
		// resources
		time_slice(const value_type & v = 0.0);
		time_slice(const time_slice &) = default;
		time_slice & operator=(const time_slice &) = default;
		
		value_type & value(); 
		value_type value() const; 
		
		void swap(time_slice &);
	private:
		
		value_type m_value;	
	};

	template<class T> 
	void swap(time_slice<T> &, time_slice<T> &);
	
	// dynamic_base 
	template<class T> 
	class dynamic_base
		: public const_observer< T > 
	{
		dynamic_base(const dynamic_base &) = delete;
		dynamic_base & operator=(dynamic_base) = delete;
	
	public:
	
		// types
		typedef T value_type;  
		typedef const_observer< value_type > base_type; 
		typedef typename base_type::context_type context_type; 
		
		// resources
		dynamic_base(context_type &); 
		virtual ~dynamic_base() = default;
		
		// 
		virtual void on_swap(const value_type &, const value_type &);
		
		const value_type & age();
	
	private:	
		typename value_type::value_type m_age;
	};

} 	// om636

#include "dynamic_base.hxx"

#endif // DYNAMIC_BASE_H_JAKBOOWH7346