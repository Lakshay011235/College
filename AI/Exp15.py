import nltk, random 
training_data = [ 
 ("The energetic dog played fetch in the park", "animal"), 
 ("Roses are often given as a symbol of love", "flower"), 
 ("Python is a versatile programming language", "programming"), 
 ("Heavy snowfall blanketed the city overnight", "weather"), 
 ("Apples are a popular choice for making pies", "fruit"), 
 ("Tennis requires agility and precision", "sport"), 
 ("The wise owl hooted softly in the moonlight", "animal"), 
 ("Tulips come in a variety of vibrant colors", "flower"), 
 ("C++ is often used for system programming", "programming"), 
 ("Gusty winds swept across the open plains", "weather"), 
 ("Oranges are rich in vitamin C", "fruit"), 
 ("Soccer is the most popular sport worldwide", "sport"), 
 ("The majestic lion roared loudly in the jungle", "animal"), 
 ("Daisies are known for their simple beauty", "flower"), 
 ("JavaScript is commonly used for web development", "programming"), 
 ("Torrential rain caused flooding in low-lying areas", "weather"), 
 ("Grapes are often used to make wine", "fruit"), 
 ("Golf requires precision and concentration", "sport"), 
] 
def extract_features(text): 
 return {word: True for word in nltk.word_tokenize(text)} 
 
featuresets = [(extract_features(text), label) for (text, label) in training_data] 
classifier = nltk.NaiveBayesClassifier.train(featuresets) 
sample = "Sunflowers are known for their bright yellow petals" 
 
features = extract_features(sample) 
predicted_label = classifier.classify(features) 
print("Test Sentence:", sample,"\nPredicted Label:", predicted_label) 