#include <iostream>
#include <chrono>
#include <unistd.h>
#include "generateTestCases/generateTestCases.h"
#include "generateAnswers/generateAnswers.h"
#include "generateResults/generateResults.h"
#include "../include/naive.h"

#include "../include/dacThread.h"





/**

*/
int main(int argc, char* argv[]){
    generateTestCase("testcase", 987, 100, 10, 10, 999, 100, 10, 10);
    //generateAllAnswers(); 
    //getAllAlgorithmResults();
    return EXIT_SUCCESS;
}
