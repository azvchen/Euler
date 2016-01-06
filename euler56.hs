
digitSum :: (Integral a) => a -> a
digitSum = sum . digits

digits :: (Integral a) => a -> [a]
digits n
    | n < 10 = [n]
    | otherwise = (n `mod` 10) : digits (n `div` 10)

maxDigitSum :: (Integral a) => a -> a -> a
maxDigitSum maxA maxB = maximum $ map digitSum [a^b | a <- [1..maxA], b <- [1..maxB]]