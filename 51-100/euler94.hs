
type Triangle = (Int, Int, Int)

almostETs :: Int -> [Triangle]
almostETs perim = [(a,b,c) | a <- [2..maxSide], b <- [a], c <- [a-1, a+1]]
    where maxSide = (perim + 1) `div` 3

perimeter :: Triangle -> Int
perimeter (a,b,c) = a + b + c

intArea :: Triangle -> Bool
intArea (a,b,c) = case maybeH of Nothing -> False
                                 Just h -> if (c * h) `mod` 2 == 0
                                           then True
                                           else False
    where maybeH = if c `mod` 2 == 0
                   then perfectSqrt $ 4 * (a^2 - (c `div` 2)^2)
                   else Nothing

perfectSqrt :: Int -> Maybe Int
perfectSqrt x = if f x == x then Just (intSqrt x) else Nothing
    where f = (^2) . fromIntegral . intSqrt
          intSqrt = floor . sqrt . fromIntegral

goodAETs :: Int -> [Triangle]
goodAETs perim = filter intArea $ almostETs perim

main = do
    putStrLn "Max perimeter?"
    perimString <- getLine
    let perim = read perimString
        goods = goodAETs perim
        solution = sum $ map perimeter goods
    putStrLn $ "Good AETs are " ++ show goods
    putStrLn $ "Solution is " ++ show solution