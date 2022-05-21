from abc import ABCMeta, abstractmethod, ABC
import random
import math


class MaterialPoint(metaclass=ABCMeta):
    def __init__(self, t):
        self._a1, self._a2, self._x0, self._y0 = random.randint(0, 5), random.randint(0, 5), \
                                                 random.randint(0, 5), random.randint(0, 5)
        self._t = t
        self._x, self._y = self._find_x(), self._find_y()

    def __str__(self):
        return f'(x;y) = ({self._x}; {self._y})'

    @abstractmethod
    def _find_x(self): pass

    @abstractmethod
    def _find_y(self): pass

    @abstractmethod
    def get_x(self): pass

    @abstractmethod
    def get_y(self): pass

    @abstractmethod
    def get_distance(self, ox, oy): pass


class MaterialPointX(MaterialPoint, ABC):
    def __init__(self, t):
        super().__init__(t)

    def _find_x(self):
        return round(self._x0 + self._a1 * math.sin(self._t), 4)

    def get_x(self):
        return self._x

    def _find_y(self):
        return 0

    def get_y(self):
        return self._y

    def get_distance(self, ox, oy):
        return round(math.sqrt((self._x - ox) ** 2 + (self._y - oy) ** 2), 4)


class MaterialPointXY(MaterialPoint, ABC):
    def __init__(self, t):
        super().__init__(t)

    def _find_x(self):
        return round(self._x0 + self._a1 * math.sin(self._t), 4)

    def get_x(self):
        return self._x

    def _find_y(self):
        return round(self._y0 + self._a2 * math.cos(self._t), 4)

    def get_y(self):
        return self._y

    def get_distance(self, ox, oy):
        return round(math.sqrt((self._x - ox) ** 2 + (self._y - oy) ** 2), 4)
