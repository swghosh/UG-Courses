import tensorflow as tf
import numpy as np
from typeguard import typechecked
from typing import Union

@tf.function
def train_kmeans(X: Union[tf.Tensor, np.ndarray], 
    k: Union[int, tf.Tensor], 
    n_iter: Union[int, tf.Tensor] = 10) -> (tf.Tensor, tf.Tensor):

    X = tf.convert_to_tensor(X)
    X = tf.cast(X, tf.float32)
    assert len(tf.shape(X)) == 2, "Training data X must be represented as 2D array only"
    m = tf.shape(X)[0]

    k = tf.convert_to_tensor(k, dtype=tf.int64)

    random_select = tf.random.shuffle(X)
    init_centroids = random_select[:k]

    centroids = tf.Variable(init_centroids)
    clusters = tf.zeros([m, ], dtype=tf.int64)
    clusters = tf.Variable(clusters)
    for _ in tf.range(n_iter):
        squared_diffs = tf.square(X[None, :, :] - centroids[:, None, :])
        euclidean_dists = tf.reduce_sum(squared_diffs, axis=-1) ** 0.5
        clusters.assign(tf.argmin(euclidean_dists, axis=0))

        selector = tf.range(k)[:, None] == clusters[None, :]
        
        for c in tf.range(k):
            select = selector[c]
            points = X[select]
            mean_points = tf.reduce_mean(points, axis=0)
            centroids[c].assign(mean_points)
    
    return centroids, clusters
