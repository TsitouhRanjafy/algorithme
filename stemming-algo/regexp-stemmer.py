# Example:
    # 'running' → 'runn'
    # Custom rule: r'ing$' removes the suffix ing.

# Advantages:
    # Highly customizable using regular expressions.
    # Suitable for domain-specific tasks.

# Limitations:
    # Requires manual rule definition.
    # Can be computationally expensive for large datasets.

from nltk.stem import RegexpStemmer

custom_rule = r'ing$'
regexp_stemmer = RegexpStemmer(custom_rule)

word = 'running'
stemmed_word = regexp_stemmer.stem(word)

print(f'Original Word: {word}')
print(f'Stemmed Word: {stemmed_word}')