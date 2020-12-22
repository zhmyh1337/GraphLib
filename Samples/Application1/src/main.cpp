#include <Graph.h>

int main()
{
	auto x = graph::Graph<int, double>();
	auto y = graph::Graph<float>();
	
	{
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

	{
		auto structure = new graph::AdjacencyMatrix<5, int, double>(std::array<std::array<std::vector<double>, 5>, 5>{
			std::array<std::vector<double>, 5>{ std::vector<double>{2.5, 3.5}, std::vector<double>{1.5, 2.5} }
		});
		structure->AddEdge(2, { 1, 2 });
		structure->AddEdge(4, { 1, 2 });
		auto edges = structure->GetAllEdgesOfVertex(0);
		auto z = graph::Graph(structure);
		delete structure;
	}

	{
		auto structure = new graph::AdjacencyMatrix<5, float>(std::array<std::array<size_t, 5>, 5>{
			std::array<size_t, 5>{ 3, 2 }
		});
// 		structure->AddEdge(2, 2);
// 		structure->AddEdge(4, 3);
		auto edges = structure->GetAllEdgesOfVertex(0);
		auto z = graph::Graph(structure);
		delete structure;
	}

	{
		auto structure = new graph::EdgeList<int, double>(std::vector<std::pair<int, std::pair<int, double>>>{
			{1, {1, 2}},
			{1, {535, 25.53}},
			{2, {3, 5.55}}
		});
		structure->AddEdge(5, std::make_pair(1, 5));
		structure->AddEdge(1, std::make_pair(5, 222));
		auto edges = structure->GetAllEdgesOfVertex(1);
		auto z = graph::Graph(structure);
		delete structure;
	}
}
