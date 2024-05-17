#ifndef client_session_H
#define client_session_H 1 
#include <iterator>
#include <vector>

#include "adas/Message.h"
#include "adas/frame/Frame.h"

#include "session.h"

namespace adas{
class client_session : public session{
  typedef session base_t;
public:
  using session::session;

  using comms_message = adas::Message<
    comms::option::app::ReadIterator<const std::uint8_t*>
    ,comms::option::app::WriteIterator<std::back_insert_iterator<std::vector<std::uint8_t>>>
    ,comms::option::app::LengthInfoInterface
    ,comms::option::app::IdInfoInterface
    ,comms::option::app::NameInterface
    ,comms::option::app::Handler<client_session>
    >;
  static_assert(comms_message::hasRead(), "Missing polymorphic read");
  static_assert(comms_message::hasWrite(), "Missing polymorphic write");
  static_assert(comms_message::hasLength(), "Missing polymorphic length");
  static_assert(comms_message::hasGetId(), "Missing polymorphic getId");
  static_assert(comms_message::hasName(), "Missing polymorphic name");
  static_assert(comms_message::hasDispatch(), "Missing polymorphic dispatch");
  static_assert(std::has_virtual_destructor<comms_message>::value
      ,"Destructor is not virtual");

  using message1 = adas::message::Msg1<comms_message>;

  void handle(comms_message& msg);

public:
  void handle(message1&);

protected:
  virtual bool start_impl() override final;
  virtual std::size_t process_input_impl(
      const std::uint8_t* buf, std::size_t bufLen) override final;

private:

  using frame_t = adas::frame::Frame<comms_message>;
  frame_t m_frame;

  void send(comms_message const&);

  
  
};
}

#endif
