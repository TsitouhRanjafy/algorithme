# Example:
    # 'running' → 'run'
    # 'quickly' → 'quick'

# Advantages:
    # More efficient than Porter Stemmer.
    # Supports multiple languages.

# Limitations:
    # More aggressive which might lead to over-stemming.

import nltk
from nltk.stem.snowball import SnowballStemmer

def stemming_demo():
    stemmer = SnowballStemmer('english')

    test_words = [
        'running', 'runs', 'ran',           # Verb variations
        'caring', 'cared', 'careful',       # Different suffixes  
        'university', 'universities',       # Plural forms
        'fairly', 'unfairly',               # Adverbs with prefixes
        'singing', 'singer', 'song'         # Related but different stems
    ]

    for word in test_words:
        stem = stemmer.stem(word)
        print(f"{word:12} → {stem}")

stemming_demo()


