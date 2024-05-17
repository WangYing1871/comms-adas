// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains definition of the ClientInputMessages messages bundle.

#pragma once

#include <tuple>
#include "adas/message/Msg1.h"
#include "adas/options/DefaultOptions.h"

namespace adas
{

namespace input
{

/// @brief Client input messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = adas::options::DefaultOptions>
using ClientInputMessages =
    std::tuple<
        adas::message::Msg1<TBase, TOpt>
    >;

} // namespace input

} // namespace adas

/// @brief Create type aliases for the client input messages of the protocol.
/// @param prefix_ Prefix of the alias message type.
/// @param suffix_ Suffix of the alias message type.
/// @param interface_ Type of the common message interface.
/// @param opts_ Type of the used protocol definition options.
#define ADAS_ALIASES_FOR_CLIENT_INPUT_MESSAGES(prefix_, suffix_, interface_, opts_) \
    using prefix_ ## Msg1 ## suffix_ = adas::message::Msg1<interface_, opts_>;

/// @brief Create type aliases for the client input messages of the protocol using default options.
/// @param prefix_ Prefix of the alias message type.
/// @param suffix_ Suffix of the alias message type.
/// @param interface_ Type of the common message interface.
#define ADAS_ALIASES_FOR_CLIENT_INPUT_MESSAGES_DEFAULT_OPTIONS(prefix_, suffix_, interface_) \
    ADAS_ALIASES_FOR_CLIENT_INPUT_MESSAGES(prefix_, suffix_, interface_, adas::options::DefaultOptions)