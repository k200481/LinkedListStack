#include "Stack.h"

Stack::~Stack()
{
	delete top;
	top = nullptr;
}

void Stack::Push(int val)
{
	top = new Node( val, top );
}

int Stack::Pop()
{
	if ( !Empty() ) {
		const int val = top->GetValue();
		top = Node::DestroyNode(top);
		return val;
	}
	else {
		return -1;
	}
}

int Stack::Size() const
{
	if ( !Empty() ) {
		return top->CountNodesInChain();
	}
	else {
		return 0;
	}
}

bool Stack::Empty() const
{
	return top == nullptr;
}

Stack::Stack(const Stack& source)
{
	*this = source;
}

Stack& Stack::operator=(const Stack& source)
{
	if ( this == &source ) {
		return *this;
	}
	if ( !Empty() ) {
		delete top;
		top = nullptr;
	}

	if ( !source.Empty() ) {
		top = new Node(*(source.top));
	}
	return *this;
}