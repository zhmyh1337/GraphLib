#pragma once

#include <vector>

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class IGraphContainer
	{
	public:
		using EdgeType = std::pair<_VertexType, _WeightType>;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(_VertexType vertex) = 0;
	};

	template<class _VertexType>
	class IGraphContainer<_VertexType, void>
	{
	public:
		using EdgeType = _VertexType;

	public:
		virtual std::vector<EdgeType> GetAllEdgesOfVertex(_VertexType vertex) = 0;
	};
}
