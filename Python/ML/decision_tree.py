"""
    module: decision_tree
    author: Vincnet Sheng
    data:   2018/01/07, Sun
    desc:   The module provide a class of Decison Tree, to be used for training a model
            and perdict the unknown data after generating a instance.
"""

import numpy as np
import math 
import pandas as pd

class DecisionTree(object):
    def __init__(self):
        print('Init decision tree!')
    
    def set_params(self, params):
        """
            name:   set_params
            params: params  <dict>
            desc:   Set hyper params of the model.
        """
        print('Here is your params ~ ')
        for item in params:
            print(item + '\t' + str(params[item]))

    def train(self, data):
        """
            name:   train
            params: data  <numpy.ndarray>
            desc:   Train you model by the data in your train set, and you'd better
                    provide necessary options. If you not, default options will be
                    used.
        """
        print('The decision is Training now ~ ')
        

    def evaluate(self):
        """
            name:   evaluate
            desc:   Evaluate you model by the data in your validate set, and you'd better
                    provide necessary options. If you not, default options will be
                    used.
        """
        print('Now we are evaluate your model ~ ')

    def predict(self, data):
        """
            name:   predict
            params: data  <numpy.ndarray>
            desc:   Predict the target of your data in test set by the model trained
                    in the previous step.You're suggested to provide some options. If you not, default options will be
                    used.
        """
        print('Here is the predict re sult ... ')

    def get_feature_weight(self):
        """
            name:   get_feature_weight
            desc:   Train you model by the data in your train set, and you'd better
                    provide necessary options. If you not, default options will be
                    used.
        """
        print('Here is the feature weight ... ')


def main():
    """
        name:   main
        desc:   The function is a test case for testing the correction of the Class, and
                provide a demo for users.
    """
    dtree = DecisionTree()
    params = {
        "lr": 0.001,
        "max_height": 10
    }
    dtree.set_params(params)
    dtree.train('Here is the data ~ ')
    dtree.evaluate()
    dtree.predict('Here is the data ~ ')
    dtree.get_feature_weight()

if __name__ == '__main__':
    main()

