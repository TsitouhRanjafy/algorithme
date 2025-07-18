# 🔡 Byte Pair Encoding (BPE)

Byte Pair Encoding (BPE) est un algorithme de compression simple mais puissant, utilisé ici pour transformer un texte brut en une séquence de **tokens numériques**.

> ⚠️ Cet algorithme **ne vise pas** à compresser les textes de façon optimale (comme ZIP), mais plutôt à segmenter le texte en unités (tokens) de manière à faciliter le traitement, notamment dans le contexte du traitement automatique des langues (NLP).

## 🧠 Principe de fonctionnement

1. On commence par considérer chaque caractère unique du texte comme un token de base.
2. À chaque itération, la **paire de tokens adjacents la plus fréquente** est fusionnée pour créer un nouveau token.
3. Ce processus continue jusqu’à un certain critère d’arrêt (nombre de tokens, taille finale, etc.).

Chaque fusion est enregistrée dans un **vocabulaire de tokens**, qui permet de reconstruire le texte original ou de comprendre sa structure.

👉 Pour plus de détails, consulte la [page Wikipédia sur BPE](https://fr.wikipedia.org/wiki/Byte_pair_encoding).

---

## 📥 Exemple

Debuter notre nouveau token à 126 et on s'increment à quand fois.

### Entrée

Text original: `aaabdaaabac`    
Taille: `0011`    

### Sortie

Texte final : `[128]d[128]ac`     
Taille : `0005`

### Vocabulaire (mode graph)

![graph_bpe](https://github.com/user-attachments/assets/13b6d032-a412-4b20-8323-cc2a21a4ff76)


### Processus

```shell
Original text:aaabdaaabac
Original size: 0011

        ! Compressing...

        ✓ Compression is done

 Final text:[128]d[128]ac
 Compressed size: 0005

 Token vocabulary: {
                     126 => (97,97),
                     127 => (126,97),
                     128 => (127,98),
                     129 => (129,0),
                    }


 DOT generated: 
 digraph{ 126 -> {97,97} 127 -> {126,97} 128 -> {127,98} }

```


### Made with ❤️ By **Tsitohaina** 😊
