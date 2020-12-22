#include <iostream>
#include <Graph.h>

class IWeightable
{
public:
	virtual float Mass() = 0;
};

class Apple : public IWeightable
{
public:
	Apple(float mass) : m_mass(mass) {}

	float Mass() override
	{
		return m_mass;
	}

private:
	const float m_mass;
};

class Box : public IWeightable
{
public:
	Box(float selfWeight) : m_selfWeight(selfWeight), m_graph(nullptr) {}

	void SetGraph(const graph::Graph<IWeightable*>* graph)
	{
		m_graph = graph;
	}

	float Mass() override
	{
		float sum = m_selfWeight;

		for (const auto edge : m_graph->GetAllEdgesOfVertex(this))
		{
			sum += edge->Mass();
		}

		return sum;
	}

private:
	const float m_selfWeight;
	const graph::Graph<IWeightable*>* m_graph;
};

class Storage : public IWeightable
{
public:
	void SetGraph(const graph::Graph<IWeightable*>* graph)
	{
		m_graph = graph;
	}

	float Mass() override
	{
		float sum = 0.0f;

		for (const auto edge : m_graph->GetAllEdgesOfVertex(this))
		{
			sum += edge->Mass();
		}

		return sum;
	}

private:
	const graph::Graph<IWeightable*>* m_graph;
};

int main()
{
	Apple* apples[] = { new Apple(0.5f), new Apple(0.3f), new Apple(0.25f), new Apple(0.4f), new Apple(0.35f) };
	auto box1 = new Box(1.0f);
	auto box2 = new Box(1.5f);
	auto storage = new Storage();

	auto graph = graph::Graph<IWeightable*>();
	graph.AddEdge(storage, box1);
	graph.AddEdge(storage, box2);
	graph.AddEdge(box1, apples[0]);
	graph.AddEdge(box1, apples[1]);
	graph.AddEdge(box1, apples[2]);
	graph.AddEdge(box2, apples[3]);
	graph.AddEdge(box2, apples[4]);

	box1->SetGraph(&graph);
	box2->SetGraph(&graph);
	storage->SetGraph(&graph);

	std::cout << "Summary storage weight: " << storage->Mass() << std::endl;
}
