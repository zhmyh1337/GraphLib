#include <utility>

#include <Graph.h>

int main()
{
	// Unweighted AdjacencyList.
	{
		auto structure = new graph::AdjacencyList<int>({
			{ 1, { 2, 3, 5 }},
			{ 2, { 1, 2, 3 }},
			{ 6, { 1 }},
		});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}

	// Weighted AdjacencyList.
	{
		auto structure = new graph::AdjacencyList<int, float>({
			{ 1, { std::make_pair(2, 1.0f), std::make_pair(3, 0.5f), std::make_pair(5, 1.5f) }},
			{ 2, { std::make_pair(1, 1.0f), std::make_pair(2, 0.0f), std::make_pair(3, 1.11f) }},
			{ 6, { std::make_pair(1, 22.0f) }},
			});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}

	// Unweighted AdjacencyMatrix.
	{
		auto structure = new graph::AdjacencyMatrix<3, int>({
			std::array<size_t, 3>
			{ 0, 1, 0 },
			{ 1, 1, 0 },
			{ 2, 0, 0 },
		});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}

	// Weighted AdjacencyMatrix.
	{
		// Weight is bool.
		auto structure = new graph::AdjacencyMatrix<3, int, bool>({
			std::array<std::vector<bool>, 3>
			{ std::vector<bool> {}, { true }, {} },
			{ std::vector<bool> { false }, { true }, {} },
			{ std::vector<bool> { true, false }, {}, {} },
		});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}

	// Unweighted EdgeList.
	{
		auto structure = new graph::EdgeList<int>({
			std::make_pair(-1, 5),
			std::make_pair(5, 1),
			std::make_pair(3, 6),
			std::make_pair(6, 3),
			std::make_pair(3, 7),
			std::make_pair(3, 6),
			std::make_pair(0, 0),
		});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}

	// Weighted EdgeList.
	{
		auto structure = new graph::EdgeList<int, double>({
			std::make_pair(-1, std::make_pair(5, 25.0)),
			std::make_pair(5, std::make_pair(1, 5.5)),
			std::make_pair(3, std::make_pair(6, 13.0)),
			std::make_pair(6, std::make_pair(3, 6.4)),
			std::make_pair(3, std::make_pair(7, 2.4)),
			std::make_pair(3, std::make_pair(6, 5.0)),
			std::make_pair(0, std::make_pair(0, 0.0)),
			});
		auto graph = graph::Graph(structure);

		// ...

		delete structure;
	}
}
