Code Challenge
============

###Intro

Thank you for spending some of your valuable time to take this small code challenge!
At enfore we work using agile methods but not straight from the book. Nevertheless we keep to common terms from the agile world and expect from every member of the team an active contribution to the overall process. So please also demonstrate an important part of agile development in terms of transparency. Tell us about your ideas, thoughts and worries! Please also tell us why you left out parts or focused on others. In our opinion an open communication the key for teamwork.


###Definition of done
* every aspect of the story covered
* all acceptance criteria are met
* tests achieve 100 % code coverage
* no usage of C++ STL

###Epic
The enfore product team has an idea of a new device that will probably utilize a Cortex-M3 and FreeRTOS, but further details are still tbd. The engineering team should make basic preparations for this as the product team expects several PoCs soon.

###Story EMB-1
As an embedded developer I need an easy API to UART that is mapped to certain registers.

*for further details, see emb1.c*


###Story EMB-2
As an embedded developer I want to use a memory allocator that is based on a meaningful block-size that also avoids memory fragmentation.

*for further details, see emb2.cxx*


###Store EMB-3
As an embedded developer and as a build and release engineer I expect to build the product via GNU *Makefile*.

*Acceptance Criteria*
* Single Makefile
* Makefile compiles emb1.c
* Makefile compiles emb2.cxx
* output of emb2.cxx is executable
