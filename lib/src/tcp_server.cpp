#include <iostream>
#include <sstream>

#include "tcp_server.h"

namespace adas{
tcp_server::tcp_server(boost::asio::io_service& io):
  m_io(io), m_acceptor(io) {}

bool tcp_server::start(port_type port){
  boost::system::error_code ec;
  m_acceptor.open(boost::asio::ip::tcp::v4(), ec);
  if (ec){
    std::cerr << "ERROR: Failed to open acceptor with error: " << ec.message();
    return false; }
  m_acceptor.bind(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port), ec);
  if (ec) {
    std::cerr << "ERROR: Failed to bind port " << port << " with error: " << ec.message() << std::endl;
    m_acceptor.close(ec); return false; }
  m_acceptor.listen(boost::asio::socket_base::max_connections, ec);
  if (ec) {
    std::cerr << "ERROR: Failed to put acceptor in the listen state with error: " << ec.message() << std::endl;
    m_acceptor.close(ec); return false; }
  accept();
  return true; }

void tcp_server::accept(){
  m_socket.reset(new socket(m_io));
  m_acceptor.async_accept(
      *m_socket
      ,[this](boost::system::error_code const& ec){
        if (ec == boost::asio::error::operation_aborted) return;
        do{
          if (ec) {
            std::cerr << "ERROR: Accept error: " << ec.message() << std::endl;
            break; }
          std::stringstream stream;
          stream<<m_socket->remote_endpoint();
          auto session_id = stream.str();
          std::cout << "INFO: New connection from " <<session_id<< std::endl;

          auto session = session::create_server(m_io);
          session->set_terminate(
              [this,session_id](){
                if (auto iter = m_sessions.find(session_id); iter==m_sessions.end()){
                  assert(!"Should not happen"); return; }
                else m_sessions.erase(iter);
              });

          session->set_socket(std::move(m_socket));
          if (!session->start()) {
            std::cerr << "ERROR: Failed to start session for " << session_id << std::endl;
            break; }
          assert(!m_socket);
          m_sessions.insert(std::make_pair(std::move(session_id),std::move(session)));
        }while(false);
        accept();
      }
      );
}

}
