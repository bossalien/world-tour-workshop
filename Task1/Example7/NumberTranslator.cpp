#include "NumberTranslator.h"
#include <assert.h>

using namespace std;

NumberTranslator::NumberTranslator() {
   // Initialize translations
   
   // Single digit translations
   _traslationTable.reserve(27);
   _traslationTable.push_back("zero");
   _traslationTable.push_back("one");
   _traslationTable.push_back("two");
   _traslationTable.push_back("three");
   _traslationTable.push_back("four");
   _traslationTable.push_back("five");
   _traslationTable.push_back("six");
   _traslationTable.push_back("seven");
   _traslationTable.push_back("eight");
   _traslationTable.push_back("nine");

   // Second digit translation
   // Digits from 10 to 19 are especial
   _traslationTable.push_back("ten");
   _traslationTable.push_back("eleven");
   _traslationTable.push_back("twelve");
   _traslationTable.push_back("thirteen");
   _traslationTable.push_back("fourteen");
   _traslationTable.push_back("fifteen");
   _traslationTable.push_back("sixteen");
   _traslationTable.push_back("seventeen");
   _traslationTable.push_back("eighteen");
   _traslationTable.push_back("nineteen");
   // The rest of the leading numbers
   _traslationTable.push_back("twenty");
   _traslationTable.push_back("thirty");
   _traslationTable.push_back("fourty");
   _traslationTable.push_back("fifty");
   _traslationTable.push_back("sixty");
   _traslationTable.push_back("seventy");
   _traslationTable.push_back("ninety");
}

//__________________________________________________________________

NumberTranslator::~NumberTranslator() {
   // Nothing to do
}

//__________________________________________________________________

vector<unsigned int> NumberTranslator::reversedDigits(int value) {
   // We get each digit by the method of successive divisions.
   int digitValue;
   vector<unsigned int> digits;
   do {
      digitValue = value % 10;
      value /= 10;
      digits.push_back(digitValue % 10);
   } while(value != 0);

   // Return the result
   return digits;
}

//__________________________________________________________________

// Given a number between 0 and 30, translate it to it's word form
std::string NumberTranslator::translate(int number) {
   // We are just translating numbers from 0 to 30
   assert(number >= 0 && number <= 30);

   string word;
   if(number < 20) {
      word = _traslationTable[number];
   }
   else {
      // Get the digits in reverse order
      vector<unsigned int> digits = reversedDigits(number);
      // Store the size to avoid unnecessary calls
      unsigned int nbDigits = digits.size();
       
      // Fetch the next digit, we now for a fact that at least
      // it's going to be a 2 (for twenty), hence count from
      // 18 to match the trasnlation in the table
      unsigned int digitValue = digits[1];
      string doubleDigit = _traslationTable[18 + digitValue];

      // Fetch the single digit value. If it's a zero, we
      // are not interested in it
      digitValue = digits[0];
      if(digitValue > 0) {
         string singleDigit = _traslationTable[digitValue];
         word = doubleDigit + "-" + singleDigit;
      }
      else {
         word = doubleDigit;
      }
   }

   return word;
}

