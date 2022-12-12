# Word-Labbers
An example of using DFS based on recursion.  

A word ladder is a connection from one word to another formed by changing one letter at a time with the constraint that at each step the sequence of letters still forms a valid word. For example, here is a word ladder connecting "code" to "data".  

code → core → care → dare → date →data  

That word ladder, however, is not the shortest possible one. Although the words may be a little less familiar, the following ladder is one step shorter.  

code → cade → cate  

The goal of this problem is to write a program that finds a minimal word ladder between two words.  

(depth-first search) We first set up a map that stores the word found and the shortest number of transformations to reach it. In the recursive function, we iterate through each position of the word and replace it with another letter. If a word is formed, we check to see if the word is already in the map. If the word is recorded, and the shortest number of transformations to reach the word is shorter than the current transformation, this clearly cannot be the shortest transformation path. Otherwise, record the word and the number of transformations in the map, and call recursion. If the final word is found, record the number of transformations as bestValue. In other cases, once the number of transformations is greater than or equal to the BestValue, there is no need to recursively continue, because it is impossible to find a shorter number of transformations than the previous recursion. With the smart setting of map and BestValue, we can use depth-first search to find the shortest path in a short time.
