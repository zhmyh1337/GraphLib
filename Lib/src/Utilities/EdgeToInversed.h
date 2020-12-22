#pragma once

#include <utility>

namespace graph
{
	template<class _VertexType>
	struct _EdgeToInversed
	{
		static auto Do(_VertexType vertex, _VertexType edge)
		{
			return vertex;
		}
	};

	template<class _VertexType, class _WeightType>
	struct _EdgeToInversed<std::pair<_VertexType, _WeightType>>
	{
		static auto Do(_VertexType vertex, std::pair<_VertexType, _WeightType> edge)
		{
			return std::make_pair(vertex, edge.second);
		}
	};
}
