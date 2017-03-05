import numpy as np
from sklearn.neighbors import KDTree


class MatrixKNN(object):
	def __init__(self, deg):
		self.dist_mtx = None
		self.num_cycles = deg

	def fit(self, X_train, y_train):
		self.X_train = X_train
		self.y_train = y_train
		return self

	def predict(self, X_test, k=1):
		num_train_obj = self.X_train.shape[0]
		num_test_obj = X_test.shape[0]
		self.dist_mt = np.zeros((num_test_obj, num_train_obj))
		answers = np.zeros(num_test_obj)
                    
		if self.num_cycles == 0:
			ones_test = np.ones((X_test.shape[1], self.X_train.shape[0]))
			ones_train = np.ones((X_test.shape[0], self.X_train.shape[1]))
			self.dist_mt = np.dot(X_test**2, ones_test) - 2*np.dot(X_test, np.transpose(self.X_train)) + np.dot(ones_train,np.transpose(self.X_train**2))
		
		if self.num_cycles == 1:
			for i in range(num_test_obj):
				self.dist_mt[i] = np.dot(np.ones( (1,X_test.shape[1]) ), np.transpose( (self.X_train - X_test[i])**2 ))

		if self.num_cycles == 2:
			for i in range(num_test_obj):
				for j in range(num_train_obj):
					a = X_test[i] - self.X_train[j]
					self.dist_mt[i][j] = np.dot(a, a)

		for i in range(num_test_obj):
			nearest_y = []
			indices = np.argsort(self.dist_mt[i])
            
			for j in range(k):
				nearest_y.append(self.y_train[indices[j]])
			num_class = 10            
			vote = np.zeros(num_class)
            
			for j in range(k):
				vote[nearest_y[j]] += 1
                
			answers[i] = np.argmax(vote)

		return answers


class KDTreeKNN(object):
	def __init__(self):
		pass

	def fit(self, X_train, y_train):
		self.X_train = X_train
		self.y_train = y_train
		self.kd_tree = KDTree(X_train)
		return self

	def predict(self, X_test, k = 1):
		num_test_obj = X_test.shape[0]
		answers = np.zeros(num_test_obj)
		num_class = 10  
		for i in range(num_test_obj):
			X_array = X_test[i].reshape(1, -1)
			(dist, ind) = (self.kd_tree.query(X_array, k))           
			vote = np.zeros(num_class)
			for j in range(k):
				vote[self.y_train[ind[0][j]]] += 100/(dist[0][j]+0.01)
			answers[i] = int(np.argmax(vote))
            
		return answers
