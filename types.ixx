export module ktl.types;

import ktl.templates;

export using i8 = signed char;
export using i16 = signed short;
export using i32 = signed int;
export using i64 = signed long long;

export using u8 = unsigned char;
export using u16 = unsigned short;
export using u32 = unsigned int;
export using u64 = unsigned long long;

export using f32 = float;
export using f64 = double;
export using f80 = long double;

export using isize = ternar_t<sizeof(void *) == 4, i32, i64>;
export using usize = ternar_t<sizeof(void *) == 4, u32, u64>;

