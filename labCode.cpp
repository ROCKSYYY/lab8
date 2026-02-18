/************************
* Автор: Долинин Н.К.   *  
* Название: Вариант 5   *
*************************/

#include <iostream>
#include <string>

using namespace std;

bool checkingRomanOrArabicNumber(string theEnteredStringWithTheNumber) {
  if (theEnteredStringWithTheNumber.empty()) {
    return false;
  }
  
  for (int numberVerificationCounter = 0; numberVerificationCounter < theEnteredStringWithTheNumber.length(); numberVerificationCounter++) {
    char currentChar = theEnteredStringWithTheNumber[numberVerificationCounter];
    
    if (!isdigit(static_cast<unsigned char>(currentChar))) {
      return false;
    }
  }
  return true;
}

int getRomanValue(char arabChar) {
  switch (arabChar) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

int main() {
  int arabicVals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string romanVals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  string inputNumber;
  int integerRomanNumber, arabResult, secondArabNumber, anAdditionalUnitForArabicNumbers, theNumberOfNumbersInTheArray, minimumArabicNumber, maximumArabicNumber;
  bool errorArabNumber;
  
  cout << "Введите число (арабское или римское): ";
  cin >> inputNumber;
  
  anAdditionalUnitForArabicNumbers = 1;
  theNumberOfNumbersInTheArray = 13;
  minimumArabicNumber = 0;
  maximumArabicNumber = 4000;
  
  if (checkingRomanOrArabicNumber(inputNumber)) {
    integerRomanNumber = stoi(inputNumber);
    if (integerRomanNumber <= minimumArabicNumber || integerRomanNumber >= maximumArabicNumber) {
      cout << "Ошибка: число должно быть от 1 до 3999" << endl;
    } else {
      string romResult = "";
      
      for (int romCounter = 0; romCounter < theNumberOfNumbersInTheArray; ++romCounter) {
        while (integerRomanNumber >= arabicVals[romCounter]) {
          romResult += romanVals[romCounter];
          integerRomanNumber -= arabicVals[romCounter];
        }
      }
      cout << "Римское число: " << romResult << endl;
    }
  } else {
    arabResult = 0;
    errorArabNumber = false;
    
    for (int arabCounter = 0; arabCounter < inputNumber.length(); ++arabCounter) {
      int firstarAbNumber = getRomanValue(inputNumber[arabCounter]);
      
      if (firstarAbNumber == 0) {
        errorArabNumber = true;
        break;
      }
      if (arabCounter + anAdditionalUnitForArabicNumbers < inputNumber.length()) {
        secondArabNumber = getRomanValue(inputNumber[arabCounter + anAdditionalUnitForArabicNumbers]);
        if (firstarAbNumber < secondArabNumber) {
          arabResult -= firstarAbNumber;
        } else {
          arabResult += firstarAbNumber;
        }
      } else {
        arabResult += firstarAbNumber;
      }
    }
    if (errorArabNumber) {
      cout << "Ошибка: Введены некорректные символы!" << endl;
    } else {
      cout << "Арабское число: " << arabResult << endl;
    }
  }
  return 0;
}
