#pragma once

#include "IGraphContainer.h"

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class AdjacencyList : IGraphContainer<_VertexType, _WeightType>
	{

	};
}
