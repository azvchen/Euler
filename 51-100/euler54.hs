import Data.List
import Data.Function (on)

data HandRank a = HighCard [a] | OnePair a [a] | TwoPair a a [a]  | ThreeKind a [a] |
                  Straight a | Flush [a] | FullHouse a a | FourKind a a |
                  StraightFlush a deriving (Show, Ord, Eq)

data Suit = H | D | C | S deriving (Show, Read, Eq)

data Card = Card { getValue :: Int, getSuit :: Suit } deriving (Show, Eq)
instance Ord Card where
    compare (Card a _) (Card b _) = compare a b
parseCard :: String -> Card
parseCard (v:s:[]) = 
    let value = if v `elem` ['2'..'9']
                then read $ v:[]
                else case v of 'T' -> 10
                               'J' -> 11
                               'Q' -> 12
                               'K' -> 13
                               'A' -> 14
        suit = read $ s:[]
    in Card value suit

type Hand = [Card]

rank :: Hand -> HandRank Card
rank hand = 
    let sortedHand = reverse $ sort hand
        straight = isStraight sortedHand
        groups = reverse $ sortBy (compare `on` length) $ groupBy ((==) `on` getValue) sortedHand
        bigGroup = head groups
        suits = map getSuit hand
        flush = all (==(head suits)) suits
    in if flush
       then if straight
            then StraightFlush $ head sortedHand
            else Flush sortedHand
       else if straight
            then Straight $ head sortedHand
            else case length bigGroup of 
                     4 -> FourKind (head bigGroup) (head (last groups))
                     3 -> if length groups == 2
                          then FullHouse (head bigGroup) (head (last groups))
                          else ThreeKind (head bigGroup) (reverse $ sort $ map head (tail groups))
                     2 -> if length groups == 3
                          then TwoPair (head bigGroup) (head (groups !! 1)) (groups !! 2)
                          else OnePair (head bigGroup) (reverse $ sort $ map head (tail groups))
                     1 -> HighCard sortedHand

isStraight :: [Card] -> Bool
isStraight [] = True
isStraight (_:[]) = True
isStraight (a:b:xs) = if getValue a == getValue b + 1then isStraight (b:xs) else False

compareHands :: Hand -> Hand -> Ordering
compareHands = compare `on` rank

parseLine :: String -> (Hand, Hand)
parseLine = splitAt 5 . map parseCard . words

compareLine :: String -> Ordering
compareLine line = 
    let hands = parseLine line
    in (compare `on` rank) (fst hands) (snd hands)

solution :: String -> Int
solution str = 
    let hands = map parseLine $ lines str
    in foldl (\wins hand -> if compareHands (fst hand) (snd hand) == GT
                            then wins + 1
                            else wins) 0 hands

main = do
    contents <- getContents
    putStrLn $ show $ solution contents