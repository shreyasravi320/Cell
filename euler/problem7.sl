use "std/std.sl"

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10001st prime number?

def N 10001 end
def count mem end
def primes count 8 + end

def isPrime
    0
    while
        dup2 8 * primes + @64 dup * >= if
            dup2 8 * primes + @64 mod 0 !=
        else
            fls
        end
    do 
        1 + 
    end
    8 * primes + @64 dup * <
end

def addPrime
  primes count @64 8 * + swap !64
  count inc64
end

2 addPrime

3 while count @64 N < do
  dup isPrime if dup addPrime end
  2 +
end drop

primes N 1 - 8 * + @64 dump
