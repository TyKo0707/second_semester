from abc import ABCMeta, abstractmethod, ABC


class MaterialPoint(metaclass=ABCMeta):
    @abstractmethod
    def get_attr(self):
        pass


class MaterialPointX(MaterialPoint, ABC):
    def get_attr(self):
        print('a')


class MaterialPointXY(MaterialPoint, ABC):
    def get_attr(self):
        print('b')
