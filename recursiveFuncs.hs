import System.Environment -- for main arguments

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

divisors :: Int -> [Int]
divisors n = [i | i <- [2..(n `div` 2)], n `mod` i == 0]

primes :: Int -> [Int]
primes n = [i | i <- [2..n], divisors i == []]

fact'::Integer->Integer
fact' n = foldl (*) 1 [1..n]

toInt :: String -> Integer
toInt s = read s :: Integer

main :: IO ()
main = do
  args <- getArgs
  case args of ["hail", n] -> toInt n
                   
  print args