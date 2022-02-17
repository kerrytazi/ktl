import ktl.types;
import ktl.rtti;
import std.core;


template <typename T>
void print_type()
{
	constexpr auto &name = type_name<T>::name;
	std::string s(name.data(), name.data() + name.size());
	std::cout << s << '\n';
}

i32 main()
{
	print_type<usize>();
	print_type<array<int, 3>>();
	print_type<std::vector<std::vector<f80>>>();
	return 0;
}
