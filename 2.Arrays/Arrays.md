# Arrays

 - My Code School [Basics](https://www.youtube.com/watch?v=h-HBipu_1P0&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

### Array Implementation Details
C style arrays work in C++ as well.

However, C++ provides vectors which is much more powerful than C arrays. We will be using C++ vectors in most of the problems on this judge.

Vector declaration :

        vector<int> V; // declares an empty integer array of size 0. O(1)
        vector<int> V(100, 1);
        // declares an integer array of size 100 with all elements initialized to 1. O(size)
Accessing ith element :

        V[i] // O(1)
Size ( number of elements ) of the vector :

        V.size()  // O(1)
Adding element to the vector :

        V.push_back(new_value); // new_value will be appended to the vector.  O(1)
Removing element from end of the vector :

        V.pop_back(); // equivalent to size--; O(1)


### Sorting Algorithms

[All Sorting Algorithms](https://gist.github.com/arun-sudharsan/42b9e554fbd199dd60ac201fd8051b4c)