// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains definition of protocol server input messages dynamic memory allocation message factory options.

#pragma once

#include "adas/factory/ServerInputMessagesDynMemMsgFactory.h"
#include "adas/options/DefaultOptions.h"

namespace adas
{

namespace options
{

/// @brief Provided server input messages dynamic memory allocation message factory options of the protocol.
/// @details Must be used as the outermost wrapper of the protocol options.
template <typename TBase = adas::options::DefaultOptions>
struct ServerInputMessagesDynMemMsgFactoryDefaultOptionsT : public TBase
{
    /// @brief Alias to @ref adas::factory::ServerInputMessagesDynMemMsgFactory message factory.
    /// @details Exposes the same template parameters as @b comms::MsgFactory.
    template <typename TInterface, typename TAllMessages, typename... TOptions>
    using MsgFactory = adas::factory::ServerInputMessagesDynMemMsgFactory<TInterface, ServerInputMessagesDynMemMsgFactoryDefaultOptionsT<TBase> >;

    /// @brief Extra options for frames.
    struct frame : public TBase::frame
    {
        /// @brief Extra options for layers of
        ///     @ref adas::frame::Frame frame.
        struct FrameLayers : public TBase::frame::FrameLayers
        {
            /// @brief Extra options for @ref
            ///     adas::frame::FrameLayers::ID layer.
            using ID =
                std::tuple<
                    comms::option::app::MsgFactoryTempl<MsgFactory>,
                    typename TBase::frame::FrameLayers::ID
                >;
        }; // struct FrameLayers
    }; // struct frame
};

/// @brief Alias to @ref ServerInputMessagesDynMemMsgFactoryDefaultOptionsT with default template parameter.
using ServerInputMessagesDynMemMsgFactoryDefaultOptions = ServerInputMessagesDynMemMsgFactoryDefaultOptionsT<>;

} // namespace options

} // namespace adas