#include <iostream>
#include <chrono>
#include <unistd.h>
#include "generateTestCases/generateTestCases.h"
#include "generateAnswers/generateAnswers.h"
#include "generateResults/generateResults.h"
#include "algorithms/dacThread/dacThread.h"
#include "algorithms/naive/naive.h"


/**
    TODO 
    1. Generate Test Cases
    2. Put test cases into files
    3. read those files
    4. insert those testcases into naive approach and make answers
    5. Comments
    6. ReadMe's
    7. finish Divide and Conquer
    7.5. Add threads
    8. make another file that will be Strassen 7 algos
    9. strassen 7 algos in threads
*/


/**

*/
int main(int argc, char* argv[]){
    //generateTestCase("testcase", 987, 100, 5, 5, 999, 100, 5, 5);
    //generateAllAnswers(); 
    getAllAlgorithmResults();

    return EXIT_SUCCESS;

}
