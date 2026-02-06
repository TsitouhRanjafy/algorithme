# Example:
    # 'running' → 'run'
    # 'happily' → 'happy'

# Advantages:
    # Very fast.
    # Good for smaller datasets or quick preprocessing.

# Limitations:
    # Aggressive which can result in over-stemming.
    # Less efficient than Snowball in larger datasets.


import nltk
nltk.download('punkt')

from stemming.paicehusk import stem
from nltk.tokenize import word_tokenize

text = "The cats are running swiftly."
words = word_tokenize(text)
stemmed_words = [stem(word) for word in words]

print("Original words:", words)
print("Stemmed words:", stemmed_words)


from nltk.stem import LancasterStemmer

stemmer = LancasterStemmer()

words_to_stem = ['running', 'jumped', 'happily', 'quickly', 'foxes']
stemmed_words = [stemmer.stem(word) for word in words_to_stem]
print("\n\nOriginal words:", words_to_stem)
print("Stemmed words:", stemmed_words)

words_to_stem = word_tokenize("The cats are running swiftly.")
stemmed_words = [stemmer.stem(word) for word in words_to_stem]
print("\n\nOriginal words:", words_to_stem)
print("Stemmed words:", stemmed_words)
