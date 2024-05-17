#ifndef session_H
#define session_H 1 
#include <memory>
#include <vector>
#include <array>
#include <iostream>
#include <iomanip>
#include <type_traits>

#include "boost_wrap.h"

namespace adas{
class session{
  typedef session self_t;
public:
  typedef std::unique_ptr<self_t> uptr_t;
  typedef boost::asio::ip::tcp::socket socket_t;
  typedef std::unique_ptr<socket_t> uptr_socket_t;

  typedef std::function<void()> terminate_cb_t;

  explicit session(boost::asio::io_service& io): m_io(io) {}
  virtual ~session();

  inline void set_socket(std::unique_ptr<boost::asio::ip::tcp::socket> s){
    m_socket = std::move(s); }

  template <class _tp>
  inline void set_terminate(_tp&& func){
    m_terminate_cb = std::forward<_tp>(func); }

  boost::asio::io_service& get_io(){ return m_io; }

  bool start();

private:
  void read();
  boost::asio::io_service& m_io;
  std::unique_ptr<boost::asio::ip::tcp::socket> m_socket;
  std::array<std::uint8_t,1024> m_buffer;
  std::vector<std::uint8_t> m_data;
  terminate_cb_t m_terminate_cb;

protected:
  virtual bool start_impl();
  virtual size_t process_input_impl(std::uint8_t const*, size_t bufl) = 0;

  void send_output(std::uint8_t const*, std::size_t);
  void terminate_session();

  
public:
   static std::unique_ptr<self_t> create_server(boost::asio::io_service&);
   static std::unique_ptr<self_t> create_client(boost::asio::io_service&);
};

typedef std::unique_ptr<session> uptr_session;
}
#endif
