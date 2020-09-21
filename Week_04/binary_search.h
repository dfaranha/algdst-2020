using namespace std;

/**
 * Performs the standard binary search using two comparisons per level.
*/
template <typename iterator, typename Object>
iterator binarySearch(iterator first, iterator last, const Object& value) {
	iterator begin = first;
	iterator end = last;
	while(begin != end) {
		int distance = std::distance(begin, end);
		iterator middle = begin;
		std::advance(begin, distance/2);
		if(*middle == value) {
			return middle;
		} else if(*middle < value) {
			begin = std::next(middle);
		} else {
			end = middle;
		}
	}
	return last;
}
