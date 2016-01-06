import qualified Data.List as L

type FDN = (Int, Int)

intToFDN :: Int -> FDN
intToFDN x = (x `div` 100, x `mod` 100)

chained :: FDN -> FDN -> Bool
chained a b = snd a == fst b

polygonals :: Int -> Int -> Int -> [Int]
polygonals s min max = 
    let allPolys = scanl (+) 1 [s-1, 2*s-3 ..]
    in takeWhile (<max) $ dropWhile (<min) $ allPolys

allChains :: FDN -> [[FDN]] -> [[FDN]]
allChains _ [] = error "something bad"
allChains start (links:[]) = map (\link -> [start, link]) $ filter (chained start) links
allChains start rest = 
    let followingChains links = 
            L.concat $ map (\link -> allChains link otherRest) chainableLinks
            where chainableLinks = filter (chained start) links
                  otherRest = L.delete links rest
    in map (start:) $ L.concat $ map followingChains rest

cyclic :: [FDN] -> Bool
cyclic fdn = chained (last fdn) (head fdn)

cyclesFDN :: Int -> Int -> [[FDN]]
cyclesFDN sMin sMax = 
    let (tris:shapes) = map (\s -> map intToFDN $ polygonals s 1000 10000) [sMin..sMax]
    in filter cyclic $ L.concat $ map (\tri -> allChains tri shapes) tris

solution :: [Int]
solution = map sumFDN $ cyclesFDN 3 8
    where sumFDN = sum . map (\(a,b) -> a * 100 + b)