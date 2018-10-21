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
* `append(x)`:Add x to the right side of the deque.
* `appendleft(x)`:Add x to the left side of the deque.
* `clear()`:Remove all elements from the deque leaving it with length 0.
* `copy()`:Create a shallow copy of the deque.
* `count(x)`Count the number of deque elements equal to x.
* `extend(iterable)`:Extend the right side of the deque by appending elements from the iterable argument.
* `extendleft(iterable)`:Extend the left side of the deque by appending elements from iterable. Note, the series of left appends results in reversing the order of elements in the iterable argument.
* `index(x[, start[, stop]])`:Return the position of x in the deque (at or after index start and before index stop). Returns the first match or raises ValueError if not found.
* `insert(i, x)`:Insert x into the deque at position i.If the insertion would cause a bounded deque to grow beyond maxlen, an IndexError is raised.
* `pop()`:Remove and return an element from the right side of the deque. If no elements are present, raises an IndexError.
* `popleft()`:Remove and return an element from the left side of the deque. If no elements are present, raises an IndexError.
* `remove(value)`:Remove the first occurrence of value. If not found, raises a ValueError.
* `reverse()`:Reverse the elements of the deque in-place and then return None.
* `rotate(n=1)`:Rotate the deque n steps to the right. If n is negative, rotate to the left.When the deque is not empty, rotating one step to the right is equivalent to d.appendleft(d.pop()), and rotating one step to the left is equivalent to d.append(d.popleft()).

### 程序注释
```python
def swap(a):
    for b in range(5):
        a, b = b, a + b
        print(a,b)

swap(1)

Result:
0 1
1 1
2 3
3 5
4 7

Note:赋值运算，先计算右边算式再进行赋值
```

### heapq模块
`heapq`也即`Heap queue algorithm`堆队列算法。该模块提供了堆队列算法的实现，也称为优先级队列算法。

堆是二叉树，每个父节点的值小于或等于其任何子节点。 对于所有`k`，此实现使用堆`heap[k] <= heap[2*k+1]`和`heap[k] <= heap[2*k+2]`的数组，从零开始计数元素。为了比较，不存在的元素被认为是无限的。堆的重要特性是`heap[0]`总是最小的那个元素。

要创建堆，可使用初始化为`[]`的列表，或者可以通过函数`heapify（）`将填充的列表转换为堆。 

* `heapq.heappush(heap, item)`:Push the value item onto the heap, maintaining the heap invariant.
* `heapq.heappop(heap)`：Pop and return the smallest item from the heap, maintaining the heap invariant. If the heap is empty, `IndexError` is raised. To access the smallest item without popping it, use heap[0].
* `heapq.heappushpop(heap, item)`：Push item on the heap, then pop and return the smallest item from the heap. The combined action runs more efficiently than `heappush()` followed by a separate call to `heappop()`.
* `heapq.heapify(x)`：Transform list x into a heap, in-place, in linear time.
* `heapq.heapreplace(heap, item)`：Pop and return the smallest item from the heap, and also push the new item. The heap size doesn’t change. If the heap is empty, IndexError is raised.
* `heapq.merge(*iterables, key=None, reverse=False)`：
* `heapq.nlargest(n, iterable, key=None)`：Return a list with the n largest elements from the dataset defined by iterable. key, if provided, specifies a function of one argument that is used to extract a comparison key from each element in the iterable: `key=str.lower` Equivalent to: `sorted(iterable, key=key,reverse=True)[:n]`.
* `heapq.nsmallest(n, iterable, key=None)`：Return a list with the n smallest elements from the dataset defined by iterable. key, if provided, specifies a function of one argument that is used to extract a comparison key from each element in the iterable: `key=str.lower` Equivalent to: `sorted(iterable, key=key)[:n]`.
  
The latter two functions perform best for smaller values of n. For larger values, it is more efficient to use the sorted() function. 

### lambda表达式
lambda表达式通常是在需要一个函数，但简单起见不想命名它的场合下使用，即匿名函数。
```python
example1：
>>>add = lambda x, y: x + y
>>>add(1,2)
3
example2: 将列表中的元素按照绝对值大小进行升序排列
list1 = [3,5,-4,-1,0,-2,-6]
sorted(list1, key=lambda x: abs(x))
常规方法：
list1 = [3,5,-4,-1,0,-2,-6]
def get_abs(x):
    return abs(x)
sorted(list1,key=get_abs)
```

