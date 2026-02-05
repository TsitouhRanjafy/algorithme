# Example:
    # 'agreed' → 'agree'
    # Rule: If the word has a suffix EED (with at least one vowel and consonant) remove the suffix and change it to EE.

# Advantages:
    # Very fast and efficient.
    # Commonly used for tasks like information retrieval and text mining.

# Limitations:
    # Outputs may not always be real words.
    # Limited to English words.

from porter2stemmer import Porter2Stemmer

porter_stemmer = Porter2Stemmer()

words = ["running", "jumps", "happily", "running", "happily", "playing","quickly","saved"]

stemmed_words = [porter_stemmer.stem(word) for word in words]

print("Original words:", words)
print("Stemmed words:", stemmed_words)