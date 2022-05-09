#include <iostream>
#include <chrono>
#include <type_traits>
#include <string>

// external unmodifiable tests

struct Accumulate
 {
  char const * const title
   {"Test accumulating 0.1"} ;
  void operator()() const
   {
    std::cout.precision(18) ;
    double acc {} ;
    for ( int i = 0 ; i<10 ; ++i )
     {
      acc += 0.1 ;
      std::cout<<acc<<std::endl ;
    }
   }
 } ;

// your categories

struct TestTag {} ;
struct TestChronoTag {} ;

// your additional tests

struct StringCopy
 {
  using category = TestChronoTag ;
  char const * const title
   {"Timing a std::string copy"} ;
  void operator()() const
   {
    std::string s1 {"dummy"}, s2 ;
    for ( int i = 0 ; i<1000 ; ++i )
    {
     if (i%2) s2 = s1 ;
     else s1 = s2 ;
    }
   }
 } ;

struct StringMove
 {
  using category = TestChronoTag ;
  char const * const title
   {"Timing a std::string move"} ;
  void operator()() const
   {
    std::string s1 {"dummy"}, s2 ;
    for ( int i = 0 ; i<1000 ; ++i )
     {
     if (i%2) s2 = std::move(s1) ;
     else s1 = std::move(s2) ;
     }
   }
 } ;
 
// traits

template< typename TestT >
struct TestTraits
 { using category = typename TestT::category ; } ;

template<>
struct TestTraits<Accumulate>
 { using category = TestTag ; } ;

// execution generic framework

template< typename TestT >
void execute_single_test()
 {
  TestT test ;

  std::cout<<std::endl ;
  std::cout<<"== " ;
  std::cout<<(test.title)<<std::endl ;

  if constexpr (std::is_same_v<typename TestTraits<TestT>::category,TestChronoTag>)
   {
    using namespace std::chrono ;
    auto t1 = steady_clock::now() ;
   
    test() ;
     
    auto t2 = steady_clock::now() ;
    std::cout<<"Execution time: "
      <<duration_cast<microseconds>(t2-t1).count()
      <<" us."<<std::endl ;
   }
  else if constexpr (std::is_same_v<typename TestTraits<TestT>::category,TestTag>)
   { test() ; }
 }

template< typename... TestTs >
void execute()
 { ( execute_single_test<TestTs>() , ... ) ; }

// main program

int main()
 {
  execute<StringCopy,StringMove,Accumulate>() ;
 }
