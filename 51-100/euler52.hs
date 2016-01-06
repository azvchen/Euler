import Data.List

digits :: Int -> [Int]
digits n
    | n < 10 = [n]
    | otherwise = (n `mod` 10) : digits (n `div` 10)

permuted :: Int -> Int -> Bool
permuted a b = length ads == length bds && ads \\ bds == []
    where ads = digits a
          bds = digits b

permutedWith :: Int -> Int -> Bool
permutedWith n i
    | i == 1 = True
    | otherwise = permuted n (i*n) && permutedWith n (i-1)

smallPermW6 :: Int -> Int
smallPermW6 n = if permutedWith n 6 then n else smallPermW6 (n+1)

main = putStrLn $ show $ smallPermW6 1