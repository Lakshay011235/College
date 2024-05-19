import nltk 
from nltk.stem import PorterStemmer 
from nltk.tokenize import word_tokenize 
ps = PorterStemmer() 
 
sentence = "This is an urgent text to check teh stemming process for chainging testing hiring" 
words = word_tokenize(sentence) 
for w in words: 
 print(w, " : ", ps.stem(w)) 