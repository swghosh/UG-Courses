import tensorflow as tf
import numpy as np
from typeguard import typechecked
from typing import Union

@tf.function
def kmeans(X: Union[tf.Tensor, np.ndarray], 
    k: int, 
    n_iter: int = 10) -> (tf.Tensor, tf.Tensor):

    X = tf.convert_to_tensor(X)
    X = tf.cast(X, tf.float32)
    assert len(tf.shape(X)) == 2, "Training data X must be represented as 2D array only"
    m = tf.shape(X)[0]

    random_select = tf.random.shuffle(X)
    init_centroids = random_select[:k]

    clusters = tf.zeros([m, ], dtype=tf.int64)
    centroids = init_centroids
    prev_centroids = centroids

    for _ in tf.range(n_iter + 1):
        squared_diffs = tf.square(X[None, :, :] - centroids[:, None, :])
        euclidean_dists = tf.reduce_sum(squared_diffs, axis=-1) ** 0.5
        clusters = tf.argmin(euclidean_dists, axis=0)

        selector = tf.range(k, dtype=tf.int64)[:, None] == clusters[None, :]
        centroids_array = tf.TensorArray(tf.float32, size=k)
        prev_centroids = centroids

        for c in tf.range(k):
            select = selector[c]
            points = X[select]
            mean_points = tf.reduce_mean(points, axis=0)
            centroids_array = centroids_array.write(c, mean_points)
        
        centroids = centroids_array.stack()

    return prev_centroids, clusters

class KMeans:
    @typechecked
    def __init__(self, k: int, n_iter: int = 10):
        self.k = k
        self.n_iter = n_iter
        self.centroids = None
    
    @typechecked
    def fit_predict(self, X: Union[tf.Tensor, np.ndarray]) -> tf.Tensor:
        self.centroids, clusters = kmeans(X, self.k, self.n_iter)
        return clusters
    