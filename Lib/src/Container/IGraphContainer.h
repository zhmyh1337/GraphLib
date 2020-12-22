#pragma once

#include <vector>

namespace graph
{
	// Weighted graph.
	template<class _VertexType, class _WeightType = void>
	class IGraphContainer
	{
	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using EdgeType = std::pair<VertexType, WeightType>;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const = 0;

		virtual void AddEdge(VertexType vertex, EdgeType edge) = 0;
	};

	// Unweighted graph.
	template<class _VertexType>
	class IGraphContainer<_VertexType, void>
	{
	public:
		using VertexType = _VertexType;
		using EdgeType = VertexType;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const = 0;

		virtual void AddEdge(VertexType vertex, EdgeType edge) = 0;
	};
}
