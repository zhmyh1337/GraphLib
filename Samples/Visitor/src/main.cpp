#include <Graph.h>

#include "Classes.h"
#include "PrintVisitor.h"

int main()
{
	auto a1 = new A();
	auto a2 = new A();
	auto b = new B();
	auto c1 = new C();
	auto c2 = new C();
	auto d = new D();

	auto graphStructure = new graph::EdgeList<IBase*>({
		std::make_pair(a1, b),
		std::make_pair(b, a2),
		std::make_pair(a2, a2),
		std::make_pair(b, c1),
		std::make_pair(c1, d),
		std::make_pair(d, a1),
		std::make_pair(d, c2),
	});
	auto graph = graph::Graph(graphStructure);

	auto printVisitor = new PrintVisitor();
	graph.DepthFirstSearch(a1, [printVisitor](auto from, IBase* to) { to->Accept(printVisitor); });

	delete graphStructure;
}
