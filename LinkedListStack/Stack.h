#pragma once

class Stack
{
private:
	struct Node {
		//creates a new node which points t the one after it
		Node(int x, Node* next)
			:
			val( x ),
			next( next )
		{
		}

		//deep copies the entire list statring at the given source
		Node( const Node& source ) {
			*this = source;
		}

		//recursive, deletes all nodes starting at the one delete is called on, or the whole list at end of scope
		~Node() {
			if (next != nullptr) {
				delete next;
				next = nullptr;
			}
		}

		//this is a recursive function
		Node& operator=( const Node& source ) {
			val = source.val;
			if (source.next == nullptr) {
				next = nullptr;
			}
			else {
				next = new Node( *(source.next) );
			}
			return *this;
		}

		//non-recursive, just deletes the given node
		static Node* DestroyNode( Node* node ) {
			if ( node != nullptr ) {
				Node* temp = node->next;
				node->next = nullptr;
				delete node;
				return temp;
			}
			return nullptr;
		}
		//non-recursive, just disconnects the node it is called on
		Node* Disconnect() {
			Node* temp = next;
			next = nullptr;
			return temp;
		}

		//recursively counts all nodes in the list starting at the one it is called on
		int CountNodesInChain() const {
			if ( next == nullptr ) {
				return 1;
			}
			return 1 + next->CountNodesInChain();
		}

		//get the value stored at a node
		int GetValue() const {
			return val;
		}
		//get pointer to the next node
		Node* GetNext() {
			return next;
		}
		//get pointer to the next node
		const Node* GetNext() const {
			return next;
		}

	private:
		int val;
		Node* next;
	};

public:
	Stack() = default;
	~Stack();
	//adds an itim to the top of the stack
	void Push( int val );
	//removes items from the top of the stack and return value
	int Pop();
	//returns the size of the stack
	int Size() const;
	//checks if stack is empty
	bool Empty() const;

	//copy-constructor, deep-copies the entire stack
	Stack( const Stack& source );
	//assignment operator, deep copies the entire stack
	Stack& operator=( const Stack& source );

private:
	struct Node* top = nullptr;
};