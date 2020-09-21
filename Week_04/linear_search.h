using namespace std;

/**
 * Performs the standard binary search using two comparisons per level.
*/
template <typename iterator, typename Object>
iterator linearSearch(iterator first, iterator last, const Object& value) {
	iterator begin = first;
	iterator end = last;
	while(begin != end) {
		if(*begin == value) {
			return begin;
		} else {
			begin = std::next(begin);
		}
	}
	return end;
}
