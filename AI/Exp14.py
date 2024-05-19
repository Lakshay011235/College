import nltk 
nltk.download('wordnet') 
from nltk.stem import WordNetLemmatizer 
lemmatizer = WordNetLemmatizer() 
text = "This is the file of Lakshay Sharma. There are checkpoints in the digital file." 
for i in text.split(): 
 print(i,": ", lemmatizer.lemmatize(i))