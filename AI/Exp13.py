import nltk 
from nltk.tokenize import sent_tokenize 
txt = "This is message from Lakshay to Earth, please send more troops to moon" 
tokenized = sent_tokenize(txt) 
for i in tokenized: 
 wordsList = nltk.word_tokenize(i) 
print(nltk.pos_tag(wordsList))