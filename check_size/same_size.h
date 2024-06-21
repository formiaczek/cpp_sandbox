#include <exception>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <stddef.h>


namespace Macros {
template<typename ... Containers>
std::tuple<bool, std::vector<size_t>>
all_have_this_size(size_t expected_size, const Containers &... containers) {
	bool matches = true;
	auto check = [&expected_size, &matches] (const auto& container) {
		if (container.size() != expected_size) {
			matches = false;
		}
		return container.size();
	};
	auto constexpr num_vectors = sizeof... (Containers);
	size_t sizes [num_vectors] = {(check(containers))...};
	return std::make_tuple (matches, std::vector<size_t>(sizes, sizes+num_vectors));
}

template<typename... Containers>
void check_containers(size_t expected_size, std::string names,
		const Containers &... containers) {
	auto [all_same_size, sizes] = all_have_this_size(expected_size,	std::forward<const Containers>(containers)...);
	if (!all_same_size) {
		std::stringstream err;
		err << "Size mismatch for: [" << names << "], expected size was: "
				<< expected_size << " but actual sizes were: [";
		for (size_t i = 0; i < sizes.size(); ++i) {
			err << (i > 0 ? ", " : "") << sizes[i];
		}
		err << "]";
		throw std::logic_error(err.str());
	}
}
}

/**
 * Use this macro to verify if all of the containers listed have the expected size, e.g.:
  std::vector<int> a(3), b(5), c(3), d(4);
  ASSERT_ALL_THIS_SIZE(5, a, b, c, d);

 throws:
  Size mismatch for: (a, b, c, d), expected size for all is: 5 but actual sizes were: [3, 5, 3, 4]

 */

#define ASSERT_ALL_THIS_SIZE(expected_size, ...) Macros::check_containers (expected_size, #__VA_ARGS__, __VA_ARGS__)

