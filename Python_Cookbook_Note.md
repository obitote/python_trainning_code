## chapt1

### starred expression:[relevant](http://yaoyao.codes/python/2016/09/25/python-starred-expression)
* `*` :iterable unpacking operator

If the syntax `*expression` appears in the functioin call,exopression must evaluate to `iterable`.Elements from these iterables are treated as if they were additional positional arguments.For the call `f(x1, x2, *y, x3, x4)`,if `y` evaluable to a sequence `y1, ..., yM`,this is equivalent to a call `f(x1, x2, y1, ..., yM, x3, x4).

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