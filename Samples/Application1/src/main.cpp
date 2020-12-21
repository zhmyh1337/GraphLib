#include <Graph.h>

int main()
{
	auto x = graph::Graph<int, double>();
	auto y = graph::Graph<float>();
	
	auto structure = new graph::AdjacencyList<int, double>(std::unordered_map<int, std::vector<graph::AdjacencyList<int, double>::EdgeType>>({
		{ 1, {std::make_pair(2, 2.3), std::make_pair(1, 0.4)} },
		{ 5, {std::make_pair(6, 1533.35)} },
	}));
	structure->AddEdge(1, { 1, 2 });
	structure->AddEdge(6, { 1, 2 });
	auto edges = structure->GetAllEdgesOfVertex(1);
	auto z = graph::Graph(structure);
	delete structure;
}
