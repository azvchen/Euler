
prime :: (Integral a) => a -> Bool
prime n = foldl (\acc x -> if n `mod` x == 0 then False else acc) True [2 .. s n]
    where s = floor . sqrt . fromIntegral

layer :: (Integral a) => a -> [a]
layer 1 = [1]
layer sideLength = tail . take 5 $ iterate (+ (sideLength - 1)) corner
    where corner = (sideLength - 2) ^ 2

layerPrimes :: (Integral a) => a -> a
layerPrimes sideLength = fromIntegral . length . filter prime $ layer sideLength

solve :: (Integral a) => Float -> a
solve ratio = recur ratio 3 3

recur :: (Integral a) => Float -> a -> a -> a
recur ratio numPrimes sideLength = 
    let total = 2 * sideLength - 1
    in if (fromIntegral numPrimes / fromIntegral total) < ratio
       then sideLength
       else let newSideLength = sideLength + 2
                newNumPrimes = numPrimes + layerPrimes newSideLength
            in recur ratio newNumPrimes newSideLength