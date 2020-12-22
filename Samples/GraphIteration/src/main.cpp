#include <iostream>
#include <Graph.h>

int main()
{
	{
		std::cout << "DFS with bidirectional edges:" << std::endl;
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
		std::cout << "BFS with unidirectional edges:" << std::endl;
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

	std::cout << std::endl;

	{
		std::cout << "BFS path's weights sum:" << std::endl;
		auto graph = graph::Graph<int, float>();
		graph.AddEdge(0, std::make_pair(2, 22.0f));
		graph.AddEdge(0, std::make_pair(4, 1.5f));
		graph.AddEdge(0, std::make_pair(5, 0.0f));
		graph.AddEdge(1, std::make_pair(4, -3333.0f));
		graph.AddEdge(1, std::make_pair(5, -2222.0f));
		graph.AddEdge(2, std::make_pair(3, 0.44f));
		graph.AddEdge(2, std::make_pair(4, 5.0f));
		graph.AddEdge(4, std::make_pair(5, -1.0f));
		float sum = 0.0f;
		graph.BreadthFirstSearch(0, [&sum](int from, std::pair<int, float> edge) { sum += edge.second; });
		std::cout << sum << std::endl;
	}
}
