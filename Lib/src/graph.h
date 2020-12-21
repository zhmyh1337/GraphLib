#pragma once

#include "Container/IGraphContainer.h"
#include "Container/AdjacencyList.h"

namespace graph
{
	/// <summary>
	/// Weighted graph.
	/// </summary>
	/// <typeparam name="_VertexType">Type of vertices.</typeparam>
	/// <typeparam name="_WeightType">Type of weights.</typeparam>
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

	/// <summary>
	/// Unweighted graph.
	/// </summary>
	/// <typeparam name="_VertexType">Type of vertices.</typeparam>
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
