
type Fraction a = (a, a)

add1 :: Integral a => Fraction a -> Fraction a
add1 (numer, denom) = (numer + denom, denom)

expand :: Integral a => Fraction a -> Fraction a
expand (numer, denom) = (denom, 2 * denom + numer)

digits :: Integral a => a -> [a]
digits n
    | n < 10 = [n]
    | otherwise = (n `mod` 10) : digits (n `div` 10)

condition :: Integral a => Fraction a -> Bool
condition (numer, denom) = numDigits numer > numDigits denom
    where numDigits = length . digits

solution :: Integral a => a
solution = let expansions = map add1 $ take 1000 $ iterate expand (1,2)
           in fromIntegral $ length $ filter condition expansions