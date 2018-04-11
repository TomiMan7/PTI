import string
filename ="szamlalo.cpp"
lines=0
words=0
chars=0
num=0
let=0
spec=0
betuk=string.ascii_letters
szamok=string.digits
kulonleges=string.punctuation

with open(filename, 'r') as file:
	for line in file:
		wordsList = line.split()
		lines += 1
		words += len(wordsList)
		for c in line:
			if szamok.find(c) != -1:
				num += 1
			if betuk.find(c) != -1:
				let += 1
			if kulonleges.find(c) != -1:
				spec += 1

chars = num + let + spec
print "Sorok: %i\nSzavak %i\nSzamok: %i\nBetuk: %i\nSpecialis karakterek %i\nKarakterek %i\n" % (lines, words, num, let, spec, chars)
