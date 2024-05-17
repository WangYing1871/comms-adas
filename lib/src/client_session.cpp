#include <cassert>
#include <iterator>
#include "comms/process.h"
#include "comms/iterator.h"
#include "client_session.h"

namespace adas{

std::unique_ptr<session> session::create_client(boost::asio::io_service& io){
  return std::unique_ptr<session>(new client_session(io)); }
}
namespace adas{
bool client_session::start_impl(){
  message1 msg1;
  msg1.field_f2().value().resize(4);
  send(msg1);
  
  return true;
}

void client_session::handle(comms_message& msg){
  std::cout <<"Received message \"" << msg.name() << "\" with ID="
    << (unsigned)msg.getId() << std::endl;
}

void client_session::handle(message1& msg){
  std::cout<<"wangying"<<std::endl;

}

void client_session::send(comms_message const& msg){
    std::cout << "[START] sending message \"" << msg.name() << "\" with ID=" << 
      (unsigned)msg.getId() << std::endl;
    std::vector<std::uint8_t> output;
    output.reserve(m_frame.length(msg));
    auto write_iter = std::back_inserter(output);
    auto es = m_frame.write(msg,write_iter, output.max_size());
    if (es != comms::ErrorStatus::Success) {
      assert(!"Write operation failed unexpectedly"); return; }
    send_output(&output[0],output.size());
}

std::size_t client_session::process_input_impl(
      const std::uint8_t* buf, std::size_t bl){
  size_t consumed = 0U;
  while(consumed<bl){
    auto bi = buf+consumed;
    auto rl = bl-consumed;
    auto iter = bi;
    frame_t::MsgPtr msg;
    auto es = m_frame.read(msg,iter,rl);
    if (es == comms::ErrorStatus::NotEnoughData){
      
      break;
    }
    if (es == comms::ErrorStatus::ProtocolError) {
      ++consumed;
      continue;
    }
    if (es == comms::ErrorStatus::Success) {
      assert(msg);
      msg->dispatch(*this);
    }

    consumed += static_cast<std::size_t>(std::distance(bi, iter));
    
  }
  return consumed;
}


}
