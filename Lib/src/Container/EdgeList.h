#pragma once

#include <vector>

#include "IGraphContainer.h"

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class EdgeList : public IGraphContainer<_VertexType, _WeightType>
	{
	private:
		using _Mybase = IGraphContainer<_VertexType, _WeightType>;

	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using EdgeType = typename _Mybase::EdgeType;
		using ContainerType = std::vector<std::pair<VertexType, EdgeType>>;

	public:
		EdgeList() : m_data() {}
		EdgeList(const ContainerType& data) : m_data(data) {}

		std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const override
		{
			std::vector<EdgeType> result;

			for (const auto& [iVertex, edge] : m_data)
			{
				if (iVertex == vertex)
				{
					result.push_back(edge);
				}
			}

			return result;
		}

		void AddEdge(VertexType vertex, EdgeType edge) override
		{
			m_data.emplace_back(vertex, edge);
		}

	private:
		ContainerType m_data;
	};
}
