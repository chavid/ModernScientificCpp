include <iostream>
#include <fmt/format.h>

struct Vector3d { double x, y, z ; };

template <> struct fmt::formatter<Vector3d> : formatter<double> {

  char sep ;
  constexpr auto parse(format_parse_context& ctx) {
    auto it = ctx.begin(), end = ctx.end();
    if (it != end && *it != '}')
     { sep = *it++ ; ctx.advance_to(it) ; }
    return formatter<double>::parse(ctx) ;
  }
      
  // Formats the point p using the parsed format specification (presentation)
  // stored in this formatter.
  template <typename FormatContext>
  auto format( Vector3d const & v, FormatContext & ctx ) const -> decltype(ctx.out()) {
    format_to(ctx.out(),"vector: ") ;
    formatter<double>::format(v.x,ctx) ;
    format_to(ctx.out(),"{}",sep) ;
    formatter<double>::format(v.y,ctx) ;
    format_to(ctx.out(),"{}",sep) ;
    formatter<double>::format(v.z,ctx) ;
    return ctx.out() ;
  }
};
        
int main()
 {
  Vector3d v { 1./2., 2./2., 2./3. } ;
  std::string txt = fmt::format("{:|.3f}",v) ;
  std::cout<<txt<<std::endl ;
 }