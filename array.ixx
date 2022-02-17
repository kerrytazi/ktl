export module ktl.array;

import ktl.types;


export
template <typename T, usize S>
class array
{
public:

	using value_type = T;
	using size_type = usize;
	using difference_type = isize;
	using reference =value_type &;
	using const_reference = const value_type &;
	using pointer = value_type *;
	using const_pointer = const value_type *;

	using iterator = pointer;
	using const_iterator = const_pointer;

private:

	T _arr[S];

public:

	constexpr size_type size() const { return S; }

	constexpr pointer data() { return _arr; }
	constexpr const_pointer data() const { return _arr; }

	constexpr reference operator [] (size_type index) { return _arr[index]; }
	constexpr const_reference operator [] (size_type index) const { return _arr[index]; }

	constexpr iterator begin() { return _arr; }
	constexpr const_iterator begin() const { return _arr; }

	constexpr iterator end() { return &_arr[S]; }
	constexpr const_iterator end() const { return &_arr[S]; }

};

