export module ktl.templates;


template <bool, typename, typename>
struct ternar_s {};

template <typename T1, typename T2>
struct ternar_s<true, T1, T2> { using type = T1; };

template <typename T1, typename T2>
struct ternar_s<false, T1, T2> { using type = T2; };


export
template <bool B, typename T1, typename T2>
using ternar_t = typename ternar_s<B, T1, T2>::type;

export
template <typename, typename>
inline constexpr bool is_same_v = false;

export
template <typename T>
inline constexpr bool is_same_v<T, T> = true;

