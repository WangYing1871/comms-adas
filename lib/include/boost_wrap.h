#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <string>
#include <array>
#include <utility>
#include <sstream>
#include <stdexcept>
#include <concepts>
#include <climits>
#include <mutex>
#include <iomanip>

#include <boost/version.hpp>
#include <boost/asio.hpp>
#include <boost/type_index.hpp>
#define type_name(x) std::cout<<std::dec<<boost::typeindex::type_id<decltype(x)>().pretty_name()<<"sizeof:"<<sizeof(decltype(x))<<std::endl;
#define info_out(X) std::cout<<std::dec<<"==> "<<__LINE__<<"\t["<<"]"<<#X<<" |"<<(X)<<"|\n"
namespace boost_wrap{

template <class _tp>
void post(boost::asio::io_service& i, _tp&& func) { boost::asio::post(i,std::forward<_tp>(func)); }

}
