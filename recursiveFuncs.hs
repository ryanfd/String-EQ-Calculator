hailstone::Integer->Integer
hailstone n
 | n `mod` 2 == 0    = n `div` 2
 | otherwise         = 3*n + 1

hailSeq :: Integer -> [Integer]
hailSeq 0 = [0]
hailSeq 1 = [1]
hailSeq n = n:(hailSeq(hailstone n))

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = (fib (x-1)) + (fib (x-2))