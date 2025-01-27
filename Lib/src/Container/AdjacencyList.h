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
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using EdgeType = typename _Mybase::EdgeType;
		using ContainerType = std::unordered_map<VertexType, std::vector<EdgeType>>;

	public:
		AdjacencyList() : m_data() {}
		AdjacencyList(const ContainerType& data) : m_data(data) {}

		std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const override
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

		void AddEdge(VertexType vertex, EdgeType edge) override
		{
			m_data[vertex].push_back(edge);
		}

	private:
		ContainerType m_data;
	};
}
