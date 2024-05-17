//--------------------------------Stamp-------------------------------
//^-^ Author: Zhi Heng            Email: wy187110@mail.ustc.edu.cn     
//^-^ Time: 2024-05-15 17:23:30   Posi: Hefei
//^-^ File: main.cpp
//--------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>

#include "comms/process.h"
#include "comms/iterator.h"
#include "comms/cast.h"

#include "adas/Message.h"
#include "adas/frame/Frame.h"

struct HHandle;
using comms_message = adas::Message<
  comms::option::app::ReadIterator<const std::uint8_t*>,
  comms::option::app::WriteIterator<std::back_insert_iterator<std::vector<std::uint8_t>>>,
  comms::option::app::LengthInfoInterface,
  comms::option::app::IdInfoInterface,
  comms::option::app::NameInterface,
  comms::option::app::Handler<HHandle> >;
using Msg1 = adas::message::Msg1<comms_message>;
struct HHandle{
  void handle(comms_message& msg){
    std::cout<<msg.name()<<" "<<(unsigned)msg.getId()<<std::endl;
  }

  void handler(Msg1& msg){
    std::cout<<msg.name()<<" "<<(unsigned)msg.getId()<<std::endl;
  }

};


using std::cout; using std::endl; using std::string; using std::vector;
int main(int argc, char* argv[]){
  //typedef typename adas::Message<
  //  comms::option::ReadIterator<std::uint8_t const*>
  //  comms::option::app::WriteIterator<std::back_insert_iterator<std::vector<std::uint8_t>>>,
  //  ,comms::option::LengthInfoInterface
  //  ,comms::option::IdInfoInterface
  //  ,comms::option::NameInterface
  //> comms_message_t;
  using comms_frame = adas::frame::Frame<comms_message>;


  std::string fname = "/home/wangying/work/mis/others/ADAS/run-40.dat";
  auto* fp = fopen(fname.c_str(),"r");
  uint8_t data[4096];
  fread(data,sizeof(uint8_t),4096,fp);

  std::vector<uint8_t> data_adapt;
  data_adapt.emplace_back(0xAA);
  data_adapt.emplace_back(0xBB);
  data_adapt.emplace_back(0xCC);
  for (auto&& x : data) data_adapt.emplace_back(x);
  uint8_t const* addr = reinterpret_cast<uint8_t const*>(data_adapt.data());
  Msg1 msg1;
  std::cout<<(unsigned)msg1.field_f0().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f1().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f2().value().size()<<std::endl;
  std::cout<<(unsigned)msg1.field_f3().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f4().value()<<std::endl;
  comms_frame frame_d;
  comms::processSingle(addr,data_adapt.size(),frame_d,msg1);
  std::cout<<(unsigned)msg1.field_f0().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f1().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f2().value().size()<<std::endl;
  std::cout<<(unsigned)msg1.field_f3().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f4().value()<<std::endl;

  //HHandle handler;
  //auto result = comms::processAllWithDispatch(addr,data_adapt.size(),frame_d,handler);
  //std::cout<<(unsigned)msg1.field_f0().value()<<std::endl;



  fclose(fp);
  using comms_message_1 = adas::Message<
    comms::option::app::ReadIterator<const std::uint8_t*>,
    comms::option::app::WriteIterator<std::uint8_t*>,
    comms::option::app::LengthInfoInterface,
    comms::option::app::IdInfoInterface,
    comms::option::app::NameInterface>;
  typedef adas::frame::Frame<comms_message_1> frame1_t;
  frame1_t frame1;
  comms::processSingle(addr,data_adapt.size(),frame1,msg1);
  std::cout<<(unsigned)msg1.field_f0().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f1().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f2().value().size()<<std::endl;
  std::cout<<(unsigned)msg1.field_f3().value()<<std::endl;
  std::cout<<(unsigned)msg1.field_f4().value()<<std::endl;

  //comms_message_1 message_1;




  return 0;
}
// /home/wangying/software/gcc-13.2.0-build/bin/g++ -std=c++23 -pthread -Wall -fPIC -Wall -O3 -rdynamic -I/home/wangying/software/comms-build/include -I/home/wangying/work/mis/others/comms/adas/adas/include main.cpp -o main -Wno-deprecated-declarations
