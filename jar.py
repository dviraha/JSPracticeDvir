class Jar:
    def __init__(self, capacity=12):
        # should initialize a cookie jar with the given capacity,
        # which represents the maximum number of cookies that can
        # fit in the cookie jar. If capacity is not a non-negative int,
        # though, __init__ should instead raise a ValueError (via raise ValueError).
        if capacity < 0:
            raise ValueError('Jar capacity error')
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        # should return a str with n 🍪, where n is the number of cookies in the cookie jar.
        # For instance, if there are 3 cookies in the cookie jar, then str should return "🍪🍪🍪"
        return self.size * '🍪'

    def deposit(self, n):
        # should add n cookies to the cookie jar. If adding that many would
        # exceed the cookie jar’s capacity, though, deposit should instead raise a ValueError.
        if n > self.capacity or (self.size + n) > self.capacity:
            raise ValueError('Too many cookies in jar')
        self._size += n

    def withdraw(self, n):
        # should remove n cookies from the cookie jar. Nom nom nom. If there aren’t that
        # many cookies in the cookie jar, though, withdraw should instead raise a ValueError.
        if self.size < n:
            raise ValueError('Not enough cookies in jar')
        self._size -= n

    @property
    def capacity(self):
        # should return the cookie jar’s capacity.
        return self._capacity

    @property
    def size(self):
        # should return the number of cookies actually in the cookie jar.
        return self._size


jar = Jar()
jar.deposit(2)
jar.withdraw(1)
print(str(jar))
