//
// each node give a number representing the structure of the subtree where this node is the root.//
// each leaf is 1, map each vector structure to a number, 
// if two rooted tree has the same number at the root, then they are isomorphic. 
// TIOJ 1214. 

// map<vector<int>, int> the index is the smallest unassigned number

// use hash, for example the hash value equal to the exp(9) of the children 
// another hash
// for every node in a tree, a vector represents the distance from that node to every other node
// every tree has n vectors 
// if two trees has the same n vectors then they are isomorphic 
