#ifndef tcp_client_H
#define tcp_client_H 1 
#include "session.h"
namespace adas{
class tcp_client{
public:
  typedef boost::asio::ip::tcp::socket socket;
  typedef std::unique_ptr<socket> uptr_socket;
  typedef unsigned short port_type;

  explicit tcp_client(boost::asio::io_service&);
  bool start(port_type port=20000);

private:
  boost::asio::io_service& m_io;
  std::unique_ptr<session> m_session;
};
}
#endif
