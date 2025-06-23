touch bpe.dot
echo "$1"> bpe.dot
touch graph.html
echo "$(dot -Tsvg bpe.dot -Nshape=rect)" > graph.html