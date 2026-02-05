from nltk.stem import PorterStemmer, LancasterStemmer
from nltk.stem.snowball import SnowballStemmer

def compare_stemmers():
   
    # Initialize all three stemmers
    porter = PorterStemmer()
    lancaster = LancasterStemmer()  
    snowball = SnowballStemmer('english')
    
    # Test words that show differences between algorithms
    comparison_words = [
        'fairly', 'sportingly', 'generously',
        'organization', 'civilization', 'specialization',
        'running', 'swimming', 'beginning',
        'studies', 'flies', 'cities'
    ]
    
    print("Stemmer Comparison:")
    print("=" * 50)
    print(f"{'Word':<15} {'Porter':<12} {'Lancaster':<12} {'Snowball':<12}")
    print("-" * 50)
    
    for word in comparison_words:
        porter_stem = porter.stem(word)
        lancaster_stem = lancaster.stem(word)
        snowball_stem = snowball.stem(word)
        
        print(f"{word:<15} {porter_stem:<12} {lancaster_stem:<12} {snowball_stem:<12}")

compare_stemmers()