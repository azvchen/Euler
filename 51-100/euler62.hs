import Data.List

cubes :: (Integral a) => [a]
cubes = [x^3 | x <- [1..]]

cubesOfDigits :: (Integral a) => Int -> [a]
cubesOfDigits d = takeWhile (<10^d) $ dropWhile (<10^(d-1)) cubes

digits :: Int -> [Int]
digits = reverse . digitsRev

digitsRev :: Int -> [Int]
digitsRev n
    | n < 10 = [n]
    | otherwise = (n `mod` 10) : digitsRev (n `div` 10)

permuted :: (Eq a) => [a] -> [a] -> Bool
permuted [] [] = True
permuted _ [] = False
permuted [] _ = False
permuted (x:xs) ys = if x `elem` ys
                     then permuted xs (delete x ys)
                     else False

permutationsIn :: (Eq a) => [[a]] -> Int -> [a]
permutationsIn [] _ = []
permutationsIn (x:xs) n = 
    let perms = foldl (\acc y -> if permuted x y then acc + 1 else acc) 0 xs
    in if perms == n-1 then x else permutationsIn xs n

solution :: Int -> [Int]
solution d = head $ dropWhile (==[]) $ map (\x -> permutationsIn (map digits $ cubesOfDigits x) d) [1..]