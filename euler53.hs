
comb :: Int -> Int -> Int
n `comb` r
    | r >= n-r = product [r+1..n] `div` (product [1..n-r])
    | otherwise = n `comb` (n-r)

combsGT :: Int -> Int -> Int
combsGT n x =
    case combGT n 0 1 x of Just r -> n+1 - 2*r
                           Nothing -> 0

combGT :: (Integral a) => a -> a -> a -> a -> Maybe a
combGT n r c x
    | c > x = Just r
    | r > n `div` 2 = Nothing
    | otherwise = combGT n (r+1) (c * (n-r) `div` (r+1)) x