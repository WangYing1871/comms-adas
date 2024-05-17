// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref adas::field::I4 field.

#pragma once

#include <cstdint>

namespace adas
{

namespace field
{

/// @brief Common types and functions for
///     @ref adas::field::I4 field.
struct I4Common
{
    /// @brief Re-definition of the value type used by
    ///     adas::field::I4 field.
    using ValueType = std::uint32_t;

    /// @brief Name of the @ref adas::field::I4 field.
    static const char* name()
    {
        return "I4";
    }

    /// @brief Compile time detection of special values presence.
    static constexpr bool hasSpecials()
    {
        return false;
    }
};

} // namespace field

} // namespace adas
