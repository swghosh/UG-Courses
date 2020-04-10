import tensorflow as tf

X = tf.convert_to_tensor([
    [ 2., 10.],
    [ 2.,  5.],
    [ 8.,  4.],
    [ 5.,  8.],
    [ 7.,  5.],
    [ 6.,  4.],
    [ 1.,  2.],
    [ 4.,  9.]])
k = 3

import tf_kmeans
print(tf.autograph.to_code(tf_kmeans.kmeans.python_function))

print(tf_kmeans.kmeans(X, k))

from tf_kmeans import KMeans

kmeans = KMeans(k)
clusters = kmeans.fit_predict(X)
print(clusters)
print(kmeans.centroids)