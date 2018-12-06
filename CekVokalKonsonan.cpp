#include <iostream>

using namespace std;

int main() {
  char c;
  
  cout << "Enter an alphabet: ";
  cin >> c;

  int isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  int isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

  if (isLowercaseVowel || isUppercaseVowel)
    cout << c << " is a vowel.";
  else if (int(c) >= 0) {
    cout << c << " is not a alphabet.";
  }
  else
    cout << c << " is a consonant.";

  return 0;
}
