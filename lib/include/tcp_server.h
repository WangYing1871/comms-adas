#ifndef tcp_server_H
#define tcp_server_H 1 
#include <map>
#include <memory>
#include <boost/asio.hpp>
#include "session.h"

namespace adas{
struct tcp_server{
public:
  typedef boost::asio::ip::tcp::acceptor acceptor;
  typedef boost::asio::ip::tcp::socket socket;
  typedef std::unique_ptr<socket> uptr_socket;
  typedef unsigned short port_type;

  explicit tcp_server(boost::asio::io_service&);
  bool start(port_type port=20000);

private:
  std::map<std::string,std::unique_ptr<session>> m_sessions;
  boost::asio::io_service& m_io;
  acceptor m_acceptor;
  uptr_socket m_socket;

private:
  void accept();

};
}
#endif
