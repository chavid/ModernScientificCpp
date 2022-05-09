#include <iostream>
#include <string_view>

// A framework for running tests

template< typename... TT > class Tuple ;
template<> class Tuple<> {} ;

template< typename T, typename... TT >
struct Tuple<T,TT...>
 {
  T first ;
  Tuple<TT...> others ;
 } ;
 
template< typename... TT > void run_all( const Tuple<TT...> & ) ;
template<> void run_all( Tuple<> const & tests ) {}

template< typename T, typename... TT >
void run_all( const Tuple<T,TT...> & tests )
 { 
  T const & test = tests.first ;
  std::cout<<test.title<<": "<<test.run()<<std::endl ;
  run_all(tests.others) ;
 }

// Demo use of the framework

struct IntIs32
 {
  const std::string title = "int is 32" ;
  bool run() const { return (sizeof(int)==4) ; } ;
 } ;
 
struct DoubleIs64
 {
  const std::string title = "double is 64" ;
  bool run() const  { return (sizeof(double)==8) ; } ;
 } ;
 
int main()
 {
  Tuple<IntIs32,DoubleIs64> tests ;
  run_all(tests) ;
  return 0 ;
}
