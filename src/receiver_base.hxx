namespace om636
{
	/////////////////////////////////////////////////////////////////////////////////////////////
	// event_info
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	event_info<T>::event_info(const point_type & p, const unsigned & event_id)
		: m_position( p )
		, m_event_id( event_id )
		, m_touch_down( event_id == id_touch_down )
	{}

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	event_info<T>::event_info(const unsigned & p, const unsigned & event_id)
		: m_key_pressed( p )
		, m_event_id( event_id )
		, m_touch_down( false )
	{}

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	void event_info<T>::swap(event_info<T> & rhs)
	{
		using std::swap;
		using om636::swap;

		swap( m_key_pressed, rhs.m_key_pressed );
		swap( m_event_id, rhs.m_event_id );
		swap( m_touch_down, rhs.m_touch_down );
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	void swap(event_info<T> & lhs, event_info<T> & rhs)
	{
		lhs.swap(rhs);
	}

}	// om636
