# Matrix_Multiplication

# Design Decisions 

- Want to be able to add new algorithms easily using the Strategy pattern
    - All have the same itnerface
    - able to interchange them easily
    - Get Context from an object, Matrix object
- Matrix Object
    - 
- Want to be able to test these algorithms
    - Easily add testcases
    - Generate the answer for it
    - Measure accuracy and time easily per algorithm
    - Record results 
- Want to generate testcases
    - Make matrices from a file input
    - Make test cases from matrices mixing and matching them
    - generate answers instead of storing it in a file
    - want the ability to make testcases and store them into files
- Context
    - holds matrix1 and matrix2
    - in generateTestcases we make the matrices we use naive to fill in the answer matrix
- GenerateResults calls everything to do their parts.
    - generate testcases and make the matrices context
    - go through all stategies and measure the accuracy and time, want to be able to add more testing if needed like maybe memory usage of the algorithm
    - record the results into a file
- GenerateResults is a client
- The examples are clients they can use our context and strategies

- not sure if I want the answer to be in the context since it doesnt make sense for other clients, could keep the answer in generate results

