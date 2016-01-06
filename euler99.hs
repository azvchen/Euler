import Data.Function
import Data.List
import Data.Maybe

parseLine :: String -> (Int, Int)
parseLine s = let subs = groupBy ((==) `on` (==',')) s
              in (read (subs !! 0), read (subs !! 2))

logVal :: (Int, Int) -> Float
logVal (base, exp) = fromIntegral exp * log (fromIntegral base)

maxExp :: [(Int, Int)] -> Int
maxExp xs = fromJust $ elemIndex (maximumBy (compare `on` logVal) xs) xs

main = do
    contents <- readFile "p099_base_exp.txt"
    let maxLineNum = maxExp $ map parseLine (lines contents)
    putStrLn $ show $ maxLineNum + 1