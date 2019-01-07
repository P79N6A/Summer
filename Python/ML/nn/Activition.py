import numpy as np
import math


class NNDense(object):
    def __init__(self, size, init):
        """

        """
        self.size = size
        self.data = np.array([init() for i in range(size)])

    def forward(self, data):
        pass

    def backward(self, data):
        pass
