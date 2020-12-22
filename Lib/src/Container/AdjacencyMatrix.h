#pragma once

#include <array>
#include <algorithm>
#include <iterator>

#include "IGraphContainer.h"

namespace graph
{
	// Weighted graph.
	template<size_t _MaxVertexIndex, class _VertexType, class _WeightType = void>
	class AdjacencyMatrix : public IGraphContainer<_VertexType, _WeightType>
	{
		static_assert(std::is_convertible_v<_VertexType, size_t>, "_VertexType must be convertible to size_t (as an index).");

	private:
		using _Mybase = IGraphContainer<_VertexType, _WeightType>;

	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using EdgeType = typename _Mybase::EdgeType;
		using ContainerType = std::array<std::array<std::vector<_WeightType>, _MaxVertexIndex>, _MaxVertexIndex>;

	public:
		AdjacencyMatrix() : m_data() {}
		AdjacencyMatrix(const ContainerType& data) : m_data(data) {}

		std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const override
		{
			std::vector<EdgeType> result;

			for (size_t i = 0; i < _MaxVertexIndex; ++i)
			{
				auto otherVertex = static_cast<VertexType>(i);
				const auto& source = m_data[static_cast<size_t>(vertex)][otherVertex];
				std::transform(source.begin(), source.end(), std::back_inserter(result),
					[otherVertex](WeightType weight) -> EdgeType { return std::make_pair(otherVertex, weight); }
				);
			}

			return result;
		}

		void AddEdge(VertexType vertex, EdgeType edge) override
		{
			m_data[static_cast<size_t>(vertex)][static_cast<size_t>(edge.first)].push_back(edge.second);
		}

		constexpr auto MaxVertexIndex() const
		{
			return _MaxVertexIndex;
		}

	private:
		ContainerType m_data;
	};

	// Unweighted graph.
	template<size_t _MaxVertexIndex, class _VertexType>
	class AdjacencyMatrix<_MaxVertexIndex, _VertexType, void> : public IGraphContainer<_VertexType>
	{
		static_assert(std::is_convertible_v<_VertexType, size_t>, "_VertexType must be convertible to size_t (as an index).");

	private:
		using _Mybase = IGraphContainer<_VertexType>;

	public:
		using VertexType = _VertexType;
		using EdgeType = typename _Mybase::EdgeType;
		using ContainerType = std::array<std::array<size_t, _MaxVertexIndex>, _MaxVertexIndex>;

	public:
		AdjacencyMatrix() : m_data() {}
		AdjacencyMatrix(const ContainerType& data) : m_data(data) {}

		std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const override
		{
			std::vector<EdgeType> result;

			for (size_t i = 0; i < _MaxVertexIndex; ++i)
			{
				auto otherVertex = static_cast<VertexType>(i);
				auto edgesCount = m_data[static_cast<size_t>(vertex)][i];
				if (edgesCount)
				{
					result.insert(result.end(), edgesCount, otherVertex);
				}
			}

			return result;
		}

		void AddEdge(VertexType vertex, EdgeType edge) override
		{
			m_data[static_cast<size_t>(vertex)][static_cast<size_t>(edge)]++;
		}
		
		constexpr auto MaxVertexIndex() const
		{
			return _MaxVertexIndex;
		}

	private:
		ContainerType m_data;
	};
}
