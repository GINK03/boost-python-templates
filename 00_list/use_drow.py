from drow import drow

# create drow instance
d = drow('dog')

# access the word and print it
print d.word

# print the chars
for char in d.get_chars():
    print char

# check out if it works for a list
# it will join the words and save them in word variable
d = drow(['cat', 'dog', 'canary'])

# print me joined
print d.word