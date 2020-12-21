#pragma once

#include <unordered_map>

#include "IGraphContainer.h"

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class AdjacencyList : public IGraphContainer<_VertexType, _WeightType>
	{
	private:
		using _Mybase = IGraphContainer<_VertexType, _WeightType>;

	public:
		using _Mybase::EdgeType;

	public:
		std::vector<EdgeType> GetAllEdgesOfVertex(_VertexType vertex) const override
		{
			auto it = m_data.find(vertex);
			if (it == m_data.end())
			{
				return std::vector<EdgeType>();
			}
			else
			{
				return it->second;
			}
		}

	private:
		std::unordered_map<_VertexType, std::vector<EdgeType>> m_data;
	};
}
