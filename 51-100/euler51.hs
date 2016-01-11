import PEUtility

main :: IO ()
main = do
  putStrLn "Check if prime:"
  number <- getLine
  let isPrime = prime (read number :: Integer)
  print isPrime
