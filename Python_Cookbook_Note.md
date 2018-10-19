## chapt1

### starred expression:[relevant](http://yaoyao.codes/python/2016/09/25/python-starred-expression)
* `*` :iterable unpacking operator

If the syntax `*expression` appears in the functioin call,exopression must evaluate to `iterable`.Elements from these iterables are treated as if they were additional positional arguments.For the call `f(x1, x2, *y, x3, x4)`,if `y` evaluable to a sequence `y1, ..., yM`,this is equivalent to a call `f(x1, x2, y1, ..., yM, x3, x4)`.

If the form `*identifier` is present, it is initialized to a **tuple** receiving any excess positional parameters, defaulting to the empty tuple.

* `**` :dictionary unpacking operator

If the syntax `**expression` appears in the function call, expression must evaluate to a **mapping**, the contents of which are treated as additional keyword arguments. If a keyword is already present (as an explicit keyword argument, or from another unpacking), a `TypeError` exception is raised.

If the form `**identifier` is present, it is initialized to a new **dictionary** receiving any excess keyword arguments, defaulting to a new empty dictionary.

### program comment
```python
item = [1, 10, 7, 4, 5, 9]

def sum(items):
    head, *tail = items
    return head + sum(tail) if tail else head

>>>sum(items)
36
```
`return head + sum(tail) if tail else head` can treat as:
```python
if tail:
    return head + sum(tail)
else：
    return head
```

### deque
`class collections.deque([iterable[, maxlen]])`:
Returns a new deque object initialized left-to-right (using append()) with data from iterable. If iterable is not specified, the new deque is empty.
Deques are a generalization of stacks and queues (the name is pronounced “deck” and is short for “double-ended queue”). Deques support thread-safe, memory efficient appends and pops from either side of the deque with approximately the same O(1) performance in either direction.
If maxlen is not specified or is `None`, deques may grow to an arbitrary length. Otherwise, the deque is bounded to the specified maximum length. Once a bounded length deque is full, when new items are added, a corresponding number of items are discarded from the opposite end. Bounded length deques provide functionality similar to the `tail` filter in Unix. They are also useful for tracking transactions and other pools of data where only the most recent activity is of interest.
Deque objects support the following methods:
`append(x)`:Add x to the right side of the deque.
`appendleft(x)`:Add x to the left side of the deque.
`clear()`:Remove all elements from the deque leaving it with length 0.
`copy()`:Create a shallow copy of the deque.
`count(x)`Count the number of deque elements equal to x.
`extend(iterable)`:Extend the right side of the deque by appending elements from the iterable argument.
`extendleft(iterable)`:Extend the left side of the deque by appending elements from iterable. Note, the series of left appends results in reversing the order of elements in the iterable argument.
`index(x[, start[, stop]])`:Return the position of x in the deque (at or after index start and before index stop). Returns the first match or raises ValueError if not found.
`insert(i, x)`:Insert x into the deque at position i.If the insertion would cause a bounded deque to grow beyond maxlen, an IndexError is raised.
`pop()`:Remove and return an element from the right side of the deque. If no elements are present, raises an IndexError.
`popleft()`:Remove and return an element from the left side of the deque. If no elements are present, raises an IndexError.
`remove(value)`:Remove the first occurrence of value. If not found, raises a ValueError.
`reverse()`:Reverse the elements of the deque in-place and then return None.
`rotate(n=1)`:Rotate the deque n steps to the right. If n is negative, rotate to the left.When the deque is not empty, rotating one step to the right is equivalent to d.appendleft(d.pop()), and rotating one step to the left is equivalent to d.append(d.popleft()).