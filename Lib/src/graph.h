#pragma once

namespace graph
{
	/// <summary>
	/// Weighted graph.
	/// </summary>
	/// <typeparam name="_VertexType">Type of vertices.</typeparam>
	/// <typeparam name="_WeightType">Type of weights.</typeparam>
	template<class _VertexType, class _WeightType = void>
	class Graph
	{
	public:
		using VertexType = _VertexType;
		using WeightType = _WeightType;
	};

	/// <summary>
	/// Unweighted graph.
	/// </summary>
	/// <typeparam name="_VertexType">Type of vertices.</typeparam>
	template<class _VertexType>
	class Graph<_VertexType, void>
	{
	public:
		using VertexType = _VertexType;
	};
}
