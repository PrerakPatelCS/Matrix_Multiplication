main: main.cpp generateTestCases/generateTestCases.cpp generateAnswers/generateAnswers.cpp generateResults/generateResults.cpp algorithms/naive/naive.cpp  algorithms/dacThread/dacThread.cpp
	g++ main.cpp generateTestCases/generateTestCases.cpp generateAnswers/generateAnswers.cpp generateResults/generateResults.cpp algorithms/naive/naive.cpp  algorithms/dacThread/dacThread.cpp -Wall -Wextra -o main

make clean:
	rm main
