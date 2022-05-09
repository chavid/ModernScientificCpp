/*
Simple, mais il manque l'espace entre les affichages :

  template < typename ... Args >
  void show_args( Args ... args )
   { ( std::cout << ... << args ) << std::endl ; }

Avec l'aide d'une fonction auxiliaire :

  template < typename Type >
  std::string add_space( Type value )
   { std::ostringstream oss ; oss<<value<<' ' ; return oss.str() ; }
  
  template < typename ... Args >
  void show_args( Args ... args )
   { ( std::cout << ... << add_space(args) ) << std::endl ; }

Plus rusé, en s'appuyant sur l'opérateur virgule `,` :

  template <typename ... Args>
  void show_args( Args ... args )
   {
    ( ( std::cout << args << ' ' ) , ... , ( std::cout << std::endl ) ) ;
   }
*/