// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "BMS_Sender/BMS_SenderStream.h"


TEST_CASE("Testcase to check input data from file") 
{
   BMS_inputtype inputvaluefetch = FileInputType;
   REQUIRE(inputvalue (inputvaluefetch) == E_OK);
}

/*TEST_CASE("Testcase to check if the console print is happening periodically") 
{
 
    BMS_inputtype inputvaluefetch = FileInputType;
    BMS_outputtype outputvaluefetch = printtoconsole;
    REQUIRE(inputvalue (inputvaluefetch) == E_OK);
    REQUIRE(outputvalue (outputvaluefetch) == E_OK);
}*/
