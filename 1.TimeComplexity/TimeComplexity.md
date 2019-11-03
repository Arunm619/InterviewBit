# Time Complexity

Time complexity related questions might not be asked directly to you in the interview.
However, all interview conversations have been known to end with :
  - “Whats the time complexity of the solution ?”
  - “Can you improve the time complexity of your solution ?”
  which is why its essential for us to understand the basics of time and space complexity.

So we will try to go over the relevance of time and space complexity and a few nitty gritties around them.


# How To Calculate Running Time?

  - Time complexity PlayList [My Code School](https://www.youtube.com/watch?v=V42FBiohc6c&list=PL2_aWCzGMAwI9HK8YPVBjElbLbI3ufctn)
  - Gaurav Sen [Youtube](https://www.youtube.com/watch?v=MTl8djZFWE0&list=PLMCXHnjXnTnszR6YSo1tQK2BMr15cC9Zh&index=15)



# Space Complexity
Space complexity is a measure of how efficient your code is in terms of memory used.
Space complexity analysis happens almost in the same way time complexity analysis happens.


    vector<int> V;
    for (int i = 0; i < N; i++) V.push_back(i);
    The code snippet ends up creating a vector of size N. So, space complexity of the code is O(N).

Additional space / memory is measured in terms of the largest memory use by the program when it runs. That is to say, if you allocated O(N) memory, and later free it, that does not make the space complexity of your program O(1).

### Relevance Of Time Complexity
Lets assume we ask 2 interviewees A and Bto write a program to detect if a number N >= 2 is prime.

 A number is prime if it is divisible by exactly 2 distinct positive numbers 1 and the number itself.
 https://www.mathsisfun.com/prime-composite-number.html

A comes up with the following code :

     i = 2
     while i < N
       if N is divisible by i
          N is not prime
       add 1 to i
B comes up with the following code :

    i = 2
    while i < square root of N
      if N is divisible by i
        N is not prime
      add 1 to i
For now, lets assume that both codes are correct.
Now, B claims that his code is much better as it takes much less time to check if N is prime.
Lets look into why that is the case.

Lets assume that the operation N is divisible by i takes 1 ms.
Lets look at few examples on time taken :

    Example 1 :
    N = 1000033 ( Prime number )
    Time taken by A's program = 1 ms * number of divisions
                              = 1 ms * 1000033
                              = approximately 1000 seconds or 16.7 mins.

    Time taken by B's program = 1ms * number of divisions
                              = 1ms * square root of 1000033
                              = approximately 1000ms = 1 second.
    Example 2 :

    N = 1500450271 ( Prime number )
    Time taken by A's program = 1 ms * number of divisions
                              = 1 ms * 1500450271
                              = approximately 1000000 seconds or 11.5 days

    Time taken by B's program = 1ms * number of divisions
                              = 1ms * square root of 1500450271
                              = approximately 40000ms = 40 seconds.
As you can see B’s program is significantly faster even though both methods of solving the problem are correct.
This is where time complexity of programs comes in, which is a measure of how efficient ( or quick ) a program is for large inputs.
In first case, time taken is directly proportional to N, whereas in second case it is directly proportional to square root of N. In later slides, we will look into how we can formalize it into time complexity notations.