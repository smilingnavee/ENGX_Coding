/* Bracket Matcher

A bracket is considered to be any one of the following characters: (, ), {, }, [, ], < or >.
Two brackets are considered to be a matched pair if the an opening bracket i.e., (, [, <, or { occurs to the left of a closing bracket i.e., ), ], >, or } of the exact same type. There are four types of matched pairs of brackets: [], {}, <>, and ().
A Balanced String will be the one, which will have the brackets matched in it.
*/
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <streambuf>
#include <stack> 

bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else if (character1 == '<' && character2 == '>')
     return 1;
   else
     return 0;
}

int areParenthesBalanced(const char  exp[], int &Pairs_count)
{
       std::stack<char> stack_frame;
       int i = 0;
       while (exp[i])
   {
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '['|| exp[i] == '<')
        stack_frame.push(exp[i]);

      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']'|| exp[i] == '>')
      {
             
          if (stack_frame.empty())
           return 0; 
 
          else if ( !isMatchingPair(stack_frame.top(), exp[i] ))
           return 0;
              Pairs_count++ ;
              stack_frame.pop();
      }
      i++;
   }
}

int main()
{
       int Total_Pairs = 0;
       std::ifstream in("inputString.txt");

       
std::string str;

in.seekg(0, std::ios::end);   
str.reserve(in.tellg());
in.seekg(0, std::ios::beg);

str.assign((std::istreambuf_iterator<char>(in)),
            std::istreambuf_iterator<char>());

const char* input = str.c_str();

int result = areParenthesBalanced(input, Total_Pairs);

       if(result)
    std::cout<<"Balanced: YES;";
  else
    std::cout<<"Balanced: YES;"; 
  std::cout<<"MatchingPairs:"<<Total_Pairs<<std::endl;

  
  return 0;
}
