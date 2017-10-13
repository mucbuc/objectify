namespace om636 {
/////////////////////////////////////////////////////////////////////////////////////////////
// frame_swap
/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
frame_swap<T>::frame_swap(point_type s)
    : m_size(s)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
auto frame_swap<T>::size() const -> const point_type&
{
    return m_size;
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
auto frame_swap<T>::size() -> point_type&
{
    return m_size;
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void frame_swap<T>::swap(frame_swap& f)
{
    using om636::swap;
    swap(m_size, f.m_size);
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void swap(frame_swap<T>& lhs, frame_swap<T>& rhs)
{
    rhs.swap(lhs);
}

/////////////////////////////////////////////////////////////////////////////////////////////
// visual_base<time_slice>
/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
visual_base<T>::visual_base(context_type& s)
    : base_type(s)
    , m_frame_count()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
auto visual_base<T>::frame_count() const -> const value_type&
{
    return m_frame_count;
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void visual_base<T>::on_swap(const context_type&, const context_type&)
{
    ++m_frame_count;
}

} // om636
