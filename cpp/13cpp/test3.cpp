template<class InputIterator, class UnaryPredicate>
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred)
{
	while (first!=last) {
		if (!pred(*first)) return first;
		++first;
	}
	return last;
}
