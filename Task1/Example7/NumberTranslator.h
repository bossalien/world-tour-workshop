#ifndef _NUMBER_TRANSLATOR_H_
#define _NUMBER_TRANSLATOR_H_

#include <string>
#include <vector>

/**
Translates numbers to words. It's limited to thirty numbers although the
algorithm works for any number between 0 and 99.

@date January, 2014
*/
class NumberTranslator {
public:

   /** Default constructor. */
   NumberTranslator();

   //__________________________________________________________________

   /** Default destructor. */
   ~NumberTranslator();

   //__________________________________________________________________

   /**
   Given a number between 0 and 30 it translates
   the number to a word.

   @param number Number that is going to be translated.
   @return The number as a word.
   */
   std::string translate(int number);

private:

   /**
   Split and reverse digits.

   @param value Number that we want to split and reverse.
   @return A vector with the separated digits reversed.
   */
   std::vector<unsigned int> reversedDigits(int value);

   //__________________________________________________________________

   // Translation table for numbers
   std::vector<std::string> _traslationTable;
};

#endif