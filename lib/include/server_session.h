#ifndef server_session_H
#define server_session_H 1

#include "session.h"

#include "adas/Message.h"
#include "adas/frame/Frame.h"

namespace adas{
class server_session : public session{
  typedef session base_t;

public:
  using session::session;
  using comms_message = adas::Message<
      comms::option::app::ReadIterator<std::uint8_t const*>
      ,comms::option::app::WriteIterator<std::uint8_t*>
      ,comms::option::app::LengthInfoInterface
      ,comms::option::app::IdInfoInterface
      ,comms::option::app::NameInterface
    >;
  static_assert(comms_message::hasRead(), "Missing polymorphic read");
  static_assert(comms_message::hasWrite(), "Missing polymorphic write");
  static_assert(comms_message::hasLength(), "Missing polymorphic length");
  static_assert(comms_message::hasGetId(), "Missing polymorphic getId");
  static_assert(comms_message::hasName(), "Missing polymorphic name");

  static_assert(std::has_virtual_destructor<comms_message>::value,"destructor is not virtual");

  void handle(comms_message& msg);

protected:
  virtual std::size_t process_input_impl(std::uint8_t const*, std::size_t) override final;

private:
  using frame_t = adas::frame::Frame<comms_message>;
  frame_t m_frame;
};
}
#endif
