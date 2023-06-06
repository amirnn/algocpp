/// @copyright Amir Nourinia 2022

#pragma once

#include <cstdint>
#include <stddef.h>
#include <string>
#include <string_view>
#include <optional>
#include <vector>
#include <array>
#include <utility>

using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i32 = std::int32_t;
using i64 = std::int64_t;

using isize = size_t;

using String = std::string;
using StringView = std::string_view;

template <typename T> using Optional = std::optional<T>;

template <typename T> using Vector = std::vector<T>;

template <typename T, isize N> using Array = std::array<T, N>;

template <typename T, typename U> using Pair = std::pair<T, U>;