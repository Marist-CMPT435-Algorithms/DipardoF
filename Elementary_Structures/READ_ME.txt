# Data Structures Project: AI-Generated Code Analysis

## Array-backed Stack 

### Is It Correct?
After digging through the code and comparing it with our textbook, I think the Array-backed Stack is pretty solid. 

Key things I noticed:
- The `push()` method looks legit - it adds items and stops you from overflowing
- `pop()` removes items and handles empty stack scenarios
- Error handling seems robust

## Array-backed Queue

### Checking the Implementation
This queue implementation uses a circular buffer approach, which means it can wrap around and use array space more efficiently.

Interesting bits:
- Uses modulo math (`% CAPACITY`) to handle array wrapping
- Keeps track of current size to know when it's full or empty
- O(1) time complexity for adding and removing items

Potential weakness: Once you hit the max capacity, you're stuck with no automatic resizing.

## Linked Stack

### Memory and Pointers Everywhere
The Linked Stack is basically a chain of dynamically allocated nodes. Compared to the array version, this one can technically grow forever.

What makes it work:
- Creates nodes as you push items
- Properly deletes nodes when you pop or clear the stack
- No fixed size limit

Careful spots:
- Make sure you're not leaking memory
- The destructor is crucial here to clean up those nodes

## Linked Queue

### Another Linked Data Structure
Similar to the Linked Stack, but with front and rear pointers to manage the queue behavior.

Cool things:
- Efficient enqueue and dequeue operations
- Dynamically grows as you add items
- Separate front and rear tracking makes queue operations smooth

## Reflection: Working with AI to Build Data Structures

### About the Process

This was pretty interesting. The AI did more than just spit out code - it generated implementations that made me think about how these data structures actually work.

Some key takeaways:
- AI is great for getting a solid starting point
- BUT you absolutely cannot just trust the code blindly
- Reading and understanding the generated code is where the real learning happens

Some Challenges:
- Figuring out what to look for when reviewing the code
- Understanding why certain design choices were made
- Catching subtle potential issues

---

