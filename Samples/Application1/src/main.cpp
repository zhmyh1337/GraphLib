#include <iostream>
#include <Graph.h>

int main()
{
	{
		auto graph = graph::Graph<int>();
		graph.AddBidirectionalEdge(0, 2);
		graph.AddBidirectionalEdge(0, 4);
		graph.AddBidirectionalEdge(0, 5);
		graph.AddBidirectionalEdge(1, 4);
		graph.AddBidirectionalEdge(1, 5);
		graph.AddBidirectionalEdge(2, 3);
		graph.AddBidirectionalEdge(2, 4);
		graph.AddBidirectionalEdge(4, 5);
		graph.DepthFirstSearch(0, [](int from, int to) { std::cout << from << " -> " << to << std::endl; });
	}

	std::cout << std::endl;

	{
		auto graph = graph::Graph<int>();
		graph.AddEdge(0, 2);
		graph.AddEdge(0, 4);
		graph.AddEdge(0, 5);
		graph.AddEdge(1, 4);
		graph.AddEdge(1, 5);
		graph.AddEdge(2, 3);
		graph.AddEdge(2, 4);
		graph.AddEdge(4, 5);
		graph.BreadthFirstSearch(0, [](int from, int to) { std::cout << from << " -> " << to << std::endl; });
	}
}
