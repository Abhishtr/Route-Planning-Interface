# Route Planning Interface/System
I have created a command line-based route planning interface in C++ (using STL), which can add and delete nodes (cities) and weighted bidirectional edges (roads). Graph is represented using adjacency list. Each edge will have two properties - distance and maximum speed allowed. I have incorporated useful features such as finding minimum distance, minimum and path to travel between cities and find the hamiltonian cycle (NP - Complete Problem) in the graph. Data Structures such as maps, vectors, queues, and priority queues have been used.

## Descriptions of options of the menu:
1. Print the graph -- Choosing this option will print the current graph in a formatted manner.
2. Print neighbours of a node-- print the details of neighbours of a node.
3. Make a new Node -- Choosing this option will allow you to add new nodes in the graph. Two Different nodes can't have the same name of node.
4. Remove a Node -- Choosing this option will delete a node if it exists and all the edges connected to that node will also be deleted.
5. Add an edge between two existing nodes -- This option would allow you to add a edge between two declared nodes. If there already exists a edge between the said nodes or a node doesn't exist you will get their corresponding error messages.
6. Edit an edge between two existing nodes -- Choosing this option will allow you to change the properties such as distance, maximum speed, minimum time to cross that node.
7. Remove an edge between two existing nodes -- Choosing this option will remove an existing edge between two nodes.
8. Find the minimum distance between two nodes -- Choosing this option will allow you to find the minimum distance between the two nodes.
9. Find the minimum time to travel between two nodes -- Choosing this option will allow you to find the minimum distance between the two nodes.
10. Find Hamiltonian Cycle -- Choosing this option will allow you to check whether hamiltonian cycle exists or not.
11. DFS Traversal -- Choosing this option will provide you Depth first traversal sequence of a node.
12. BFS Traversal -- Choosing this option will provide you Breadth first traversal sequence of a node.
13. See existing nodes -- Choosing this option will show you the cities and the index code associated with them.
14. help -- Choosing this option will show you this help guide.
15. quit -- Choosing this option will terminate the program.
