#include <iostream>
#include <csignal>
#include <stdexcept>
#include <cassert>
#include "boost_wrap.h"

#include "tcp_client.h"

int main(int argc, const char* argv[]){
  static_cast<void>(argc);
  static_cast<void>(argv);
  try{
    boost::asio::io_service io;
    adas::tcp_client client(io);
    if (!client.start()){
      std::cerr << "Failed to start tcp server!" << std::endl; return -1; }
    boost::asio::signal_set ts(io,SIGTERM,SIGINT);
    ts.async_wait(
        [&io](boost::system::error_code const& ec, int signo){
          static_cast<void>(ec);
          assert(!ec);
          std::cerr << "Terminating tcp client due to signal " << signo << std::endl;
          io.stop(); }
        );
    io.run();
  }catch(std::exception const& e){
    std::cerr << "Unexpected exception in tcp client: " << e.what() << std::endl;
    return -1;
  }
}
