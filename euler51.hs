import System.Environment

prime :: (Integral a) => a -> Bool
prime n = foldl (\acc x -> if n `mod` x == 0 then False else acc) True [2 .. s n]
    where s = floor . sqrt . fromIntegral

