#include "session.h"
#include <cassert>
#include <iostream>

namespace adas{

session::~session() = default;
//---------------------------------------------------------------------
bool session::start(){
  assert(m_socket->is_open()); 
  if (!start_impl()) return false;
  read();
  return true;
}
//---------------------------------------------------------------------
bool session::start_impl(){ return true; }
//---------------------------------------------------------------------
void session::send_output(std::uint8_t const* buf, std::size_t bl){
  std::cout << "[send_output] sending raw data: " << std::hex;
  std::copy(buf, buf+bl, std::ostream_iterator<unsigned>(std::cout, " "));
  std::cout << std::dec << std::endl; 
  if (!m_socket->is_open()) return;
  size_t consumed = 0U;
  while(consumed<bl){
    boost::system::error_code ec;
    consumed += boost::asio::write(*m_socket,boost::asio::buffer(buf,bl),ec);
    if (ec){
      std::cerr << "ERROR: Failed to write: " << ec.message() << std::endl;
      terminate_session(); return; }
  }
}
//---------------------------------------------------------------------
void session::terminate_session(){
  assert(m_terminate_cb);
  m_terminate_cb(); }
//---------------------------------------------------------------------
void session::read(){
  assert(m_socket);
  assert(m_socket->is_open());
  info_out("...");
  m_socket->async_read_some(
      boost::asio::buffer(m_buffer)
      ,[this](boost::system::error_code const& ec, size_t bc){
        if (ec==boost::asio::error::operation_aborted) return;
        if (ec){
          std::cerr<<"[ERROR] failed to read "<<ec.message()<<std::endl;
          terminate_session();
          return;
        }
        auto* addr = &m_buffer[0];
        bool ve = !m_data.empty();
        if(ve){
          m_data.insert(m_data.end(),addr,addr+bc);
          addr = &m_data[0];
          bc = m_data.size();
        }

        auto consumed = process_input_impl(addr,bc);
        if (ve) m_data.erase(m_data.begin(),m_data.begin()+consumed);
        else{
          auto bi = addr + consumed;
          auto ei = bi + bc - consumed;
          m_data.assign(bi,ei);
        }
        read();
      });
}
}
