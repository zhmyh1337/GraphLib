#pragma once

#include <functional>
#include <unordered_set>
#include <queue>

#include "Container/IGraphContainer.h"
#include "Container/AdjacencyList.h"
#include "Container/AdjacencyMatrix.h"
#include "Container/EdgeList.h"
#include "Utilities/EdgeToInversed.h"
#include "Utilities/EdgeToVertex.h"

namespace graph
{
	template<class _VertexType, class _WeightType = void>
	class Graph
	{
	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
		using Container = IGraphContainer<VertexType, WeightType>;
		using EdgeType = typename Container::EdgeType;

	public:
		Graph() : m_structure(new AdjacencyList<VertexType, WeightType>()) {}

		explicit Graph(Container* structure) : m_structure(structure) {}

		void AddEdge(VertexType vertex, EdgeType edge)
		{
			m_structure->AddEdge(vertex, edge);
		}
		
		void AddBidirectionalEdge(VertexType vertex, EdgeType edge)
		{
			m_structure->AddEdge(vertex, edge);
			m_structure->AddEdge(_EdgeToVertex<EdgeType>::Do(edge), _EdgeToInversed<EdgeType>::Do(vertex, edge));
		}

		std::vector<EdgeType> GetAllEdgesOfVertex(VertexType vertex) const
		{
			return m_structure->GetAllEdgesOfVertex(vertex);
		}

		void BreadthFirstSearch(VertexType startingVertex, std::function<void(VertexType, EdgeType)> callback) const
		{
			std::unordered_set<VertexType> visitedVertices;
			std::queue<VertexType> queue;

			visitedVertices.insert(startingVertex);
			queue.push(startingVertex);

			while (!queue.empty())
			{
				auto vertex = queue.front();
				queue.pop();

				for (const auto edge : m_structure->GetAllEdgesOfVertex(vertex))
				{
					auto newVertex = _EdgeToVertex<EdgeType>::Do(edge);
					if (!visitedVertices.count(newVertex))
					{
						visitedVertices.insert(newVertex);
						queue.push(newVertex);
						callback(vertex, edge);
					}
				}
			}
		}

		void DepthFirstSearch(VertexType startingVertex, std::function<void(VertexType, EdgeType)> callback) const
		{
			std::unordered_set<VertexType> visitedVertices;
			DepthFirstSearch(startingVertex, callback, visitedVertices);
		}

	private:
		void DepthFirstSearch(VertexType vertex, std::function<void(VertexType, EdgeType)> callback,
			std::unordered_set<VertexType>& visitedVertices) const
		{
			visitedVertices.insert(vertex);

			for (const auto edge : m_structure->GetAllEdgesOfVertex(vertex))
			{
				auto newVertex = _EdgeToVertex<EdgeType>::Do(edge);
				if (!visitedVertices.count(newVertex))
				{
					callback(vertex, edge);
					DepthFirstSearch(newVertex, callback, visitedVertices);
				}
			}
		}

	private:
		Container* m_structure;
	};
}
