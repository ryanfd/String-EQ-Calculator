module Recursive where

import Foreign.C.Types -- for foreign calls

foreign export ccall hailstone :: CInt -> CInt
hailstone::CInt->CInt
hailstone n
 | n `mod` 2 == 0    = n `div` 2
 | otherwise         = 3*n + 1

hailSeq :: CInt -> [CInt]
hailSeq 0 = [0]
hailSeq 1 = [1]
hailSeq n = n:(hailSeq(hailstone n))

foreign export ccall fib :: CInt -> CInt
fib :: CInt -> CInt
fib 0 = 0
fib 1 = 1
fib x = (fib (x-1)) + (fib (x-2))

divisors :: CInt -> [CInt]
divisors n = [i | i <- [2..(n `div` 2)], n `mod` i == 0]

primes :: CInt -> [CInt]
primes n = [i | i <- [2..n], divisors i == []]

foreign export ccall fact :: CInt -> CInt
fact :: CInt -> CInt
fact n = foldl (*) 1 [1..n]

main :: IO ()
main = print ""