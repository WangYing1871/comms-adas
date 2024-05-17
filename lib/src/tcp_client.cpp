#include <iostream>
#include <sstream>
#include "tcp_client.h"

namespace adas{
tcp_client::tcp_client(boost::asio::io_service& io):
  m_io(io) ,m_session(session::create_client(io)){
  m_session->set_terminate( [this](){m_io.stop();}); }

bool tcp_client::start(port_type port){
  uptr_socket socket_(new socket(m_io));
  boost::system::error_code ec;
  if(ec){
    std::cerr << "ERROR: Failed to connect with error: " << ec.message();
    return false; }
  m_session->set_socket(std::move(socket_));
  return m_session->start();
}
}
