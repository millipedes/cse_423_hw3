# Full Test Suite
Author: Matthew C. Lindeman

# Usage
The following tests conducted will meet most (as I am not perfect there may be
something that I missed, but this should be most all cases) if not all
requirements of the puny language.

The tests should be conducted as:
********************************************************************************
                                 SECTION 1
********************************************************************************
  ==============================================================================
    $ ./puny ./error_messages/01keywords.py
    AND
    $ ./puny ./error_messages/01keywords
  Passing this test will infer that you can recognize all keywords and operators
  (note that your program should error on: is, in, bitwise operators, so if you
  have a working error system already you should remove those keywords from this
  file).
  Also note that this is the only python program that the python interpreter
  will not accept in this suite simply because it is just a mash up of all
  keywords.
  ==============================================================================
    $ ./puny ./tests/02bcs_one.py
    AND
    $ ./puny ./tests/02bcs_one
  Passing this test will ensure that you have correct identifier recognition
  (NAME token type/int code).
  ==============================================================================
    $ ./puny ./tests/03numbers.py
    AND
    $ ./puny ./tests/03numbers
  Note here that there is a super tricky case, lines 7 and 8 should have a dval,
  NOT and ival. Aside from that there should be all cases of numbers here tmk.
  ==============================================================================
    $ ./puny ./tests/04strings.py
    AND
    $ ./puny ./tests/04strings
  This should ensure that strings are working (double check the svals).
  Note that errors are handled elsewhere.
  ==============================================================================
    $ ./puny ./tests/05cs_one.py
    AND
    $ ./puny ./tests/05cs_one
  This tests control structure only in that is tests single indents.
  ==============================================================================
    $ ./puny ./tests/06cs_two.py
    AND
    $ ./puny ./tests/06cs_two
  This tests control structures such that there is single level dedents.
  ==============================================================================
    $ ./puny ./tests/07cs_three.py
    AND
    $ ./puny ./tests/07cs_three
  This tests control structures such that there are multiple dedents into
  newlines into text on char 1 of the line (this is several edge cases all in
  one, if you are struggling here take out all the newlines between the first
  char func and where the dedents occur, fix that and then try the multiple
  newlines). Also notice all of the trailing newlines.
  ==============================================================================
    $ ./puny ./tests/14cs_four.py
    AND
    $ ./puny ./tests/14cs_four
  Same as 07 except with literal tabs instead of just spaces.
  ==============================================================================
********************************************************************************
                                 SECTION 2
********************************************************************************
The error checking section.
  ==============================================================================
    $ ./puny ./error_messages/08reserved_word_one.py
    AND
    $ ./puny ./error_messages/08reserved_word_one
  This tests the keyword is.
  ==============================================================================
    $ ./puny ./error_messages/09reserved_word_two.py
    AND
    $ ./puny ./error_messages/09reserved_word_two
  This tests the keyword in.
  ==============================================================================
    $ ./puny ./error_messages/10reserved_word_three.py
    AND
    $ ./puny ./error_messages/10reserved_word_three
  This tests the keyword type.
  ==============================================================================
    $ ./puny ./error_messages/11reserved_word_four.py
    AND
    $ ./puny ./error_messages/11reserved_word_four
  This tests the keyword await.
  ==============================================================================
    $ ./puny ./error_messages/12reserved_word_five.py
    AND
    $ ./puny ./error_messages/12reserved_word_five
  This tests the keyword #type.
  ==============================================================================
    $ ./puny ./error_messages/13reserved_word_six.py
    AND
    $ ./puny ./error_messages/13reserved_word_six
  This tests the keyword async.
  ==============================================================================
    $ ./puny ./error_messages/15unmatched_quote_one.py
    AND
    $ ./puny ./error_messages/15unmatched_quote_one.py
  This will test unmatched double quotes
  ==============================================================================
    $ ./puny ./error_messages/16unmatched_quote_two.py
    AND
    $ ./puny ./error_messages/16unmatched_quote_two.py
  This will test unmatched single quotes
  ==============================================================================
    $ ./puny ./error_messages/17operators.py
    AND
    $ ./puny ./error_messages/17operators
  Note here that each operator is commented and you will have to uncomment each
  line to test each op (It would be rediculous to have 18 files).
  ==============================================================================
    $ ./puny ./error_messages/18unmatched_exponential_operand_one.py
    AND
    $ ./puny ./error_messages/18unmatched_exponential_operand_one
  Test to see if you can detect an exponential notation without an operand.
  Again, same as last since multiple cases, need to comment each one.
  ==============================================================================
