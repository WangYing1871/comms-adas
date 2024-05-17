#include <cassert>

#include "server_session.h"
#include "comms/process.h"
#include "comms/iterator.h"

namespace adas{
void server_session::handle(comms_message& msg){
  info_out("server_session::handle");
  std::cout << "Received message \"" << msg.name() << "\" with ID=" <<
      (unsigned)msg.getId() << std::endl;
  std::vector<std::uint8_t> output;
  output.resize(m_frame.length(msg));
  auto write_iter = &output[0];
  auto es = m_frame.write(msg,write_iter,output.size());
  if (es != comms::ErrorStatus::Success){
    assert(!"Write operation failed unexpectedly");
    return;
  }
  assert(output.size() == static_cast<std::size_t>(std::distance(&output[0],write_iter)));
  send_output(&output[0],output.size());
}

std::size_t server_session::process_input_impl(std::uint8_t const* buf
    ,size_t bl){
  return comms::processAllWithDispatch(buf,bl,m_frame,*this);
}
//---------------------------------------------------------------------
std::unique_ptr<session> session::create_server(boost::asio::io_service& io){
  return std::unique_ptr<session>(new server_session(io)); }


}
