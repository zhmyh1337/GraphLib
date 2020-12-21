#pragma once

#include <vector>

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class IGraphContainer
	{
	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using EdgeType = std::pair<VertexType, WeightType>;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const = 0;
	};

	template<class _VertexType>
	class IGraphContainer<_VertexType, void>
	{
	public:
		using EdgeType = _VertexType;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(_VertexType vertex) const = 0;
	};
}
