
digits :: (Integral a) => a -> [Int]
digits = reverse . digitsRev

digitsRev :: (Integral a) => a -> [Int]
digitsRev n
    | n < 10 = [fromIntegral n]
    | otherwise = (fromIntegral $ n `mod` 10) : digitsRev (n `div` 10)