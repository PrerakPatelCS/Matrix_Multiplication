main: main.cpp generateTestCases/generateTestCases.cpp generateAnswers/generateAnswers.cpp algorithms/naive/naive.cpp generateResults/generateResults.cpp
	g++ main.cpp generateTestCases/generateTestCases.cpp generateAnswers/generateAnswers.cpp algorithms/naive/naive.cpp generateResults/generateResults.cpp  -Wall -Wextra -o main

make clean:
	rm main
