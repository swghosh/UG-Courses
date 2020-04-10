import tensorflow as tf
import numpy as np

X = np.array([[ 2., 10.],
    [ 2.,  5.],
    [ 8.,  4.],
    [ 5.,  8.],
    [ 7.,  5.],
    [ 6.,  4.],
    [ 1.,  2.],
    [ 4.,  9.]])
k = 3

import tf_kmeans
tf_kmeans.train_kmeans(X, k)