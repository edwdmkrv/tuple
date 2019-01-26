#include <tuple>
#include <iostream>

#include <cassert>

namespace version1 {

template <typename... Types>
using custom_tuple = std::tuple<Types...>;

template <typename... Types>
auto custom_make_tuple(Types &&... values) {
	return std::make_tuple(std::forward<Types>(values)...);
}

template <typename... Types>
auto custom_tie(Types &... values) {
	return std::tie(values...);
}

} // namespace version 1

namespace version2 {

template <typename... Types>
using custom_tuple = std::tuple<Types...>;

template <typename... Types>
auto custom_make_tuple(Types &&... values) {
	return custom_tuple<typename std::decay<Types>::type...>{std::forward<Types>(values)...};
}

template <typename... Types>
auto custom_tie(Types &... values) {
	return custom_tuple<Types &...>(values...);
}

} // namespace version2

namespace version3 {

template <typename Type, typename... Types>
class custom_tuple: public custom_tuple<Types...> {
private:
	Type value;

public:
	custom_tuple(Type const &value, Types const &... values): custom_tuple<Types...>{values...}, value{value} {}

	Type const &get() const & noexcept {
		return value;
	}

	Type &&get() && noexcept {
		return std::move(value);
	}
};

template <typename Type>
class custom_tuple<Type> {
private:
	Type value;

public:
	custom_tuple(Type const &value): value{value} {}

	Type const &get() const & noexcept {
		return value;
	}

	Type &&get() && noexcept {
		return std::move(value);
	}
};

template <typename Type, typename... Types>
class custom_tuple<Type &, Types &...>: public custom_tuple<Types &...> {
private:
	Type &value;

public:
	custom_tuple(Type &value, Types &... values): custom_tuple<Types &...>{values...}, value{value} {}

	custom_tuple<Type &, Types &...> &operator =(custom_tuple<Type, Types...> const &tuple) {
		custom_tuple<Types &...>::operator =(tuple);
		value = tuple.get();
		return *this;
	}

	custom_tuple<Type &, Types &...> &operator =(custom_tuple<Type, Types...> &&tuple) {
		custom_tuple<Types &...>::operator =(std::move(tuple));
		value = std::move(tuple).get();
		return *this;
	}
};

template <typename Type>
class custom_tuple<Type &> {
private:
	Type &value;

public:
	custom_tuple(Type &value): value{value} {}

	custom_tuple<Type &> &operator =(custom_tuple<Type> const &tuple) {
		value = tuple.get();
		return *this;
	}

	custom_tuple<Type &> &operator =(custom_tuple<Type> &&tuple) {
		value = std::move(tuple).get();
		return *this;
	}
};

template <typename... Types>
auto custom_make_tuple(Types &&... values) {
	return custom_tuple<typename std::decay<Types>::type...>{std::forward<Types>(values)...};
}

template <typename... Types>
auto custom_tie(Types &... values) {
	return custom_tuple<Types &...>(values...);
}

} // namespace version3
