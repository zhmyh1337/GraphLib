#pragma once

#include "Container/IGraphContainer.h"
#include "Container/AdjacencyList.h"
#include "Container/AdjacencyMatrix.h"

namespace graph
{
	// Weighted graph.
	template<class _VertexType, class _WeightType = void>
	class Graph
	{
	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;

	private:
		using Container = IGraphContainer<VertexType, WeightType>;

	public:
		Graph() : m_structure(new AdjacencyList<VertexType, WeightType>()) {}

		explicit Graph(Container* structure) : m_structure(structure) {}

	private:
		Container* m_structure;
	};

	// Unweighted graph.
	template<class _VertexType>
	class Graph<_VertexType, void>
	{
	public:
		using VertexType = _VertexType;

	private:
		using Container = IGraphContainer<VertexType>;

	public:
		Graph() : m_structure(new AdjacencyList<VertexType>()) {}

		explicit Graph(Container* structure) : m_structure(structure) {}

	private:
		Container* m_structure;
	};
}
