module PEUtility
( prime
) where

prime :: (Integral a) => a -> Bool
prime n = foldl (\acc x -> n `mod` x /= 0 && acc) True [2 .. s n]
    where s = floor . sqrt . fromIntegral
