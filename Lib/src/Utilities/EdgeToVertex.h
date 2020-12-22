#pragma once

#include <utility>

namespace graph
{
	template<class _VertexType>
	struct _EdgeToVertex
	{
		static auto Do(_VertexType edge)
		{
			return edge;
		}
	};

	template<class _VertexType, class _WeightType>
	struct _EdgeToVertex<std::pair<_VertexType, _WeightType>>
	{
		static auto Do(std::pair<_VertexType, _WeightType> edge)
		{
			return edge.first;
		}
	};
}
