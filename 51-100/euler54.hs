
palindrome :: (Eq a) => [a] -> Bool
palindrome [] = True
palindrome (_:[]) = True
palindrome (a:xs) = a == last xs && palindrome (init xs)

digits :: (Integral a) => a -> [Int]
digits n
    | n < 10 = [fromIntegral n]
    | otherwise = fromIntegral (n `mod` 10) : digits (n `div` 10)

numReverse :: (Integral a) => a -> a
numReverse n = foldl (\acc x -> 10 * acc + fromIntegral x) 0 (digits n)

numPalindrome :: (Integral a) => a -> Bool
numPalindrome = palindrome . digits

lychrel :: (Integral a) => a -> a -> Bool
lychrel n i
    | i == 0 = True
    | otherwise = if numPalindrome iter then False else lychrel iter (i-1)
        where iter = n + numReverse n