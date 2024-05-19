import nltk 
from nltk.corpus import stopwords 
from nltk.tokenize import word_tokenize 
example = """This is a nice paragraph but unfortunately it is very hard to write it by my own so kindly assume this short para as a passage.""" 
stop_words = set(stopwords.words('english')) 
word_tokens = word_tokenize(example) 
filtered_sentence = [w for w in word_tokens if not w.lower() in stop_words] 
print(word_tokens) 
print(filtered_sentence)