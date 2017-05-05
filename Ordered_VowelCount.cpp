/* 
We have a dictionary in txt format (attached). 
An ordered word is one that has vowels in alphabetical order ( A,E,I,O,U)
     Bbc:                 Not ordered as no vowel, vowel count=0
     Aeue:              Not ordered as U comes before E, vowel count=4
     ABC :                Ordered (Only 1 Vowel so ordered ), vowel count=1
     Keep:               Ordered (Repeat vowels are always ordered), vowel count=2
     Ended:            Ordered, vowel count=2
     Ending:           Ordered, vowel count=2
*/

#include <iostream>
#include <fstream>
#include <ctype.h>
int N = 20;
int VOWEL_COUNT[20] = {0};

int Count_Vowels(char  word[]) {
	int count = 0;
	char Prev_Vowel = 'a';
	char case_letter;
	for(int i= 0; i< strlen(word);i++) {
		case_letter = tolower(word[i]);
		if(case_letter == 'a' || case_letter == 'e' || case_letter == 'i' || case_letter== 'o'|| case_letter=='u') {	
			if((Prev_Vowel > case_letter)) {
				count = 0;
				break;
			}	
			count++;
			Prev_Vowel = case_letter;
		}
	}
	return count;
}

int main()
{
	std::ifstream in("words.txt");

  if(!in) {
    std::cout << "Cannot open input file.\n";
    return 1;
  }

  char str[255];
  int max =0; // Variable which holds max vowel count. 

  //Actual logic starts here
  while(in) {
    in.getline(str, 255);  // delim defaults to '\n'
    if(in) {
		int count = Count_Vowels(str);
		if(count > max)
			max = count;
		VOWEL_COUNT[count] =VOWEL_COUNT[count] + 1;
	}
  }

  //Below code is for Display Output logic
  std::cout<<"[";
  for(int i = 1; i<=max;i++){
	  std::cout<<VOWEL_COUNT[i];
		if(i!=max)
			std::cout<<",";
  }
  std::cout<<"]";

  in.close();
	return 0;
}

