export module ktl.rtti;

import ktl.types;
import ktl.array;


export
template <typename T>
struct type_name
{
private:

#ifdef _MSC_VER // __FUNCSIG__

#define skip_string(str) \
	do {														\
	for (usize i = begin; i != sizeof(__FUNCSIG__); ++i)		\
	{															\
		for (usize j = 0; j + i != sizeof(__FUNCSIG__); ++j)	\
		{														\
			if (__FUNCSIG__[i + j] != str[j])					\
				break;											\
																\
			if (j + 1 == sizeof(str) - 1)						\
			{													\
				begin = i + j + 1;								\
				i = sizeof(__FUNCSIG__) - 1;					\
				break;											\
			}													\
		}														\
	}															\
	} while (0)

	static constexpr usize $size()
	{
		usize begin = 0;

		skip_string("<");
		skip_string("class ");
		skip_string("struct ");

		usize depth = 1;

		for (usize i = begin; i != sizeof(__FUNCSIG__); ++i)
		{
			if (__FUNCSIG__[i] == '<')
				++depth;
			else
			if (__FUNCSIG__[i] == '>')
				--depth;

			if (depth == 0)
				return i - begin;
		}

		__assume(0);
	}

	template <usize S>
	static constexpr array<char, S> $getname()
	{
		usize begin = 0;

		skip_string("type_name");
		skip_string("<");
		skip_string("class ");
		skip_string("struct ");

		array<char, S> out{};

		for (usize i = 0; i != S; ++i)
			out[i] = __FUNCSIG__[begin + i];

		return out;
	}
#else // __PRETTY_FUNCTION__
#endif

public:

	static constexpr usize size = $size();

	static constexpr array<char, size> name = $getname<size>();

};

