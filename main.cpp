#include <iostream>
#include <chrono>
#include <unistd.h>
#include "generateTestCases/generateTestCases.h"
#include "generateAnswers/generateAnswers.h"
#include "generateResults/generateResults.h"




/**
    TODO 
    1. Generate Test Cases
    2. Put test cases into files
    3. read those files
    4. insert those testcases into naive approach and make answers
*/



/**

*/
int main(int argc, char* argv[]){
    generateTestCase("testcase", 987, 100, 5, 5, 999, 100, 5, 5);
    generateAllAnswers(); 
    getNaiveResults();

    return EXIT_SUCCESS;

}
