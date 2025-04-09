# 
# Questions powered by:
# - https://github.com/jmshea/jupyterquiz 2.7.0a4
# - https://github.com/jmshea/jupytercards 2.7.0a4
#

questions_dict = {

#===================================================

'BasicChallenge': {
  'type': 'multiple_choice', 
  'question': '1. What is displayed ?',
  'answers': [
    { 'answer': 'It will fail to compile MyInteger', 'correct': True, 'feedback': 'True. The final ";" is lacking' },
    { 'answer': 'There will be a runtime error', 'correct': False },
    { 'answer': 'A random value', 'correct': False, 'feedback': 'Wrong. The constructor provides a default 0 value.' },
    { 'answer': '0', 'correct': False, 'feedback': 'Wrong. The expected value is 0, yet it will not be displayed. Why ?' },
    { 'answer': 'It will fail to compile main()', 'correct': True, 'feedback': 'Right ! This is the famous "most vexing parse" : for some historical reason, an expression such as "MyInteger mi() ;" is interpreted as a function declaration.' }
  ],
  'code':
'''#include &lt;iostream>

struct MyInteger {
  MyInteger( int i = 0 ) : i_(i) {}
  int i_ ;
}

int main() {
  MyInteger mi() ;
  std::cout&lt;&lt;mi.i_&lt;&lt;std::endl ;
}
'''
},

#===================================================

'DynamicMemory': {
  'type': 'multiple_choice', 
  'question': '2. Should I copy such an array?',
  'answers': [
    { 'answer': 'Yes. The copy constructor is added by the compiler', 'correct': False, 'feedback': 'the implicit copy constructor is perforing a shallow copy, not relevant here.' },
    { 'answer': 'No. The operator=() is lacking', 'correct': True, 'feedback': 'when dynamic resources are involved (here heap memory), one must redefine the copy constructor, the copy assignment operator... and also now the move constructor and the move assignment operator.' },
    { 'answer': 'No. The copy constructor is lacking', 'correct': True, 'feedback': 'when dynamic resources are involved (here heap memory), one must redefine the copy constructor, the copy assignment operator... and also now the move constructor and the move assignment operator.' },
    { 'answer': 'Core dumped or segmentation fault ensured', 'correct': True, 'feedback': 'also true !' },
    { 'answer': 'Yes. But there is a memory leak', 'correct': False, 'feedback': 'the problem here is not memory leak, but shared memory which will be deleted several times.' },
    { 'answer': 'Yes. Thanks to explicit','correct': False, 'feedback': 'off-topic ; "explicit" is there in order to forbid an implicit compiler conversion between an "unsigned" and an "Array".'  }
  ],
  'code':
'''class Array {
  public :
    explicit Array( std::size_t s ) { data_ = new double [s]; }
    double & operator[]( std::size_t i ) { return data_[i]; }
    ~Array() { delete [] data_; }
  private :
      double * data_;
 } ;
'''
},


#===================================================

'Conversions': {
  'type': 'multiple_choice', 
  'question': '3. What is displayed?',
  'answers': [
    { 'answer': 'There will be a compilation error', 'correct': False, 'feedback': '' },
    { 'answer': 'There will be an error at runtime', 'correct': False, 'feedback': '' },
    { 'answer': '"i is less than j"', 'correct': False, 'feedback': '' },
    { 'answer': '"i is greater than j"', 'correct': True, 'feedback': 'Yes ! When interpreting "i < j", the compiler convert all the numbers "unsigned int", which it considers more accurate than "int", then the value "-1" becomes the highest possibel value than an "unsigned int" can have, therefore greater than "1". Damned !'  }
  ],
  'code':
'''#include &lt;iostream>

int main() 
  {
    int i = -1 ;
    unsigned int j = 1 ;
    if ( i &lt; j ) std::cout &lt;&lt; "i is less than j" ;
    else std::cout &lt;&lt; "i is greater than j" ;
    return 0 ;
  }
'''
},


#===================================================

'Inheritance': {
  'type': 'multiple_choice', 
  'question': '4. What is displayed ?',
  'answers': [
    { 'answer': 'There will be a compilation error', 'correct': False, 'feedback': '' },
    { 'answer': 'There will be an error at runtime', 'correct': False, 'feedback': '' },
    { 'answer': '3', 'correct': True, 'feedback': 'Yes ! When interpreting "b.m(3.14)", the compiler find some "m" function within class "B", and then does not check if the base class has some better matching function.' },
    { 'answer': '3.14', 'correct': False, 'feedback': '' },
  ],
  'code':
'''#include &nbsp;iostream>

struct A {
  void m( double d )   
   { std::cout &lt;&lt; d &lt;&lt; std::endl ; }
} ;

struct B : public A {
  void m( int i )
   { std::cout &lt;&lt; i &lt;&lt; std::endl ; }
} ;

int main()
 {
  B b;
  b.m(3.14);
  return 0;
 }
'''
},

#===================================================

'FloatingPoint': {
  'type': 'multiple_choice', 
  'question': '5. Why is it returning false?',
  'answers': [
    { 'answer': 'Never iterate with a real variable (index)', 'correct': False, 'feedback': '"never" is overkill, one sometimes needs to.' },
    { 'answer': 'Never compare floats with ==', 'correct': True, 'feedback': 'As a general rule, floating operations are never perfectly exacts ; any floating comparison should allow an epsilon error.' },
    { 'answer': 'Some curly braces are lacking', 'correct': False, 'feedback': 'Some curly braces would make the code more readable, but that is not the issue here.' },
    { 'answer': '1.0 is a double', 'correct': True, 'feedback': 'Best answer here, because "1.0" is a double, the result of "index / ( index + 1.0 )" is a double, and will not match the value stored in "ref", which is a float ; try with "1.0f", or "static_cast<float>( index / ( index + 1.0 ) )".' },
    { 'answer': 'Index value is never exactly 169.0', 'correct': False, 'feedback': 'Nice try ;) actually no, because the step of "1.0" is 2 power 0, it can be exactly encoded in binary basis, and the last value of "index" will exactly be "169.0" ; if the step was "0.1", for example, the value of ìndex" would never be exactly "169.0".' },
  ],
  'code':
'''bool check()
 {
  float ref, index ;
  ref = 169.0 / 170.0 ;
  for ( index = 160.0 ; index &lt; 170.0 ; index += 1.0 )
      if ( ( index / ( index + 1.0 ) ) == ref )
          return true ;
  return false ;
 }
'''
},

#===================================================

'Polymorphism': {
  'type': 'multiple_choice', 
  'question': '6. What is lacking below?',
  'answers': [
    { 'answer': 'One "virtual"', 'correct': True, 'feedback': 'The destructor should be virtual, because "display()" is.' },
    { 'answer': 'Several "virtual"', 'correct': False, 'feedback': 'Which ones ??' },
    { 'answer': 'A "private" zone', 'correct': False, 'feedback': 'A private zone is not mandatory.' },
    { 'answer': 'The body of display()', 'correct': False, 'feedback': 'Off-topic ; that is an abstract class, not all the functions needs to be implemented.' },
  ],
  'code':
'''class A {
  public :
    A() {}
    ~A() {}
    virtual void display() = 0 ; 
} ;
'''
},

#===================================================

}

import random
import time
current_time = int(time.time())
random.seed(current_time)

import argparse
parser = argparse.ArgumentParser(description='display questions for a quiz')
parser.add_argument('-n', default=0, dest='nb', help='number of random questions to display')
parser.add_argument('names', nargs='*', default=[''],help='the list of questions to be displayed')
args = parser.parse_args()

if args.names==['']:
  questions_list = list(questions_dict.values())
else:
  questions_list = [questions_dict[name] for name in args.names]
random.shuffle(questions_list)

from jupyterquiz import display_quiz
if args.nb==0:
  display_quiz(questions_list, question_alignment='left', max_width=1000, shuffle_answers=False )
else:
  display_quiz(questions_list, args.nb, question_alignment='left', max_width=1000, shuffle_answers=False )

