{-# LANGUAGE CPP                         #-}
{-# LANGUAGE ForeignFunctionInterface    #-}

module Recursive where

import Foreign.C.Types -- for foreign calls

-- foreign ctype calls
foreign export ccall hailstone_hs :: CInt -> CInt
foreign export ccall fib_hs :: CInt -> CInt
foreign export ccall fact_hs :: CInt -> CInt

hailstone :: Int -> Int
hailstone n
 | n `mod` 2 == 0    = n `div` 2
 | otherwise         = 3*n + 1

hailstone_hs :: CInt -> CInt
hailstone_hs = fromIntegral . hailstone . fromIntegral


hailSeq :: Int -> [Int]
hailSeq 0 = [0]
hailSeq 1 = [1]
hailSeq n = n:(hailSeq(hailstone n))


fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = (fib (x-1)) + (fib (x-2))

fib_hs :: CInt -> CInt
fib_hs = fromIntegral . fib .fromIntegral

divisors :: Int -> [Int]
divisors n = [i | i <- [2..(n `div` 2)], n `mod` i == 0]

primes :: Int -> [Int]
primes n = [i | i <- [2..n], divisors i == []]


fact :: Int -> Int
fact n = foldl (*) 1 [1..n]

fact_hs :: CInt -> CInt
fact_hs = fromIntegral . fact . fromIntegral