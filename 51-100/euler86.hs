
type Cuboid a = (a, a, a)

squaresUpTo :: (Integral a, Integral b) => a -> [a]
squaresUpTo n = takeWhile (<fromIntegral n) [x*x | x <- [0..]]

cuboidsUpTo :: (Integral a) => a -> [Cuboid a]
cuboidsUpTo m = [(l,w,h) | l <- [1..m], w <- [1..l], h <- [1..w]]

checkCuboidPath :: (Integral a) => Cuboid a -> [a] -> Bool
checkCuboidPath (l,w,h) paths = fromIntegral (l^2 + (w+h)^2) `elem` paths

solsOfLength :: (Integral a) => a -> a
solsOfLength m = fromIntegral $ length $ filter (`checkCuboidPath` squares) $ cuboids
  where squares = squaresUpTo (2*m*m)
        cuboids = cuboidsUpTo m

solution :: (Integral a) => a -> a
solution total = head $ dropWhile (<=total) $ [solsOfLength m | m <- [1..]]

main :: IO ()
main = do
  putStrLn "Number of solutions:"
  totalString <- getLine
  let total = read totalString
  putStrLn $ "Least value of M: " ++ (show $ solution total)
