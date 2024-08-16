
// Eulerian Tour/ Eulerian Path
// A trail that contains every egde exactly once

// Necessary Contitons
// 1. Every Node has even degree and two can have odd degree [start and end nodes]
// 2. Whole Graph must be a single connected component
// 3. Eulerain Circuit-> a path which traverse every edge exactly once and comes to the starting edge
// 4. For Eulerian Circuit-> all nodes must have even degree

// Algorithm for Eulerian Circuit-> Heirholzer's Algorithm

// For Undirected Graph
// 1. For Eulerian Circuit-> must have even degree for all nodes
// 2. For Eulerian Path-> must have even degree for n-2 nodes, and 2 nodes have odd degree start and end

// For Directed Graph
// 1. For Eulerian Circuit-> must have equal indegree and outdegree for all nodes
// 2. For Eulerian Path-> must have equal indegree and outdegree for n-2 nodes and two nodes have one indegree extra and one outdegree extra.
