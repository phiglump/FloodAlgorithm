{- |
Module      :  flood-algorithm.hs
Description :  This is the flood algorithm written in Haskell 
Copyright   :  (c) Author: Philippe Lumpkin
License     :  Open Source License
Maintainer  :  phiglump@ut.utm.edu
Stability   :  unstable | <experimental> | provisional | stable | frozen
Discussed high level code with Nicholas Pica and Hunter Haislip
-}

import Data.List
-- ^ imported for nub and sort 

reachable :: [(Char, Char)] -> Char -> [Char]
reachable graph start = sort ( nub (reachable' graph start))
-- ^ This is the main function that will take the list and the starting point
-- It will also sort and remove duplicates from the list 

reachable' :: [(Char, Char)] -> Char -> [Char]
reachable' graph start = start: restCompare [start] graph
-- ^ this function essentially just adds the start node to a list so that restCompare will accept it
-- still functionally works the same 

restCompare :: [Char] -> [(Char, Char)] -> [Char]
restCompare [] graph = []
restCompare (n:ns) graph = compareStart ++ restCompare compareStart removeTuple ++ restCompare ns removeTuple
    where 
    compareStart = (compare' n graph)
    removeTuple = (remove n graph)
-- ^ The middle part of the concatenation from my understanding seems to be more for positioning and for the recursion
-- the first will get the first set of neighbors from the neighbors list and the last part is sending the rest of the list
-- thru the restcompare again. 

compare' :: Char -> [(Char, Char)] -> [Char]
compare' start [] = []
compare' start (x:xs)
    | start == fst x = snd x: compare' start xs
    | otherwise = compare' start xs
-- ^ comparing the starting node to the head of all the tuples in the given list

remove :: Char -> [(Char, Char)] -> [(Char, Char)]
remove start [] = []
remove start (x:xs)
    | start == fst x = remove start xs
    | otherwise = x: remove start xs 
-- ^ This is my remove function that updates the graph after the compare function has already gathered what it needed to know
-- It works very similar to how compare' worked but instead of printing the list of neighbors it instead removes the head on a match condition

-- [('a', 'f'), ('a', 'h'), ('a', 'c'), ('c', 'd'), ('f', 'd')]
-- [('k','f'),('x','l'),('n','s'),('b','a'),('f','q'),('a','c'),('f','s'),('r','h'),('d','t'),('b','y'),('h','g'),('r','y'),('c','c'),('a','g'),('v','j'),('v','l'),('s','u'),('i','j'),('y','e'),('y','v'),('a','f'),('f','g'),('z','h'),('y','y'),('g','q'),('y','s'),('b','t'),('l','j'),('m','q'),('p','k'),('p','b'),('t','w'),('k','j'),('q','c')]
-- ^ test cases that i used as reference, the second one uses loops like c to c and like c to b and b to c.
