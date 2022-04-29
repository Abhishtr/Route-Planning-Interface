/*
Group  Project Topic - Route Planning System/Interface

Group Members -
1>Abhisht Rustagi - 2020A7PS1891H
2>Akshit Rathi - 2020A7PS2045H
3>Varad Asawa - 2020A7PS0217H
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll INF = numeric_limits<ll>::max() - 1;
ll NINF = numeric_limits<ll>::min() + 1;
//the class and it member functions and member variables
class edge {

	private:
		ll source_node;
		ll destination_node;
		ld speed_limit;
		ld distance;
		ld minimum_time_taken;

	public:
		void calc_time()
		{
			minimum_time_taken = distance / speed_limit;
		}
		//Some Constructores
		edge()
		{
			source_node = -1;
			destination_node = -1;
			speed_limit = -1;
			distance = -1;
			minimum_time_taken = -1;
		}

		edge(ll source_node, ll destination_node, ld distance, ld speed_limit)
		{
			this->source_node = source_node;
			this->destination_node = destination_node;
			this->speed_limit = speed_limit;
			this->distance = distance;
			calc_time();
		}

		edge(const edge &temp_edge)
		{
			source_node = temp_edge.source_node;
			destination_node = temp_edge.destination_node;
			speed_limit = temp_edge.speed_limit;
			distance = temp_edge.distance;
			calc_time();
		}

		ll get_source()
		{
			return source_node;
		}

		ll get_destination()
		{
			return destination_node;
		}

		ld get_distance()
		{
			return distance;
		}

		ld get_speed()
		{
			return speed_limit;
		}

		ld get_mintime()
		{
			return minimum_time_taken;
		}

		void set_distance(ld distance)
		{
			this->distance = distance;
		}

		void set_speed(ld speed_limit)
		{
			this->speed_limit = speed_limit;
		}

		void set_mintime(ld minimum_time_taken)
		{
			this->minimum_time_taken = minimum_time_taken;
		}
};

//prototype of print node function
void printcityname(const vector<vector<edge>>&graph, const map<ll, string>&city_names);

//function to print the graph
void print_graph(const vector<vector<edge>>&graph, map<ll, string>cities)
{
	for (ll i = 0; i < graph.size(); i++)
	{
		if (graph[i].size() > 0)
		{
			cout << "#################################" << '\n';
			cout << "Cities connected to : " << cities[i] << "\n\n";

			for (auto e : graph[i])
			{
				cout << "Destination : " << cities[e.get_destination()] << '\n';
				cout << "Distance : " << e.get_distance() << " Km" << '\n';
				cout << "Speed Limit : " << e.get_speed() << " Kmph" << "\n";
				cout << "Time Taken : " << e.get_mintime() << " hours" << "\n\n";
			}
		}
	}
	cout << "#################################" << '\n';
	cout << "\n\n";
}

//function to print the subgraph
void printsubgraph(vector<vector<edge>>&graph, map<ll, string>&city_names, ll source_node)
{
	if (graph[source_node].size() > 0)
	{
		cout << "\nNeighbours of " << city_names[source_node] << "\n\n";

		for (auto e : graph[source_node])
		{
			cout << "##############################\n\n";
			cout << "Destination : " << city_names[e.get_destination()] << '\n';
			cout << "Distance : " << e.get_distance() << " Km" << '\n';
			cout << "Speed Limit : " << e.get_speed() << " Kmph" << "\n";
			cout << "Time Taken : " << e.get_mintime() << " hours" << "\n\n";
		}
		cout << "##############################\n";
	}
	else
	{
		cout << city_names[source_node] << " isn't connected to any other node.\n";
	}
}

//taking input for source node and calling the print subgraph function
void printsubgraph_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the source node: ";
	ll source_node;
	cin >> source_node;

	if (source_node >= graph.size())
	{
		cout << "Invalid node entered, enter a valid node";
		return;
	}
	else
	{
		printsubgraph(graph, city_names, source_node);
	}
}

//delay for menu
void delay(ll milliseconds)
{
	for (ll i = 0; i <= 900000 * milliseconds; i++);
}

//menu which will be shown to user
void menu()
{
	delay(1500);
	cout << "\n\nMenu:\n";
	cout << "\n01> Print the graph";
	cout << "\n02> Print the neighbours of a node";
	cout << "\n03> Make a new Node";
	cout << "\n04> Remove a Node";
	cout << "\n05> Add an edge between two existing nodes";
	cout << "\n06> Edit an edge between two existing nodes";
	cout << "\n07> Remove an edge between two existing nodes";
	cout << "\n08> Find the minimum distance between two nodes";
	cout << "\n09> Find the minimum time to travel between two nodes";
	cout << "\n10> Find Hamiltonian Cycle";
	cout << "\n11> DFS Traversal";
	cout << "\n12> BFS Traversal";
	cout << "\n13> See existing nodes";
	cout << "\n14> help";
	cout << "\n15> quit\n\n";
}

//Description of Our Program
void description()
{
	cout << "This is a Route planning interface. This will allow you to add/delete nodes(cities) and add/delete edges(roads) between them. The graph is presented using adjacency list. Each edge has three properties - Distance between the nodes, the maximum speed allowed on that road and minimum time to traverse on that edge, all of which can be modified. We have incorporated various features such as finding the minimum distance/time between the two nodes, finding the starting point to maximise the profit using various algorithm using bellman ford, djikstra. We have also implemented an algorithm to find the hamiltonian cycle.\n\n";
}

//Help, it would be displaying the description of all the options of the menu
void help()
{
	cout << "Here are all the descriptions of all the items of the menu:\n";
	cout << "\n01> Print the graph -- Choosing this option will print the current graph in a formatted manner\n";
	cout << "\n02> Print neighbours of a node-- print the details of neighbours of a node\n";
	cout << "\n03> Make a new Node -- Choosing this option will allow you to add new nodes in the graph. Two Different nodes can't have the same name of node.\n";
	cout << "\n04> Remove a Node -- Choosing this option will delete a node if it exists and all the edges connected to that node will also be deleted.\n";
	cout << "\n05> Add an edge between two existing nodes -- This option would allow you to add a edge between two declared nodes. If there already exists a edge between the said nodes or a node doesn't exist you will get their corresponding error messages.\n";
	cout << "\n06> Edit an edge between two existing nodes -- Choosing this option will allow you to change the properties such as distance, maximum speed, minimum time to cross that node\n";
	cout << "\n07> Remove an edge between two existing nodes -- Choosing this option will remove an existing edge between two nodes\n";
	cout << "\n08> Find the minimum distance between two nodes -- Choosing this option will allow you to find the minimum distance between the two nodes\n";
	cout << "\n09> Find the minimum time to travel between two nodes -- Choosing this option will allow you to find the minimum distance between the two nodes\n";
	cout << "\n10> Find Hamiltonian Cycle -- Choosing this option will allow you to check whether hamiltonian cycle exists or not\n";
	cout << "\n11> DFS Traversal -- Choosing this option will provide you Depth first traversal sequence of a node\n";
	cout << "\n12> BFS Traversal -- Choosing this option will provide you Breadth first traversal sequence of a node\n";
	cout << "\n13> See existing nodes -- Choosing this option will show you the cities and the code associated with them\n";
	cout << "\n14> help -- Choosing this option will show you this help guide\n";
	cout << "\n15> quit -- Choosing this option will terminate the program\n\n";
}
//function to add an edge between two nodes
void add_edge(vector<vector<edge>>&graph, ll source_node, ll destination_node, ld distance, ld speed_limit, map<ll, string>&city_names)
{
	bool flag = true;
	//checking whether both the nodes exists in graph or not
	if ((max(source_node, destination_node) >= graph.size()))
	{
		//if either or both the nodes doesn't exist in graph
		cout << "Node doesn't exist,\nadd the new node first";
	}
	else
	{
		//if both the nodes exists in the graph
		//checking whether there already exists an edge between source node and destinatoin node
		for (auto e : graph[source_node])
		{
			if (e.get_destination() == destination_node) {
				flag = false;
				break;
			}
		}
		//if no edge already exists between the two nodes, then create an edge between them
		if (flag)
		{
			edge e1(source_node, destination_node, distance, speed_limit);
			edge e2(destination_node, source_node, distance, speed_limit);

			graph[source_node].emplace_back(e1);
			graph[destination_node].push_back(e2);

			cout << "\nEdge added between " << city_names[source_node] << " and " << city_names[destination_node] << '\n';
		}
		else
		{
			cout << "\nMultiple edges between Source node and Destination node is not allowed.\nAlthough you can edit the the properties between them";
			return;
		}
	}
}

//function to take inputs of source and destination node &
// all the properties of edge and then call add_edge function
void add_edge_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	//checking whether there exists at least two nodes in the grpah
	if (graph.size() < 2)
	{
		cout << "less than two nodes in the graph, add more nodes first.";
		return;
	}
	else
	{
		printcityname(graph, city_names);
		//taking inputs
		cout << "Enter the first node: ";
		ll source_node;
		cin >> source_node;

		cout << "Enter the second node: ";
		ll destination_node;
		cin >> destination_node;

		cout << "Enter the distance: ";
		ld distance;
		cin >> distance;

		cout << "Enter the Speed Limit: ";
		ld speed_limit;
		cin >> speed_limit;

		//checking whether souorce node is same as destination node
		if (destination_node != source_node)
		{
			add_edge(graph, source_node, destination_node, distance, speed_limit, city_names);
		}
		else
		{
			cout << "Self Loops are not allowed.\n";
		}
	}
}

//Function to add node into the graph
void add_node(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	cout << "Enter the new node name: ";
	string node;
	cin >> node;

	//checking whether node already exists in graph
	for (auto c : city_names)
	{
		if (node == c.second)
		{
			cout << "Node for this node already exists.\n";
			return;
		}
	}
	//adding empty vector to the graph
	city_names[graph.size()] = node;
	vector<edge>v = {};
	graph.emplace_back(v);

	cout << "New node \"" << node << "\" has been created.";
}

//Function to remove node from the graph. It doesn't changes the index of other nodes
void remove_node(vector<vector<edge>>&graph, ll node, map<ll, string>&city_names)
{
	//checking whether node exists in a graph or not
	if (city_names.find(node) == city_names.end())
	{
		cout << "Node doesn't exists";
	}
	else {
		for (auto e1 : graph[node])
		{
			ll count = 0;
			for (auto e2 : graph[e1.get_destination()])
			{
				if (e2.get_destination() == node)
				{
					break;
				}
				else
				{
					count++;
				}
			}
			graph[e1.get_destination()].erase(graph[e1.get_destination()].begin() + count);
		}
		graph[node].resize(0);
	}
}

// function to take the input of node to be deleted
void remove_node_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the node you want to delete: ";
	ll node;
	cin >> node;

	remove_node(graph, node, city_names);
}

//function to find the position of source node and destination node in the vector
tuple<bool, ll, ll> positions(const vector<vector<edge>>&graph, ll source_node, ll destination_node)
{
	bool flag = false;
	ll count1 = 0, count2 = 0;
	//checking whether source node and destination node have an edge and simultaneosly getting the position in the vector
	for (auto e1 : graph[source_node])
	{
		if (e1.get_destination() == destination_node)
		{
			flag = true;
			break;
		}
		else
		{
			count1++;
		}
	}
	if (flag)
	{
		for (auto e2 : graph[destination_node])
		{
			if (e2.get_destination() == source_node)
			{
				break;
			}
			else
			{
				count2++;
			}
		}

		return make_tuple(true, count1, count2);
	}
	else
	{
		return make_tuple(false, -1, -1);
	}
}

//Function to remove the edge from the graph
void remove_edge(vector<vector<edge>>&graph, ll source_node, ll destination_node, map<ll, string>&city_names)
{
	//checking whether nodes exists in the graph or not.
	if ((max(source_node, destination_node) >= graph.size()))
	{
		cout << "Node doesn't exist,\nadd the new node first";
	}
	else
	{
		auto position = positions(graph, source_node, destination_node);

		if (get<0>(position))
		{
			graph[source_node].erase(graph[source_node].begin() + get<1>(position));
			graph[destination_node].erase(graph[destination_node].begin() + get<2>(position));
			cout << "Edge Removed Successfully\n";
		}
		else
		{
			cout << "No edge exist between source node and destination node.\n";
			return;
		}
	}
}

//Function to take inputs of source node and destination node and calling the remove_edge function
void remove_edge_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the first node: ";
	ll source_node;
	cin >> source_node;

	cout << "Enter the second node: ";
	ll destination_node;
	cin >> destination_node;

	remove_edge(graph, source_node, destination_node, city_names);

}

//Function to modify the properties of edge
void modify_edge(vector<vector<edge>>&graph, ll source_node, ll destination_node, map<ll, string>&city_names)
{
	auto position = positions(graph, source_node, destination_node);
	//checking whether source node and destination node is connected by an edge
	if (get<0>(position))
	{
		//changing the speed limit of an edge
		cout << "Would you like to modify speed_limit of this edge? Enter 1 for YES and 0 for NO : ";
		ll option;
		cin >> option;

		if (option == 1)
		{
			ld temp_speed_limit;
			cout << "Enter the new speed limit between of the edge between these two nodes : ";
			cin >> temp_speed_limit;

			while (temp_speed_limit <= 0)
			{
				cout << "You have entered invalid value of speed_limit, Please enter a valid value : ";
				cin >> temp_speed_limit;
			}

			graph[source_node][get<1>(position)].set_speed(temp_speed_limit);
			graph[destination_node][get<2>(position)].set_speed(temp_speed_limit);
		}

		//changing the distance of an edge
		cout << "Would you like to modify distance of this edge? Enter 1 for YES and 0 for NO : ";
		cin >> option;

		if (option == 1)
		{
			ld temp_distance;
			cout << "Enter the new distance between the nodes : ";
			cin >> temp_distance;

			while (temp_distance <= 0)
			{
				cout << "You have entered invalid value of distance, Please enter a valid value : ";
				cin >> temp_distance;
			}

			graph[source_node][get<1>(position)].set_distance(temp_distance);
			graph[destination_node][get<2>(position)].set_distance(temp_distance);
		}
		graph[source_node][get<1>(position)].calc_time();
		graph[destination_node][get<2>(position)].calc_time();
	}
	else
	{
		cout << "No edge exist between source node and destination node.\n";
		return;
	}
}

//function to take input of source node and destination code and calling the modify_edge function
void modify_edge_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the source node: ";
	ll source_node;
	cin >> source_node;

	cout << "Enter the destination node: ";
	ll destination_node;
	cin >> destination_node;

	modify_edge(graph, source_node, destination_node, city_names);
}

//function to find the minimum distance between two nodes
//Using Djiksta Algorithm
ld minimum_distance(const vector<vector<edge>>&graph, ll source_node, ll destination_node, map<ll, string>&city_names)
{
	vector<ld>distance(graph.size(), INF);
	vector<bool>processed(graph.size(), false);

	for (ll i = 0; i < graph.size(); i++)
	{
		if (graph[i].size() == 0)
		{
			processed[i] = true;
		}
	}

	if (graph[source_node].size() == 0 || graph[destination_node].size() == 0)
	{
		return INF;
	}

	distance[source_node] = 0;
	priority_queue<pair<ll, ll>>q;

	q.push(make_pair(0, source_node));
	while (!q.empty())
	{
		ll current_node = q.top().second;
		q.pop();

		if (!processed[current_node])
		{
			processed[current_node] = true;
			for (auto next : graph[current_node])
			{
				ll next_node = next.get_destination();
				ld weight = next.get_distance();

				if (distance[current_node] + weight < distance[next_node])
				{
					distance[next_node] = distance[current_node] + weight;
					q.push(make_pair( -distance[next_node], next_node));
				}
			}
		}
	}
	return distance[destination_node];
}

//function to take input of source node and destination node and then calling the minimum_distance function
void minimum_distance_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the source node: ";
	ll source_node;
	cin >> source_node;

	cout << "Enter the destination node: ";
	ll destination_node;
	cin >> destination_node;

	cout << "Minimum Distance between \"" << city_names[source_node] << "\" & \"" << city_names[destination_node] << "\" is :" << minimum_distance(graph, source_node, destination_node, city_names) << " Km";
}

//function to find the minimum time between any two two nodes
ld minimum_time(const vector<vector<edge>>&graph, ll source_node, ll destination_node, map<ll, string>&city_names)
{
	vector<ld>mintime(graph.size(), INF);
	vector<bool>processed(graph.size(), false);

	for (ll i = 0; i < graph.size(); i++)
	{
		if (graph[i].size() == 0)
		{
			processed[i] = true;
		}
	}

	if (graph[source_node].size() == 0 || graph[destination_node].size() == 0)
	{
		return INF;
	}

	mintime[source_node] = 0;
	priority_queue<pair<ll, ll>>q;

	q.push(make_pair(0, source_node));
	while (!q.empty())
	{
		ll current_node = q.top().second;
		q.pop();

		if (!processed[current_node])
		{
			processed[current_node] = true;
			for (auto next : graph[current_node])
			{
				ll next_node = next.get_destination();
				ld time_taken = next.get_mintime();

				if (mintime[current_node] + time_taken < mintime[next_node])
				{
					mintime[next_node] = mintime[current_node] + time_taken;
					q.push(make_pair( -mintime[next_node], next_node));
				}
			}
		}
	}
	return mintime[destination_node];
}

//function to take input of source node and destination node and then calling the minimum_time function
void minimum_time_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	cout << "Enter the source node: ";
	ll source_node;
	cin >> source_node;

	cout << "Enter the destination node: ";
	ll destination_node;
	cin >> destination_node;

	cout << "Minimum Time Taken to travel between \"" << city_names[source_node] << "\" & \"" << city_names[destination_node] << "\" is :" << minimum_time(graph, source_node, destination_node, city_names) << " hours";
}

//function to print the node names as well as their indexes in a formatted manner
void printcityname(const vector<vector<edge>>&graph, const map<ll, string>&city_names)
{
	cout << "\n\nNumber associated with each node\n";
	for (auto e : city_names)
	{
		cout << e.second << " - " << e.first << '\n';
	}
	cout << '\n';
}

//function for depth first search
void depth_first_search (ll source_node, const vector<vector<edge>>&adjacency_list, vector<bool>&visited, vector<ll>&order)
{
	visited[source_node] = true;
	order.emplace_back(source_node);

	for (auto destination_node : adjacency_list[source_node])
	{
		if (!(visited[destination_node.get_destination()]))
		{
			depth_first_search (destination_node.get_destination(), adjacency_list, visited, order);
		}
	}
}

//function to take input of starting node and calling depth_first_search function
void dfs_start(const vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	ll start;// this is the starting node we are travelling from
	cout << "\nEnter the starting node : ";
	cin >> start;

	if (start < city_names.size())
	{
		vector<bool>visited (graph.size(), false);

		for (ll i = 0; i < graph.size(); i++)
		{
			if (graph[i].size() == 0)
			{
				visited[i] = true;
			}
		}

		vector<ll>order;
		depth_first_search (start, graph, visited, order);

		for (auto c : order)
		{
			cout << city_names[c] << ", ";
		}

		cout << "\b\b  \b\b";
	}
	else
	{
		cout << "Invalid node entered";
	}

}

//function for breadth first search
void breadth_first_search (ll source_node, const vector<vector<edge>>&graph, vector<bool>&visited, vector<ll>&order)
{
	visited[source_node] = true;
	queue<ll>q;
	q.push (source_node);

	while (!q.empty())
	{
		ll current_node = q.front();
		order.emplace_back(current_node);
		q.pop();

		for (auto destination_node : graph[current_node])
		{
			if (!visited[destination_node.get_destination()])
			{
				visited[destination_node.get_destination()] = true;
				q.push (destination_node.get_destination());
			}
		}
	}
}

//function to take input of starting node and calling breadth_first_search function
void bfs_start(const vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	printcityname(graph, city_names);

	ll start;
	cout << "\nEnter the starting node : ";
	cin >> start;

	if (start < city_names.size())
	{
		vector<bool>visited (graph.size(), false);
		for (ll i = 0; i < graph.size(); i++)
		{
			if (graph[i].size() == 0)
			{
				visited[i] = true;
			}
		}

		vector<ll>order;
		breadth_first_search (start, graph, visited, order);

		for (auto c : order)
		{
			cout << city_names[c] << ", ";
		}

		cout << "\b\b  \b\b";
	}
	else
	{
		cout << "Invalid node entered";
	}
}

void printSolution(int path[], int size, map<ll, string>&city_names);

bool isSafe(int v, vector<vector<bool>>am,
            int path[], int pos)
{

	if (am [path[pos - 1]][ v ] == 0)
	{ return false; }


	for (int i = 0; i < pos; i++)
		if (path[i] == v)
		{ return false; }

	return true;
}

/* A recursive function to solve hamiltonian cycle*/
bool Hamiltonian_Check(vector<vector<bool>>am, int path[], int position)
{

	if (position == am.size())
	{
		if (am[path[position - 1]][path[0]] == 1)
		{ return true; }
		else
		{ return false; }
	}

	for (int v = 1; v < am.size(); v++)
	{
		// Check if this vertex can be added to Hamiltonian Cycle
		if (isSafe(v, am, path, position))
		{
			path[position] = v;

			// recur to construct rest of the path
			if (Hamiltonian_Check (am, path, position + 1) == true)
			{ return true; }

			// If adding vertex v doesn't lead to a solution, then remove it
			path[position] = -1;
		}
	}

	return false;
}

// This function solves the Hamiltonian Cycle problem using Backtracking.  It returns false if there is no Hamiltonian Cycle possible, otherwise return true and prints the path.
bool Hamiltonian_Cycle(vector<vector<bool>>&am, map<ll, string>&city_names)
{
	int *path = new int[am.size()];
	for (int i = 0; i < am.size(); i++)
	{ path[i] = -1; }

	/* Let us put vertex 0 as the first vertex in the path.
	If there is a Hamiltonian Cycle, then the path can be
	started from any point of the cycle as the graph is undirected */
	path[0] = 0;
	if (Hamiltonian_Check(am, path, 1) == false )
	{
		cout << "There is no Hamiltonian Cycle in the graph";
		return false;
	}

	printSolution(path, am.size(), city_names);
	return true;
}

//Function to print the hamiltonian path
void printSolution(int path[], int size, map<ll, string>&city_names)
{
	cout << "One Possible hamiltonian cycle is :\n";
	for (int i = 0; i < size; i++)
	{ cout << city_names[path[i]] << ", "; }

	// printing the first vertex
	// to show the complete cycle
	cout << city_names[path[0]] << " ";
	cout << endl;
}

//Hamiltonian Function for menu
void hamiltonian_cycle_menu(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	vector<vector<bool>>am(graph.size(), vector<bool>(graph.size(), false));

	for (ll i = 0; i < graph.size(); i++)
	{
		for (ll j = 0; j < graph[i].size(); j++)
		{
			am[i][graph[i][j].get_destination()] = true;
		}
	}

	Hamiltonian_Cycle(am, city_names);
}

// Function to print the node names and their indexes.
// This function is different from printcitynames
void Existing_cities(vector<vector<edge>>&graph, map<ll, string>&city_names)
{
	ll count = 0;
	for (ll i = 0; i < graph.size(); i++)
	{
		cout << city_names[i] << " - " << i << '\n';
		count++;
	}

	if (count == 0)
	{
		cout << "No Node has been created in the graph.";
	}
}

//driver code
void solve()
{
	description();
	//Declaring required data structures and
	ll option;
	map<ll, string>city_names;
	vector<vector<edge>>graph;

	cout << "Type 0 to enter demontration mode or type 1 to enter manual mode or type 2 to quit the program.\nYour Option : ";
	cin >> option;

	while (option != 0 && option != 1 && option != 2)
	{
		cout << "You entered invalid option, Please enter a valid option: ";
		cin >> option;
	}

	if (option == 1)
	{
		cout << "Entering manual mode. An empty graph will be initialized\n";
	}
	else if (option == 0)
	{
		city_names[0] = "Delhi";
		city_names[1] = "Hyderabad";
		city_names[2] = "Mumbai";
		city_names[3] = "Kolkata";
		city_names[4] = "Chennai";
		city_names[5] = "Bangalore";
		city_names[6] = "Bhopal";
		city_names[7] = "Lucknow";

		graph.resize(city_names.size());
		printcityname(graph, city_names);

		add_edge(graph, 0, 1, 100, 70, city_names);
		add_edge(graph, 0, 2, 150, 40, city_names);
		add_edge(graph, 0, 6, 200, 80, city_names);
		add_edge(graph, 1, 2, 75, 15, city_names);
		add_edge(graph, 2, 4, 60, 45, city_names);
		add_edge(graph, 4, 6, 90, 20, city_names);
		add_edge(graph, 1, 3, 40, 40, city_names);
		add_edge(graph, 2, 3, 50, 100, city_names);
		add_edge(graph, 3, 5, 300, 100, city_names);
		add_edge(graph, 4, 5, 250, 175, city_names);
		add_edge(graph, 5, 6, 120, 60, city_names);
		add_edge(graph, 6, 7, 500, 45, city_names);
		add_edge(graph, 7, 2, 45, 90, city_names);

		cout << "Your graph has been initialized. Printing the graph\n\n";
		print_graph(graph, city_names);
	}
	else
	{
		cout << "Exiting the program\n";
		exit(0);
	}

	while (true)
	{
		menu();
		cout << "Your option : ";
		cin >> option;
		switch (option)
		{
			case 1: print_graph(graph, city_names);//tested
				break;

			case 2: printsubgraph_menu(graph, city_names);//tested
				break;

			case 3: add_node(graph, city_names);//tested
				break;

			case 4: remove_node_menu(graph, city_names);//tested
				break;

			case 5: add_edge_menu(graph, city_names);//tested
				break;

			case 6: modify_edge_menu(graph, city_names); //tested
				break;

			case 7: remove_edge_menu(graph, city_names);//tested
				break;

			case 8: minimum_distance_menu(graph, city_names);//tested
				break;

			case 9: minimum_time_menu(graph, city_names);//tested
				break;

			case 10: hamiltonian_cycle_menu(graph, city_names); //tested
				break;

			case 11: dfs_start(graph, city_names); //tested
				break;

			case 12: bfs_start(graph, city_names); //tested
				break;

			case 13: Existing_cities(graph, city_names);//tested
				break;

			case 14: help();//tested
				break;

			case 15: cout << "Exiting the program\n";//tested
				exit(0);
				break;

			default: cout << "You have entered an invalid option, please enter a valid option.\n";
		}
	}
}

int main()
{
	solve();
	return 0;
}