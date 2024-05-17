// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains definition of <b>"I2"</b> field.

#pragma once

#include <cstdint>
#include "adas/field/FieldBase.h"
#include "adas/field/I2Common.h"
#include "adas/options/DefaultOptions.h"
#include "comms/field/ArrayList.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"

namespace adas
{

namespace field
{

/// @brief Scope for all the member fields of
///     @ref I2 field.
/// @tparam TOpt Protocol options.
template <typename TOpt = adas::options::DefaultOptions>
struct I2Members
{
    /// @brief Definition of <b>"Element"</b> field.
    class Element : public
        comms::field::IntValue<
            adas::field::FieldBase<>,
            std::uint32_t
        >
    {
        using Base =
            comms::field::IntValue<
                adas::field::FieldBase<>,
                std::uint32_t
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return adas::field::I2MembersCommon::ElementCommon::hasSpecials();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return adas::field::I2MembersCommon::ElementCommon::name();
        }
    };
};

/// @brief Definition of <b>"I2"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = adas::options::DefaultOptions, typename... TExtraOpts>
class I2 : public
    comms::field::ArrayList<
        adas::field::FieldBase<>,
        typename I2Members<TOpt>::Element,
        TExtraOpts...,
        typename TOpt::field::I2,
        comms::option::def::SequenceFixedSize<1024U>
    >
{
    using Base =
        comms::field::ArrayList<
            adas::field::FieldBase<>,
            typename I2Members<TOpt>::Element,
            TExtraOpts...,
            typename TOpt::field::I2,
            comms::option::def::SequenceFixedSize<1024U>
        >;
public:
    /// @brief Name of the field.
    static const char* name()
    {
        return adas::field::I2Common::name();
    }
};

} // namespace field

} // namespace adas
